##Interval Tree
区间树是在红黑树基础上进行扩展得到的支持以区间为元素的动态集合的操作，其中每个节点的关键值是区间的__左端点__。通过建立这种特定的结构，可是使区间的元素的查找和插入都可以在 O(lgn) 的时间内完成。</br>
相比于基础的数据结构，增加了一个 max[x]，即以 x 为根的子树中所有区间的端点的最大值。</br>

###Centered Interval Tree
Queries require O(log _n_ + _m_) time, with _n_ being the total number of intervals and _m_ being the number of reported results. Construction requires O(_n_ log _n_) time, and storage requires O(_n_) space.</br>

###Construction
Given a set of _n_ intervals on the number line, we want to construct a data structure so that we can efficiently retrieve all invervals overlapping another interval or point.</br>
We start by taking the entire range of all the intervals and dividing it in half at _x_center_ (in practice, _x_center_ should be picked to keep the tree relatively balanced). This gives three sets of intervals, those completely to the left of _x_center_ which we'll call _S_left_, those completely to the right of _x_center_ which we'll call _S_right_, and those overlapping _x_center_ which we'll call _S_center_.</br>
The intervals in _S_left_ and _S_right_ are recursively divided in the same manner until there are no intervals left.</br>
The intervals in _S_center_ that overlap the center point are stored in a separate data structure linked to the node in the interval tree. This data structure consists of two lists, one containing all the intervals sorted by their beginning points, and another containing all thte intervals sorted by their ending points.</br>
The result is a ternary tree with each node storing:

* A center point
* A pointer to another node containing all intervals completely to the left of the center point
* A pointer to another node containing all intervals completely to the right of the center point
* All intervals overlapping the center point sorted by their beginning point
* All intervals overlapping the center point sorted by their ending point

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
<div align="center">![img](https://cloud.githubusercontent.com/assets/9131176/9573425/ed2d9c6e-4fee-11e5-9118-9d29c0001a1b.png)</br>
<div align="center">![img](https://cloud.githubusercontent.com/assets/9131176/8700579/33808868-2b3f-11e5-8277-0dad83c6c5ff.png)</br>

