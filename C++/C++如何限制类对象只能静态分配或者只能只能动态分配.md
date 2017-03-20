# C++如何限制类对象只能静态分配或者只能只能动态分配



动态分配就是用运算符new来创建一个类的对象，在堆上分配内存。

静态分配就是A a;这样来由编译器来创建一个对象，在栈 上分配内存。

### （1）动态分配（在堆上分配内存）
将类的构造函数和析构函数设为protected属性，这样类对象不能够访问，但是派生类能够访问，能够正常的继承。同时创建另外两个create和destory函数类创建对象。（将create设为static原因是：创建对象的时候是A *p = A::create(); 只有静态成员函数才能够通过类名来访问。）

```
class A
{
protected:
    A(){}
    ~A(){}
public:
    static A* create()
    {
        return new A();
    }
    void destory()
    {
        delete this;
    }
};
```

### （2）静态分配（在栈上）

把new、delete运算符重载为private属性就可以了。

```
class A
{
private:
    void* operator new(size_t t){}     // 注意函数的第一个参数和返回值都是固定的
    void operator delete(void* ptr){} // 重载了new就需要重载delete
public:
    A(){}
    ~A(){}
};
```
