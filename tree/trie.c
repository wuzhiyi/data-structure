/**************************************************************
 * Copyright (c) Wuzhiyi
 * Introduction to Algorithms
 *
 * 题目:  Trie
 * 名称:
 * 作者:  wuzhiyi
 * 语言:  c
 * 内容摘要: 字典树
 *
 * 修改记录:
 * 修改日期       版本号       修改人       修改内容
 * ------------------------------------------------------------
 * 20150901      V1.0        wuzhiyi     创建
 **************************************************************/
#define MAX 26  //字符集大小
#define NULL (void*)0
typedef struct TrieNode
{
    int nCount;//记录该字符出现次数
    struct TrieNode* next[MAX];
}TrieNode;

TrieNode Memory[1000000];
int allocp=0;

/*初始化*/
void InitTrieRoot(TrieNode* *pRoot)
{
    *pRoot = NULL;
}

/*创建新结点*/
TrieNode* CreateTrieNode()
{
    int i;
    TrieNode *p;
    p = &Memory[allocp++];    //分配内存
    p->nCount = 1;            //记数指针初始化值为 1
    for(i=0; i<MAX; i++){
        p->next[i] = NULL;
    }
    return p;
}

/*插入*/
void InsertTrie(TrieNode* *pRoot,char *s)
{
    int i,k;
    TrieNode *p;
    if(!(p = *pRoot)){
        p = *pRoot = CreateTrieNode();
    }
    i = 0;
    while(s[i]){
        k = s[i++]-'a'; //确定branch
        if(p->next[k]) p->next[k]->nCount++;
        else p->next[k] = CreateTrieNode();
        p = p->next[k];
    }
}

//查找
int SearchTrie(TrieNode* *pRoot,char *s)
{
    TrieNode *p;
    int i,k;
    if(!(p = *pRoot)){
        return 0;
    }
    i = 0;
    while(s[i]){
        k = s[i++]-'a';
        if(p->next[k] == NULL) return 0;
        p = p->next[k];
    }
    return p->nCount;
}
