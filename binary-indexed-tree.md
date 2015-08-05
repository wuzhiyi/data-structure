###树状数组基本操作
####预备函数
定义一个 lowbit 函数，返回参数转为二进制后，最后一个 1 的位置所代表的数值
    //C++
    int lowbit(int x) {
        return x&(-x);
    }

####新建
维护 A 的前缀和
    //C++
    void build() {
        for (int i=1; i<MAX_N; i++) {
            BIT[i] = A[i];
            for (int j=i-1; j>i-1-lowbit(i); j-=lowbit(j))
                BIT[i] += BIT[j];
        }
    }

####修改
假设要将 A[i] 的值增加 delta，那么需要将 BIT[i] 覆盖的区间包含 A[i] 的值都加上 K
    //C++
    void edit(int i, int delta) {
        for (int j=i; j<=MAX_N; j+=lowbit(j))
            BIT[j] += delta;
    }

####求和
    //C/C++
    int sum(int k) {
        int ans=0;
        for (int i=k; i>0; i-=lowbit(i))
            ans += BIT[i];
        return ans;
    }
