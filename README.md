数据结构
================
主要给出数据结构中常用的数据类型和算法的Ｃ＋＋实现

什么是数据结构？
------
究竟什么是数据结构，目前还没有标准的定义。在这里我们称组成数据的基本单元为“数据元素”。一个“数据结构”是由数据元素依据某种逻辑联系组织起来的。

数据结构间的逻辑关系称为数据的“逻辑结构”。数据结构一般还包括作用在数据结构上的算法。

数据的逻辑结构是面向应用问题的，是从用户角度看到的数据的结构。

数据必须在计算机内存储，数据的存储结构是数据在计算机内的组织方式。

1.4 C++程序设计
=======

1.4.1  传值参数  和  引用参数
---------------
###   函数形参的传递有两种
####   一是传值参数： 
      形参得到了实在参数的一个副本，但是在调用中就不能再对实在参数进行操作了。
####  二是引用参数：
      当一个实参和一个引用参数结合时，被传递的实际是实在参数的地址。函数体中对引用参数的修改会导致实参的修改。
   （注意引用&，相当于起个别名，实际指向的仍然是原来的数据）
  还有一种是常量引用参数，指明函数体中不能对引用参数做修改，否则编译出错。使用const来指明。
  
  
1.4.2 动态存储分配
===================
 
###  malloc 和 free
###  new    和 delete
    int *y ;
    y = new int;
    *y = 10;
    
###   等价于 
   int *y = new int(10);
   
###   delete   
   delete y;
   int *a = new int[10];
   delete []a;

1.4.3 C++ 类
==================
###   建立一个类的对象类似于定义C语言的变量，有如下两种：
      1. 直接定义类的实例
         ClassName  tempClass;
      2. 使用new
         ClassName * tempClass = new ClassName;
         delete tempClass;   // 注意要释放new申请的变量
###   1.4.3.1 操作符重载
      operate+
      输入输出流的重载等。
      
###   1.4.3.2 友元函数
      一个类的private成员仅仅对该类的成员函数是可见的。有些应用中要求对将这些private成员的访问权限授予其他的类或者函数，这时候可将这些类或者函数定义成友元的形式（friend）。
      class Y;
      class X{
         friend Y;
         ...
      }
      class Y{
      
        ...
      }
      类Y中所有函数都是X的友元，因此他们都能存取X的私有成员。
      
###  C++ 还有继承、多态、虚函数、模板等概念这里就不在一一介绍。
      
      
本书中的实现，一个数据结构被看成一个类属抽象数据结构，用一个模板类描述。


