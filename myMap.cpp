#pragma once
#include "RBTree.h"

template<class K, class V>
struct MapKeyOfValue
{
    K operator()(const V& kv)
    {
        return kv.first;
    }
};

template<class K, class V, class KeyOfValue = MapKeyOfValue<K, pair<K, V>>>
class Map
{
public:

    typedef typename RBTree<K, pair<K, V>, KeyOfValue>::Iterator Iterator;

    Iterator Begin()
    {
        return t.Begin();
    }

    Iterator End()
    {
        return t.End();
    }

    bool Insert(const pair<K, V>& value)
    {
        return t.Insert(value);
    }

    V& operator[](const K& key)
    {
        // (*((this->insert(make_pair(k,mapped_type()))).first)).second
        pair<Iterator, bool> ret = t.Insert(make_pair(key, V()));
        return ret.first->second;
    }

protected:
    RBTree<K, pair<K, V>, KeyOfValue> t;
};


int main()
{
    Map<int,char> s;
    s.Insert({1,'1'});
    s.Insert({2,'2'});
    s.Insert({3,'3'});
    Map<int,char>::Iterator it = s.Begin();
    while (it != s.End())
    {
        cout << it->first << it->second;
        ++it;
    }
    cout << endl;
    return 0;
}