# C++问题

##基础知识
* 结构体和共同体的区别   sizeof时内存对齐原则
* static 和const分别怎么用，类里面static和const可以同时修饰成员函数吗静态成员函数和成员变量
* explicitvolatileextern关键字  extern “C”的作用   宏定义和const的区别
* C++程序内存布局  
* new和mallocdelete和free的区别  delete和delete[]       内存池
* 指针和引用的区别
* Const如何实现的
* 什么是多态，多态有什么用途，多态（动态和静态—虚函数和函数重载） 虚函数纯虚函数什么函数可以或不可以定义为虚函数虚函数表，多重继承/菱形继承 内存分配 虚拟继承   重载覆盖和隐藏   编译时多态和运行时多态
*  如何实现动态绑定   友元函数
* vector中size()和capacity()的区别  
capacity的意思是容量，此方法返回的是该vector对象在重新分配内存之前最多能容纳多少个元素。
size的意思是大小，此方法是返回该vector对象当前有多少个元素。
* mapset vector的原理  stl有哪些容器 对比vector和set
* 四种类型转换  
C++引入了4种类型转化操作符（cast operator）：static_cast，const_cast，dynamic_cast和reinterpret_cast  
static_cast：static_cast基本上拥有与C旧式转型相同的威力和意义，以及相同的限制。但是，该类型转换操作符不能移除常量性，因为有一个专门的操作符用来移除常量性。  
const_cast：用来改变表达式中的常量性（constness）或者易变形（volatileness），只能用于此功能。  
dynamic_cast：将指向基类basic class object的pointer或者reference转型为指向派生类derived（或这sibling base）class object的pointer或者reference中，并且可以获知是否转型成功：如果转型失败，当转型对象是指针的时候会返回一个null指针；当转型对象是reference会抛出一个异常exception。dynamic_cast无法应用在缺乏虚函数的类型上，也不能改变类型的常量性。此外，dynamic_cast还有一个用途就是找出被对象占用的内存的起始点。  
reinterpret_cast：这个操作符的转换结果几乎总是和编译器平台相关，所以不具有移植性。reinterpret_cast的最常用用途是转换“函数指针”类型。
* 模板特化，为什么特化     特化和偏特化  模板多态     
* 内联函数优点与宏定义的区别
* C和C++区别（OOL 继承封装多态）
* 继承机制中，对象之间如何转换引用和指针如何转换
* C++内存溢出，内存泄漏   如何防止
* 智能指针（auto_ptr,unique_ptr,shared_ptr,week_ptr），如何实现的
* 类的访问控制，public，protected，private，继承后属性
* 容器插入和删除元素时迭代器的行为
* C++11新标准记几个


