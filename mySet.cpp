#include<iostream>
#include<assert.h>
#include"RBTree.h"
using namespace std;


template<class K>
class Set
{
public:
    Set()
        :_s(NULL)
    {}

    struct KeyOfValue//在类外需要在定义模版参数
    {
        K operator()(const K& key)
        {
            return key;
        }
    };

    typedef typename RBTree<K, K, KeyOfValue>::Iterator Iterator;

    Iterator Begin()
    {
        return _s.Begin();
    }

    Iterator End()
    {
        return _s.End();
    }

    Iterator RBegin()
    {
        return _s.RBegin();
    }

    Iterator REnd()
    {
        return _s.REnd();
    }

    Iterator Find()
    {
        return _s.Find();
    }

    pair<Iterator, bool> Insert(const K& key)
    {
        return _s.Insert(key);
    }
private:
    RBTree<K, K, KeyOfValue> _s;
};

int main()
{
    Set<int> s;
    s.Insert(12);
    s.Insert(31);
    s.Insert(45);
    Set<int>::Iterator it = s.Begin();
    while (it != s.End())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;
    return 0;
}