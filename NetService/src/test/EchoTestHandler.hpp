#ifndef ECHOTESTHANDLER_H_
#define ECHOTESTHANDLER_H_
#include "../AsioTcpConnection.hpp"
#include "../SocketHandler.hpp"
#include <iostream>
template <typename ConnectionT>
class EchoTestHandler: public SocketHandler
{
public:
	EchoTestHandler(ConnectionT *connection):connection_(connection){}
	virtual void start()
	{
        connection_->read_some(data_, sizeof(data_)-1, 
        std::bind(&EchoTestHandler::ReadsomeHandler, this,
          std::placeholders::_1,
          std::placeholders::_2));
	}
    virtual void ReadsomeHandler(const asio::error_code& error, size_t bytes_transferred)
    {
        if (!error)
		{
            data_[bytes_transferred]='\0';
            std::cout<<data_;
            connection_->send(data_, bytes_transferred, 
            std::bind(&EchoTestHandler::HandleWrite, this,
              std::placeholders::_1));
        }else
        {
            delete this;
        }
    }
	virtual void HandleWrite(const asio::error_code& error)
	{
		if (!error)
		{
			connection_->read_some(data_, sizeof(data_)-1, 
            std::bind(&EchoTestHandler::ReadsomeHandler, this,
              std::placeholders::_1,
              std::placeholders::_2));
		}else
		{
			delete this;
		}
		
	}
private:
    ConnectionT *connection_;
    char data_[512];
};

class EchoTestHandlerFactory: public SocketHandlerFactory
{
public:
	virtual SocketHandler* CreateHandler(AsioTcpConnection *connection)
	{
		return new EchoTestHandler<AsioTcpConnection>(connection);
	}
};

#endif /* ECHOTESTHANDLER_H_ */
