####并查集
	//合并两个不相交集合
	void Union(int x, int y) {
		fx = Getfather(x);
		fy = Getfather(y);
		if (fy != fx)
			father[fx] = fy;
	}
	
	//判断两个元素是否属于同一集合
	int Same(int x, int y) {
		if (Getfather(x) == Getfather(y))
			return 1;
		else return 0;
	}
	
	//路径压缩
	int Getfather(int v) {
		if (father[v] == v)
			return v;
		else {
			father[v] = Getfather(father[v]);	//路径压缩
			return father[v];
	}
	
	//轶合并
	void Judge(int x, int y) {
		fx = Getfather(x);
		fy = Getfather(y);
		
		if (rank[fx] > rank[fy])
			father[fy] = fx;
		else {
			father[fx] = fy;
			if (rank[fx] == rank[fy])
				++rank[fy];//只用修改祖先的rank
		}
	}

##Note
两种优化方法：
####按轶合并
	function Market(x)
		x.parent := x
		x.rank	 := 0
		
	function Union(x, y)
		xRoot := Find(x)
		yRoot := Find(y)
		if xRoot == yRoot
			return
			
		//x和y不在同一个集合，合并它们
		if xRoot.rank < yRoot.rank
			xRoot.parent := yRoot
		else if xRoot.rank > yRoot.rank
			yRoot.parent := xRoot
		else
			//两棵树轶相同
			yRoot.parent := xRoot
			xRoot.rank := xRoot.rank + 1

####路径压缩
	function Find(x)
		if x.parent != x
			x.parent := Find(x.parent)
		return x.parent
		
