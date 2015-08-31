##Radix Tree
基数树（radix tree）是将指针与 long 整数键值相关联的机制，它存储有效率，并且可快速查询，用于指针与整数值的映射（如：IDR 机制）、内存管理等。</br>
IDR（ID Radix）机制是将对象的身分鉴别号整数值 ID 与对象指针建立关联表，完成从 ID 与指针之间的相互转换。</br>
IDR 机制使用 radix 树状结构作为 id 进行索引获取指针的稀疏数组，通过使用位图可以快速分配新的 ID，IDR 机制避免了使用固定尺寸的数组存放指针。IDR 机制的 API 函数在 lib/idr.c 中实现。</br>
Linux radix tree 最广泛的用途是用于内存管理，结构 address_space 通过 radix tree 跟踪绑定到地址映射上的核心页，该 radix tree 允许内存管理代码快速查找标识为 dirty 或 writeback 的页。Linux radix tree 的 API 函数在 lib/radix-tree.c 中实现。</br>
###Operations

* Insertion
* Deletion
* Searching
* Lookup

####Additional operations

* Find all strings with common prefix: returns an array of strings which begin with the same prefix.
* Find predecessor: Locates the largest string less than a given string, by lexicographic order.
* Find successor: Locates the smallest string greater than a given string, by lexicographic order.

####e.g.
![img](https://cloud.githubusercontent.com/assets/9131176/9570806/3466edb6-4fc6-11e5-8b74-39ec67898623.png)
