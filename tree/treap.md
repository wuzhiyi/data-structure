##Treap
##Basic Operations
* search
* insert
* delete


####Search
To search for a given key value, apply a standard binary search algorithm in a binary search tree, ignoring the priorities.</br>
####Insert
To insert a new key _x_ into the treap, generate a random priority _y_ for _x_. Binary search for _x_ in the tree, and create a new node at the leaf position where the binary search determines a node for _x_ should exist. Then, as long as _x_ is not the roof of the tree and has a larger priority number than its parent _z_, perform a tree rotation that reverses the parent-child relation between _x_ and _z_.</br>
####Delete
To delete a node _x_ from the treap, if _x_ is a leaf of the tree, simply remove it. If _x_ has a single child _z_, remove _x_ from the tree and make _z_ be the child of the parent of _x_ (or make _z_ the root of the tree if _x_ had no parent). Finally, if _x_ has two children, swap its position in the tree with the position of its immediate successor _z_ in the sorted order, resulting in one of the previous cases. In this final case, the swap may violate the heap-ordering property for _z_, so additional rotations may need to be performed to restore this property.</br>

##Bulk Operations
* union
* intersection
* set difference

##Helper Operations
* split
* merge

####Split
To split a treap into two smaller treaps, those smaller than key _x_, and those larger than key _x_, insert _x_ into the treap with maximum prority--larger than the priority of any node in the treap. After this insertion, _x_ will be the root node of the treap, all values less than _x_ will be found in the left subtreap, and all values greater than _x_ will be found in the right subtreap. This costs as much as a single insertion into the treap.</br>
####Merge
Merging two treaps that are the product of a former split, one can safely assume that the greatest value in the first treap is less than the smallest value in the second treap. Create a new node with value _x_, such that _x_ is larger that this max-value in the first treap, and smaller than the min-value in the second treap, assign it the minimum priority, then set its left child to the first heap and it's right child to the second heap. Rotate as neccessary to fix the heap order. After that it will be a leaf node, and can easily be deleted. The result is one treap merged from the two original treaps. This is effectively "undoing" a split, and costs the same.</br>

####e.g.
![img](https://cloud.githubusercontent.com/assets/9131176/9602861/a7513138-50de-11e5-8f1c-0a7a3066baa8.png)</br>
