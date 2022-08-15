# mySTL
基于C++实现的简易STL

# vector容器实现
使用动态数组实现了构造函数、析构函数、push_back()、length()、capacit()等基本函数，还实现了[]符号的重载访问，可以支持下标为负数的情况

![image](https://user-images.githubusercontent.com/61955866/175799499-611c5a2d-c5b8-4f3d-b2e4-1930360d206d.png)

# stack容器实现
使用数组实现了top()、push()、pop()、isEmpty()等基本函数

![image](https://user-images.githubusercontent.com/61955866/175799547-28176c44-cac5-47be-8321-57a110928fcc.png)

# queue容器实现
使用数组实现了pop()、push()、first()、last()、isEmpty()等基本函数

![image](https://user-images.githubusercontent.com/61955866/175799583-7f8748fb-dee7-4e81-b23f-9cf534005999.png)

# list容器实现
使用结构体实现了默认构造函数、拷贝构造函数、插入、删除、遍历、连接、isEmpty()等基本函数

![image](https://user-images.githubusercontent.com/61955866/175799617-50bc81e6-7ba3-4154-b8d6-71342f745d28.png)

# set容易实现
使用红黑树实现了查找，插入以及迭代指针begin()和end()，rbegin()和rend()函数
![image](https://user-images.githubusercontent.com/61955866/184599731-494fc648-56e7-4907-a80b-0a9f911bf414.png)

# map容器实现
使用红黑树实现了插入以及迭代指针begin()和end()和下边访问运算符的重载函数，需要注意的是map和set使用同一棵红黑树，set传入一个变量K，而map传入一个变量对pairs<K,V>
![image](https://user-images.githubusercontent.com/61955866/184599784-29deb76a-16d0-4963-8639-651437ce460c.png)

# 动态重载实现1
给予普通数据结构，使用动态数组模板类实现了默认构造函数、拷贝构造函数、析构函数、[]下标访问重载、=赋值重载等基本函数

![image](https://user-images.githubusercontent.com/61955866/175799651-24be2ab7-63f6-498f-bbfd-3089b2ad10be.png)

# 动态重载实现2
基于定义的结构体对象，使用动态数组模板类实现了默认构造函数、拷贝构造函数、析构函数、[]下标访问重载、=赋值重载等基本函数，并实现了resize()函数，实现了动态数组的扩容

![image](https://user-images.githubusercontent.com/61955866/175799752-6147919b-2a55-46b1-8712-c23c1ddebf1c.png)

以上均为原创代码，请谨慎使用，若有错误，可以指出，一起进步！
