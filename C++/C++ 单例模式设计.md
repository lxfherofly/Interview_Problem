# C++ Singleton (单例) 模式最优实现
众多设计模式中，单例模式比较常见的一种，面试和工作中也会经常接触到。本文以一个C++开发者的角度来探讨单例模式几种典型实现。设计模式经典GoF定义的单例模式需要满足以下两个条件：

* 保证一个类只创建一个实例。

* 提供对该实例的全局访问点。

如果系统有类似的实体（有且只有一个，且需要全局访问），那么就可以将其实现为一个单例。实际工作中常见的应用举例

* 日志类，一个应用往往只对应一个日志实例。

* 配置类，应用的配置集中管理，并提供全局访问。

* 管理器，比如windows系统的任务管理器就是一个例子，总是只有一个管理器的实例。
* 共享资源类，加载资源需要较长时间，使用单例可以避免重复加载资源，并被多个地方共享访问。

**Lazy Singleton**

首先看GoF在描述单例模式时提出的一种实现，教科书式的例子，对C++有些经验应该对该实现都有些印象
``` c++
//头文件中
class Singleton  
{
    public:
        static Singleton& Instance()
        {
            if (instance_ == NULL)
            {
                instance_ = new Singleton;
            }
            return *instance_;
         }
    private:
        Singleton()；
        ~Singleton()；
        Singleton(const Singleton&);
        Singleton& operator=(const Singleton&);
    private:
        static Singleton* instance_;
};
//实现文件中
Singleton* Singleton::instance_ = 0;  
``` 
实现中构造函数被声明为私有方法，这样从根本上杜绝外部使用构造函数生成新的实例，同时禁用拷贝函数与赋值操作符（声明为私有但是不提供实现）避免通过拷贝函数或赋值操作生成新实例。

提供静态方法Instance()作为实例全局访问点，该方法中先判断有没有现成的实例，如果有直接返回，如果没有则生成新实例并把实例的指针保存到私有的静态属性中。

注意，这里Instance()返回的实例的引用而不是指针，如果返回的是指针可能会有被外部调用者delete掉的隐患，所以这里返回引用会更加保险一些。并且直到Instance()被访问，才会生成实例，这种特性被称为延迟初始化（Lazy initialization），这在一些初始化时消耗较大的情况有很大优势。

Lazy Singleton不是线程安全的，比如现在有线程A和线程B，都通过`instance_ == NULL`的判断，那么线程A和B都会创建新实例。单例模式保证生成唯一实例的规则被打破了。

**Eager Singleton**

这种实现在程序开始(静态属性instance初始化)的时就完成了实例的创建。这正好和上述的Lazy Singleton相反。
``` c++
//头文件中
class Singleton  
{
    public:
        static Singleton& Instance()
        {
            return instance;
        }
    private:
        Singleton();
        ~Singleton();
        Singleton(const Singleton&);
        Singleton& operator=(const Singleton&);
    private:
        static Singleton instance;
}
//实现文件中
Singleton Singleton::instance;  
```

由于在main函数之前初始化，所以没有线程安全的问题，但是潜在问题在于no-local static对象（函数外的static对象）在不同编译单元（可理解为cpp文件和其包含的头文件）中的初始化顺序是未定义的。如果在初始化完成之前调用 Instance()方法会返回一个未定义的实例。

**Meyers Singleton**

Scott Meyers在《Effective C++》（Item 04）中的提出另一种更优雅的单例模式实现，使用local static对象（函数内的static对象）。当第一次访问Instance()方法时才创建实例。
``` c++
class Singleton  
{
    public:
        static Singleton& Instance()
    {
        static Singleton instance；
        return instance；
    }
    private:
        Singleton()；
        ~Singleton()；
        Singleton(const Singleton&);
        Singleton& operator=(const Singleton&);
};
``` 
C++0x之后是该实现线程安全的，有兴趣可以读相关的标准草案（section 6.7）编译器支持程度不一定,但是G++4.0及以上是支持的。

**双检测锁模式（Double-Checked Locking Pattern）**

Lazy Singleton的一种线程安全改造是在Instance()中每次判断是否为NULL前加锁，但是加锁是很慢的。 
而实际上只有第一次实例创建的时候才需要加锁。双检测锁模式被提出来，改造之后大致是这样
``` c++
static Singleton& Instance()  
{
    if (instance_ == NULL) 
    {
        Lock lock; //基于作用域的加锁，超出作用域，自动调用析构函数解锁
        if (instance_ == NULL)
        {
              instance_ = new Singleton;
        }
    }
    return *instance_;
}
```
既然只需要在第一次初始化的时候加锁，那么在这之前判断一下实例有没有被创建就可以了，所以多在加锁之前多加一层判断，需要判断两次所有叫Double-Checked。理论上问题解决了，但是在实践中有很多坑，如指令重排、多核处理器等问题让DCLP实现起来比较复杂比如需要使用内存屏障，详细的分析可以阅读这篇论文。


