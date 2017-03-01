# C++问题

##基础知识
* 结构体和共同体的区别   sizeof时内存对齐原则

* static 和const分别怎么用，类里面static和const可以同时修饰成员函数吗静态成员函数和成员变量

* explicitvolatileextern关键字  extern “C”的作用   宏定义和const的区别

* C++程序内存布局    
**见C/C++内存管理详解.md**  

* new和malloc delete和free的区别  delete和delete[]  内存池
1.`malloc`和`free`是C的标准库函数，而`new`和`delete`为C++的操作符    
2.`malloc`和`free`只是动态的开辟一块内存,并没有初始化, 而对一个对象来说, `new`和`delete`会调用构造和析构函数  
3.`delete`与`new`对应, `delete[]`与`new[]`相对应   
关于**内存池**    
通常我们习惯直接使用new、malloc等API申请分配内存，这样做的缺点在于：由于所申请内存块的大小不定，   
当频繁使用时会造成大量的内存碎片并进而降低性能。C/C++的内存分配(通过malloc或new)可能需要花费很多时。更糟糕的是，随着时间的流逝，内存(memory)将形成碎片，所以一个应用程序的运行会越来越慢当它运行了很长时间和/或执行了很多的内存分配(释放)操作的时候。特别是，你经常申请很小的一块内存，堆(heap)会变成碎片的，这就是为什么我们经常在运行自己的C/C++程序时一开始还好好的，可是越到后面速度越慢，最后甚至直接罢工了。   
    而对于以上，一个可行的的解决方案就是设计一个自己的内存分配策略，也即设计一个你自己的内存池。内存池(Memory Pool)是一种内存分配方式。 内存池则是在真正使用内存之前，先申请分配一定数量的、大小相等(一般情况下)的内存块留作备用。当有新的内存需求时，就从内存池中分出一部分内存块，若内存块不够再继续申请新的内存。这样做的一个显著优点是尽量避免了内存碎片，使得内存分配效率得到提升。在启动的时候，一个”内存池”(Memory Pool)分配一块很大的内存，并将会将这个大块(block)分成较小的块(smaller chunks)。每次你从内存池申请内存空间时，它会从先前已经分配的块(chunks)中得到，而不是从操作系统。   
最大的优势在于：
1.非常少(几没有) 堆碎片  
2.比通常的内存申请/释放(比如通过malloc, new等)的方式快   
3.检查任何一个指针是否在内存池里   
4.写一个”堆转储(Heap-Dump)”到你的硬盘(对事后的调试非常有用)   
5.某种”内存泄漏检测(memory-leak detection)”：当你没有释放所有以前分配的内存时，内存池(Memory Pool)会抛出一个断言(assertion).  

* 指针和引用的区别

* Const如何实现的

* 什么是多态，多态有什么用途，多态（动态和静态—虚函数和函数重载） 虚函数纯虚函数什么函数可以或不可以定义为虚函数虚函数表，多重继承/菱形继承 内存分配 虚拟继承   重载覆盖和隐藏   编译时多态和运行时多态

*  如何实现动态绑定   友元函数

* vector中size()和capacity()的区别  
`capacity`的意思是容量，此方法返回的是该vector对象在重新分配内存之前最多能容纳多少个元素。
`size`的意思是大小，此方法是返回该vector对象当前有多少个元素。

* mapset vector的原理  stl有哪些容器 对比vector和set

* 四种类型转换   
C++引入了4种类型转化操作符`（cast operator）：static_cast，const_cast，dynamic_cast和reinterpret_cast`  
`static_cast`：static_cast基本上拥有与C旧式转型相同的威力和意义，以及相同的限制。但是，该类型转换操作符不能移除常量性，因为有一个专门的操作符用来移除常量性。  
`const_cast`：用来改变表达式中的常量性（`constness`）或者易变形（`volatileness`），只能用于此功能。  
`dynamic_cast`：将指向基类`basic class object`的pointer或者reference转型为指向派生类derived（或这sibling base）`class object`的pointer或者reference中，并且可以获知是否转型成功：如果转型失败，当转型对象是指针的时候会返回一个null指针；当转型对象是reference会抛出一个异常exception。`dynamic_cast`无法应用在缺乏虚函数的类型上，也不能改变类型的常量性。此外，`dynamic_cast`还有一个用途就是找出被对象占用的内存的起始点。  
`reinterpret_cast`：这个操作符的转换结果几乎总是和编译器平台相关，所以不具有移植性。`reinterpret_cast`的最常用用途是转换“函数指针”类型。

* 模板特化，为什么特化  特化和偏特化  模板多态     

* 内联函数优点与宏定义的区别

* C和C++区别（OOL 继承封装多态）

* 继承机制中，对象之间如何转换引用和指针如何转换

* C++内存溢出，内存泄漏   如何防止

* 智能指针（auto_ptr,unique_ptr,shared_ptr,week_ptr），如何实现的

* 类的访问控制，public，protected，private，继承后属性

* 容器插入和删除元素时迭代器的行为

* C++11新标准记几个  
http://coolshell.cn/articles/5265.html
