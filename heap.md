####堆

```c
    //C
    #define PARENT(i)   (i/2)
    #define LEFT(i)     (i*2)
    #define RIGHT(i)    (i*2+1)
    #define NOTNUSEDATA -65536
    void adjust_max_heap_recursive(int *datas, int length, int i) {
        int left, right, largest;
        int temp;
        left = LEFT(i); //left child
        right= RIGHT(i);//right child
        if (left<=length && datas[left]>datas[i])
            largest = left;
        else
            largest = right;
        if (right<=length && datas[right]>datas[largest])
            largest = right;
        if (largest != i) {
            temp = datas[i];
            datas[i] = datas[largest];
            datas[largest] = temp;
            adjust_max_heap_recursive(datas, length, largest);
        }
    }
    void adjust_max_heap(int *datas, int length, int i)
    {
        int left,right,largest;
        int temp;
        while (1)
        {
            left=LEFT(i);   //left child
            right=RIGHT(i); //right child
            //find the largest value among left and right and i.
            if (left<=length && datas[left]>datas[i])
                largest=i;
            else
                largest=i;
            if (right<=length && datas[right]>datas[largest])
                largest=right;
            //exchange i and largest
            if (largest!=i)
            {
                temp=datas[i];
                datas[i]=datas[largest];
                datas[largest]=temp;
                i=largest;
                continue;
            }
            else
            break;
        }
    }
    void build_max_heap(int *datas, int length)
    {
        int i;
        //build max heap from the last parent node
        for (i=length/2; i>0; i--)
            adjust_max_heap(datas,length,i);
    }
    void heap_sort(int *datas, int length)
    {
        int i,temp;
        //build max heap
        build_max_heap(datas, length);
        i=length;
        //exchange the first value to the last unitl i=1
        while (i>1)
        {
            temp=datas[i];
            datas[i]=datas[1];
            datas[1]=temp;
            i--;
            //adjust max heap, make sure the first value is the largest
            adjust_max_heap(datas,i,1);
        }
    }
    int main()
    {
        int i;
        //array's index begin 1
        int datas[11]={NOTNUSEDATA,5,3,17,10,84,19,6,22,9,35};
        heap_sort(datas,10);
        for (i=1; i<11; ++i)
            printf("%d\t",datas[i]);
        printf("\n");
        exit(0);
    }
```
    
####堆排序

```c
    //C
    #include <stdio.h>
    //array是待调整的堆数组，i是待调整的数组元素的位置，nlength是数组的长度
    //本函数功能是：根据数组array构建大根堆
    void HeapAdjust(int array[],int i,int nLength)
    {
        int nChild;
        int nTemp;
        for(;2*i+1<nLength;i=nChild)
        {
            //子结点的位置=2*（父结点位置）+1
            nChild=2*i+1;
            //得到子结点中较大的结点
            if(nChild<nLength-1&&array[nChild+1]>array[nChild])++nChild;
            //如果较大的子结点大于父结点那么把较大的子结点往上移动，替换它的父结点
            if(array[i]<array[nChild])
            {
                nTemp=array[i];
                array[i]=array[nChild];
                array[nChild]=nTemp; 
            }
            else break; //否则退出循环
        }
    }
    //堆排序算法
    void HeapSort(int array[],int length)
    {
        int i;
        //调整序列的前半部分元素，调整完之后第一个元素是序列的最大的元素
        //length/2-1是最后一个非叶节点，此处"/"为整除
        for(i=length/2-1;i>=0;--i)
        HeapAdjust(array,i,length);
        //从最后一个元素开始对序列进行调整，不断的缩小调整的范围直到第一个元素
        for(i=length-1;i>0;--i)
        {
            //把第一个元素和当前的最后一个元素交换，
            //保证当前的最后一个位置的元素都是在现在的这个序列之中最大的
            array[i]=array[0]^array[i];
            array[0]=array[0]^array[i];
            array[i]=array[0]^array[i];
            //不断缩小调整heap的范围，每一次调整完毕保证第一个元素是当前序列的最大值
            HeapAdjust(array,0,i);
        }
    }
    int main()
    {
        int i;
        int num[]={9,8,7,6,5,4,3,2,1,0};
        HeapSort(num,sizeof(num)/sizeof(int));
        for(i=0;i<sizeof(num)/sizeof(int);i++)
        {
            printf("%d ",num[i]);
        }
        printf("\nok\n");
        return 0;
    }
```
