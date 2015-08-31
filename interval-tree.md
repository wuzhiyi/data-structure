##Interval Tree
区间树是在红黑树基础上进行扩展得到的支持以区间为元素的动态集合的操作，其中每个节点的关键值是区间的__左端点__。通过建立这种特定的结构，可是使区间的元素的查找和插入都可以在 O(lgn) 的时间内完成。</br>
相比于基础的数据结构，增加了一个 max[x]，即以 x 为根的子树中所有区间的端点的最大值。</br>

###Operations

* Left-Rotate
* Right-Rotate
* Insert-Fixup
* Insert
* Delete-Fixup
* Find Tree-Minimum
* Find Successor
* Search
* Delete
* Interval-Search

###Source Code
* [cpp](https://github.com/wuzhiyi/data-structure/blob/master/interval-tree.cpp)

####e.g
![img](https://cloud.githubusercontent.com/assets/9131176/9573425/ed2d9c6e-4fee-11e5-9118-9d29c0001a1b.png)</br>
![img](https://cloud.githubusercontent.com/assets/9131176/8700579/33808868-2b3f-11e5-8277-0dad83c6c5ff.png)</br>

