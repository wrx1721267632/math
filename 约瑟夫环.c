/*************************************************************************
	> File Name: 约瑟夫环.c
	> Author: 
	> Mail: 
	> Created Time: 2015年09月17日 星期四 19时53分30秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

struct huan
{
    int data;
    int num;
    struct huan *next;
};

struct huan *Create()
{
	struct huan *pHead;
	struct huan *pNew,*pEnd;
	int count = 1;

	pHead=(struct huan*)malloc(sizeof(struct huan));
	pNew=(struct huan*)malloc(sizeof(struct huan));
	printf("请输入第%d个数据：", count);
        pNew->num = count;
        scanf("%d", &pNew->data);
	if( pNew->data < 1 ){	
	    printf("输入错误！\n");
        printf("输入回车键继续\n");
        return NULL;
	}		
	count++;
	pNew->next=NULL;
	pHead->next=pNew;
	pEnd=pNew;
	while(1)
    { 
	    pNew=(struct huan*)malloc(sizeof(struct huan));
	    printf("请输入第%d个数据：", count);
        pNew->num = count;
        scanf("%d", &pNew->data);
        if( pNew->data < 1 ){
            if(count < 3){
                printf("输入错误！\n");
                printf("输入回车键继续\n");   
                return NULL;
            } else {
                printf("输入成功\n");
                break;
            }
        }
		count++;
		pNew->next=NULL;
		pEnd->next=pNew;
		pEnd=pNew;
	}
	pEnd->next=pHead->next;
	return pHead;
}

void Print(struct huan *pHead)
{
	struct huan *pTemp;
	
	if(pHead == NULL){
	    printf("不存在环形链表！");
	    return ;
	}
	pTemp=pHead->next;
	printf("第%d个数据是：%d\n", pTemp->num, pTemp->data);
    pTemp=pTemp->next;
	while(pTemp->num != 1)
	{
		printf("第%d个数据是：%d\n", pTemp->num, pTemp->data);
		pTemp=pTemp->next;
	}
}

void do_it(struct huan *pHead)
{
    struct huan *p1, *p2;
    int i;
    int n=1;
    int j;

    p1 = pHead->next;
    j=p1->data-1;
    while(1) {
        for(i=0; i<j; i++){
            p1 = p1->next;
        }
        printf("第%d的个被删除的数据: %d(num:%d)\n",n,p1->next->data, p1->next->num);
        j=p1->next->data-1;
        p2 = p1->next;
        p1->next = p2->next;
        free(p2);
        n++;
        if(p1->num == p1->next->num){
            printf("第%d的个被删除的数据: %d(num:%d)\n",n,p1->next->data, p1->next->num);
            break;
        }
    }
}

int main()
{
    char t;
    struct huan *pHead = NULL;

    while (1) {
        system("clear");
        printf("1.初始化\n");
        printf("2.运行并输出结果\n");
        printf("3.显示链表\n");
        printf("0.退出\n");
        printf("请输入你的选择：");
        scanf("%c", &t);
        if ((t != '0') && (t != '1') && (t != '2') && (t != '3')){
            printf("\n请正确输入!\n\n\n");
            printf("输入回车键继续\n");
            getchar();
            getchar();
            continue;
        }
        switch (t) {
            case '0':
                return 0;
            case '1':
                pHead = Create();
                break;
            case '2':
		        do_it(pHead);
                pHead = NULL;
                break;
            case '3':
               	Print(pHead);
                break;
        }
        printf("输入回车键继续\n");
        getchar();
        getchar();
    }
    return 0;
}
