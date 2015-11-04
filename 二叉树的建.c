/*************************************************************************
	> File Name: 二叉树的建.c
	> Author: 
	> Mail: 
	> Created Time: 2015年11月04日 星期三 14时52分29秒
 ************************************************************************/

#include<stdio.h>
#include "string.h"
#include "malloc.h"

typedef struct BiTNode{ 
    char data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

BiTree Create(BiTree T) 
{
    char ch;
    ch=getchar();
    if(ch=='#')
    T=NULL;
    else
    {
        if(!(T=(BiTNode *)malloc(sizeof(BiTNode))))
        printf("Error!");
        T->data=ch;
        T->lchild=Create(T->lchild);
        T->rchild=Create(T->rchild);
    }
    return T;
}
void Preorder(BiTree T)
{                       
    if(T)
    {
        printf("%c",T->data);
        Preorder(T->lchild);
        Preorder(T->rchild);
    }
}

void zhongxu(BiTree T)
{
    if(T)
    {
        zhongxu(T->lchild);
        printf("%c",T->data);
        zhongxu(T->rchild);
    }
}

void houxu(BiTree T)
{
    if(T)
    {
        houxu(T->lchild);
        houxu(T->rchild);
        printf("%c",T->data);
    }
}

void main()
{
    BiTree T;
    int sum,dep;
    printf("please input data: ");
    T=Create(T);
    printf("xianxu: ");
    Preorder(T);
    printf("\n");
    printf("zhongxu: ");
    zhongxu(T);
    printf("\n");
    printf("houxu: ");
    houxu(T);
    printf("\n");
}
