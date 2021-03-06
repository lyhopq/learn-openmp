## Why
进入多核时代后，必须使用多线程编写程序才能让各个CPU核得到利用。在单核时代，通常使用操作系统提供的API来创建线程，然而，在多核系统中，情况发生了很大的变化， 如果仍然使用操作系统API来创建线程会遇到一些问题。具体来说，有以下三个问题：

1）CPU核数扩展性问题

多核编程需要考虑程序性能随CPU核数的扩展性，即硬件升级到更多核后，能够不修改程序就让程序性能增长，这要求程序中创建的线程数量需要随CPU核数变化，不能创建固定数量的线程，否则在CPU核数超过线程数量上的机器上运行，将无法完全利用机器性能。虽然通过一定方法可以使用操作系统API创建可变化数量的线程，但是比较麻烦，不如OpenMP方便。

2）方便性问题

在多核编程时，要求计算均摊到各个CPU核上去，所有的程序都需要并行化执行，对计算的负载均衡有很高要求。这就要求在同一个函数内或同一个循环中，可能也需要将计算分摊到各个CPU核上，需要创建多个线程。操作系统API创建线程时，需要线程入口函数，很难满足这个需求，除非将一个函数内的代码手工拆成多个线程入口函数，这将大大增加程序员的工作量。使用OpenMP创建线程则不需要入口函数，非常方便，可以将同一函数内的代码分解成多个线程执行，也可以将一个for循环分解成多个线程执行。

3）可移植性问题

目前各个主流操作系统的线程API互不兼容，缺乏事实上的统一规范，要满足可移植性得自己写一些代码，将各种不同操作系统的api封装成一套统一的接口。OpenMP是标准规范，所有支持它的编译器都是执行同一套标准，不存在可移植性问题。
