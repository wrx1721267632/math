/*************************************************************************
	> File Name: 二叉树先序遍历.c
	> Author: 
	> Mail: 
	> Created Time: 2015年11月04日 星期三 08时24分50秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;

SearchTree Insert(int x, SearchTree T);

struct TreeNode
{
    int data;
    SearchTree left;
    SearchTree right;
};

SearchTree Insert(int x, SearchTree T)
{
    if(T==NULL){
        T=malloc(sizeof(struct TreeNode));
        T->data = x;
        T->left = T->right =NULL;
    }
    else if(x < T->data)
        T->left = Insert(x,T->left);
    else if(x > T->data)
        T->right = Insert(x,T->right);
    return T;
}

void Find(SearchTree T)
{
    if(T != NULL) {
        Find(T->left);
        printf("%5d",T->data);
        Find(T->right);
    }
}

void Xianxu(SearchTree T)
{
    if(T != NULL){
        printf("%5d",T->data);
        Xianxu(T->left);
        Xianxu(T->right);
    }
}

void Houxu(SearchTree T)
{
    if(T != NULL){
        Houxu(T->left);
        Houxu(T->right);
        printf("%5d",T->data);
    }
}

int main()
{
    SearchTree T=NULL;
    int x;
    printf("请输入根结点： ");
    scanf("%d", &x);
    while(x != -1) {
        T = Insert(x,T);
        printf("请输入值： ");
        scanf("%d", &x);
    }
    printf("先序: ");
    Xianxu(T);
    printf("\n");
    printf("中序: ");
    Find(T);
    printf("\n");
    printf("后序: ");
    Houxu(T);
    printf("\n");
}
