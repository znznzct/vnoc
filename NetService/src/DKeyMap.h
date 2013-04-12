#ifndef _MT_DOUBLE_KEY_MAP_H_
#define _MT_DOUBLE_KEY_MAP_H_

#include <map>

template<class TKey1, class TKey2, class T>
class DKeyMap
{
	typedef typename std::map<TKey2, T>                  TKeyMap;
	typedef typename std::map<TKey1, std::map<TKey2, T>> TDoubleKeyMap;
	typedef typename std::vector<TKey2>                  TKeyList;

public:
	void insert(const TKey1& key1, const TKey2& key2, const T& value);
	bool exist(const TKey1& key1, const TKey2& key2);
	bool find(const TKey1& key1, const TKey2& key2, T& value);
	int  size();
	int  sizeDKey();
	int  sizeKeyMap(TKey1 key1);
	bool erase(const TKey1& key1);
	bool erase(const TKey1& key1, const TKey2& key2);
	void clear();

private:
	std::map<TKey1, std::map<TKey2, T>> _dKeyMap;
};

template<class TKey1, class TKey2, class T>
void DKeyMap<TKey1,TKey2,T>::insert(const TKey1& key1, const TKey2& key2, const T& value)
{
	typename TDoubleKeyMap::iterator iter = _dKeyMap.find(key1);
	if (iter != _dKeyMap.end())
	{
		(iter->second).insert(std::make_pair(key2, value));
	}
	else
	{
		std::map<TKey2, T> subMap;
		subMap[key2] = value;
		_dKeyMap[key1] = subMap;
	}
}

template<class TKey1, class TKey2, class T>
bool DKeyMap<TKey1,TKey2,T>::exist(const TKey1& key1, const TKey2& key2)
{
	typename TDoubleKeyMap::iterator dkeyIter = _dKeyMap.find(key1);
	if (dkeyIter != _dKeyMap.end())
	{
		typename TKeyMap::iterator keyIter = (dkeyIter->second).find(key2);
		if (keyIter != (dkeyIter->second).end())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;
}

template<class TKey1, class TKey2, class T>
bool DKeyMap<TKey1,TKey2,T>::find(const TKey1& key1, const TKey2& key2, T& value)
{
	typename TDoubleKeyMap::iterator dkeyIter = _dKeyMap.find(key1);
	if (dkeyIter != _dKeyMap.end())
	{
		typename TKeyMap::iterator keyIter = (dkeyIter->second).find(key2);
		if (keyIter != (dkeyIter->second).end())
		{
			value = keyIter->second;
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;
}

template<class TKey1, class TKey2, class T>
int DKeyMap<TKey1,TKey2,T>::sizeDKey()
{
	return _dKeyMap.size();
}

template<class TKey1, class TKey2, class T>
int DKeyMap<TKey1,TKey2,T>::sizeKeyMap(TKey1 key1)
{
	typename TDoubleKeyMap::iterator iter = _dKeyMap.find(key1);
	if (iter != _dKeyMap.end())
	{
		return (iter->second).size();
	}
	return 0;
}

template<class TKey1, class TKey2, class T>
int DKeyMap<TKey1,TKey2,T>::size()
{
	int size = 0;
	for (typename TDoubleKeyMap::iterator iter = _dKeyMap.begin(); iter != _dKeyMap.end(); iter++)
	{
		size += (iter->second).size();
	}
	return size;
}

template<class TKey1, class TKey2, class T>
bool DKeyMap<TKey1,TKey2,T>::erase(const TKey1& key1)
{
	typename TDoubleKeyMap::iterator iter = _dKeyMap.find(key1);
	if (iter != _dKeyMap.end())
	{
		_dKeyMap.erase(iter);
		return true;
	}
	else
	{
		return false;
	}
}

template<class TKey1, class TKey2, class T>
bool DKeyMap<TKey1,TKey2,T>::erase(const TKey1& key1, const TKey2& key2)
{
	typename TDoubleKeyMap::iterator iter = _dKeyMap.find(key1);
	if (iter != _dKeyMap.end())
	{
		typename TKeyMap::iterator iter1 = (iter->second).find(key2);
		if (iter1 != (iter->second).end())
		{
			(iter->second).erase(iter1);
			return true;
		}
	}
	return false;
}

template<class TKey1, class TKey2, class T>
void DKeyMap<TKey1,TKey2,T>::clear()
{
	for (typename TDoubleKeyMap::iterator iter = _dKeyMap.begin(); iter != _dKeyMap.end(); iter ++)
	{
		(iter->second).clear();
	}
	_dKeyMap.clear();
}

#endif
