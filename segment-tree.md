###线段树基本操作
---
####节点数据向上更新
将子节点的值更新到父节点

```c++
    //C++
    /* 对于区间求和 */
    void push_up(int rt) {
        tree[rt] = tree[rt << 1] + tree[rt << 1 | 1];
    }
    /* 对于区间求最大值 */
    void push_up(int rt) {
        tree[rt] = max(tree[rt << 1], tree[rt << 1 | 1]);
    }
```

####节点懒惰标记下推
对于区间求和, 原子数组值需要加上lazy标记乘以子树所统计的区间长度。 
len 为父节点统计的区间长度, 则 len - (len >> 1) 为左子树区间长度, len >> 1 为右子树区间长度。

```c++
    void push_down(int rt, int len) {
        tree[rt << 1] += lazy[rt] * (len - (len >> 1));
        lazy[rt << 1] += lazy[rt];
        tree[rt << 1 | 1] += lazy[rt] * (len >> 1);
        lazy[rt << 1 | 1] += lazy[rt];
        lazy[rt] = 0;
    }
```
    
对于区间求最大值，子树的值不需要乘以长度，所以不需要传递参数 len

    void push_down(int rt) {
        tree[rt << 1] += lazy[rt];
        lazy[rt << 1] += lazy[rt];
        tree[rt << 1 | 1] += lazy[rt];
        lazy[rt << 1 | 1] += lazy[rt];
        lazy[rt] = 0;
    }
    
####建树
新建一棵长度 N 的线段树

    #define lchild rt << 1, l, m
    #define rchild rt << 1 | 1, m + 1, r
    void build(int rt = 1, int l = 1, int r = N) {
        if (l == r) { std::cin >> tree[rt]; return; }
        int m = (l + r) >> 1;
        build(lchild); build(rchild);
        push_up(rt);
    }
    
####更新
单点更新，不需要用到 lazy 标记

    #define lchild rt << 1, l, m
    #define rchild rt << 1 | 1, m + 1, r
    void update(int p, int delta, int rt = 1, int l = 1, int r = N) {
        if (l == r) {
            tree[rt] += delta;
            return;
        }
        int m = (l + r) >> 1;
        if (p <= m) update(p, delta, lchild);
        else update(p, delta, rchild);
        push_up(rt);
    }
    
成段更新，需要用到 lazy 标记来提高时间效率

    #define lchild rt << 1, l, m
    #define rchild rt << 1 | 1, m + 1, r
    void update(int L, int R, int delta, int rt = 1, int l = 1, int r = N) {
        if (L <= l && r <= R) {
            tree[rt] += delta * (r - l + 1);
            lazy[rt] += delta;
            return;
        }
        if (lazy[rt]) push_down(rt, r - l + 1);
        int m = (l + r) >> 1;
        if (L <= m) update(L, R, delta, lchild);
        if (R > m)  update(L, R, delta, rchild);
        push_up(rt);
    }
    
####区间查询

    #define lchild rt << 1, l, m
    #define rchild rt << 1 | 1, m + 1, r
    int query(int L, int R, int rt = 1, int l = 1, int r = N) {
        if (L <= l && r <= R) return tree[rt];
        if (lazy[rt]) push_down(rt, r - l + 1);
        int m = (l + r) >> 1, ret = 0;
        if (L <= m) ret += query(L, R, lchild);
        if (R > m)  ret += query(L, R, rchild);
        return ret;
    }
