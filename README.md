# mySTL
基于C++实现的简易STL，是对自己代码的一个整理和总结

# vector容器实现
使用动态数组实现了构造函数、析构函数、push_back()、length()、capacit()等基本函数，还实现了[]符号的重载访问

DynamicVector(int);

~DynamicVector();

inline void push_back(const T&);

T& operator[] (int Vindex);

unsigned length() const;

unsigned capacity() const;

int firstIndex() const;

