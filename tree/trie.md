##Trie
又称单词查找树、字典树，是一种树形结构，是一种哈希树的变种，是一种用于快速检索的多叉树结构。</br>
最典型的应用是字符串的统计和排序（但不仅限于字符串），所以经常被搜索引擎系统用于文本词频统计。
####优点
最大限度地减少无谓的字符串比较，查询效率比哈希表高。
####核心思想
空间换时间。利用字符串的公共前缀来降低查询时间的开销以达到提高效率的目的。
####基本特性
1. 根节点不包含字符，除根节点外每一个节点都只包含一个字符。
2. 从根节点到某一节点，路径上经过的字符连接起来，为该节点对应的字符串。
3. 每个节点的所有子节点包含的字符都不相同。

####e.g.
![img](https://cloud.githubusercontent.com/assets/9131176/9621194/186672ee-5156-11e5-903c-2d318abe83b5.png)</br>

####Source Code
* [trie-1](https://github.com/wuzhiyi/data-structure/blob/master/tree/trie-1.c)
* [trie-2](https://github.com/wuzhiyi/data-structure/blob/master/tree/trie-2.c)
