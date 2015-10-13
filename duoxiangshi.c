/*************************************************************************
	> File Name: 多项式.c
	> Author: 
	> Mail: 
	> Created Time: 2015年09月29日 星期二 23时46分37秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct huan
{
    int xishu;
    int zhishu;
    struct huan *next;
};

struct huan *Create()
{
	struct huan *pHead;
	struct huan *pNew,*pEnd;
     
	pHead=(struct huan*)malloc(sizeof(struct huan));
	pNew=(struct huan*)malloc(sizeof(struct huan));
    printf("输入多项式系数：\n");
    scanf("%d",&pNew->xishu);
    printf("输入多项式指数：\n");
    scanf("%d",&pNew->zhishu);
	pNew->next=NULL;
	pHead->next=pNew;
	pEnd=pNew;
	while(1)
    { 
	    pNew=(struct huan*)malloc(sizeof(struct huan));
        printf("输入多项式系数：\n");
        scanf("%d",&pNew->xishu);
        if(pNew->xishu == 0){
            return pHead;
        }
        printf("输入多项式指数：\n");
        scanf("%d",&pNew->zhishu);
        if(pNew->zhishu == 0) {
            return pHead;
        }
		pNew->next=NULL;
		pEnd->next=pNew;
		pEnd=pNew;
    }
}

void Print(struct huan *pHead)
{
	struct huan *pTemp;
    int sum = 0;
	
	if(pHead == NULL){
	    printf("不存在！\n");
	    return ;
	}
	pTemp=pHead->next;
    if(pTemp->xishu != 0){
        printf("%dx^%d", pTemp->xishu, pTemp->zhishu);
        pTemp=pTemp->next;
        sum++;
    }
    if(pTemp == NULL){
        printf("\n");
        return ;
    }
    while(pTemp != NULL)
	{
        if((pTemp->xishu > 0) && (sum != 0)){
            printf("+");
        }
        if(pTemp->xishu != 0){
            printf("%dx^%d", pTemp->xishu, pTemp->zhishu);
            sum++;
        }
		pTemp=pTemp->next;
	}
    printf("\n");
}

struct huan* Jia(struct huan *pHead1, struct huan *pHead2)
{
    struct huan *p1, *p2, *pHead, *pEnd, *pNew;

    p1 = pHead1->next;
    p2 = pHead2->next;
	pHead=(struct huan*)malloc(sizeof(struct huan));
	pNew=(struct huan*)malloc(sizeof(struct huan));
    if(p1->zhishu > p2->zhishu){
        pNew->zhishu =  p2->zhishu;
        pNew->xishu = p2->xishu;
        p2 = p2->next;
    }
    else if(p1->zhishu < p2->zhishu){
        pNew->zhishu = p1->zhishu;
        pNew->xishu = p1->xishu;
        p1 = p1->next;
    }
    else if(p1->zhishu == p2->zhishu){
        pNew->zhishu = p1->zhishu;
        pNew->xishu = p1->xishu+p2->xishu;
        p1 = p1->next;
        p2 = p2->next;
    }
	pNew->next=NULL;
	pHead->next=pNew;
	pEnd=pNew;
	while(1)
    { 
	    pNew=(struct huan*)malloc(sizeof(struct huan));
        if((p1 == NULL) && (p2 == NULL)){
            return pHead;
        }
        if(p1 == NULL){
        pNew->zhishu =  p2->zhishu;
        pNew->xishu = p2->xishu;
        p2 = p2->next;
		pNew->next=NULL;
		pEnd->next=pNew;
		pEnd=pNew;
            continue;
        }
        if(p2 == NULL){
        pNew->zhishu = p1->zhishu;
        pNew->zhishu = p1->zhishu;
        p1 = p1->next;
		pNew->next=NULL;
		pEnd->next=pNew;
		pEnd=pNew;
            continue;
        }
    if(p1->zhishu > p2->zhishu){
        pNew->zhishu =  p2->zhishu;
        pNew->xishu = p2->xishu;
        p2 = p2->next;
    }
    else if(p1->zhishu < p2->zhishu){
        pNew->zhishu = p1->zhishu;
        pNew->xishu = p1->xishu;
        p1 = p1->next;
    }
    else if(p1->zhishu == p2->zhishu){
        pNew->zhishu = p1->zhishu;
        pNew->xishu = p1->xishu+p2->xishu;
        p1 = p1->next;
        p2 = p2->next;
    }
		pNew->next=NULL;
		pEnd->next=pNew;
		pEnd=pNew;
    }
}

struct huan* Jian(struct huan *pHead1, struct huan *pHead2)
{
    struct huan *p1, *p2, *pHead, *pEnd, *pNew;

    p1 = pHead1->next;
    p2 = pHead2->next;
	pHead=(struct huan*)malloc(sizeof(struct huan));
	pNew=(struct huan*)malloc(sizeof(struct huan));
    if(p1->zhishu > p2->zhishu){
        pNew->zhishu =  p2->zhishu;
        pNew->xishu = -p2->xishu;
        p2 = p2->next;
    }
    else if(p1->zhishu < p2->zhishu){
        pNew->zhishu = p1->zhishu;
        pNew->xishu = p1->xishu;
        p1 = p1->next;
    }
    else if(p1->zhishu = p2->zhishu){
        pNew->zhishu = p1->zhishu;
        pNew->xishu = p1->xishu - p2->xishu;
        p1 = p1->next;
        p2 = p2->next;
    }
	pNew->next=NULL;
	pHead->next=pNew;
	pEnd=pNew;
	while(1)
    { 
	    pNew=(struct huan*)malloc(sizeof(struct huan));
        if((p1 == NULL) && (p2 == NULL)){
            return pHead;
        }
        if(p1 == NULL){
        pNew->zhishu =  p2->zhishu;
        pNew->xishu = -p2->xishu;
        p2 = p2->next;
		pNew->next=NULL;
		pEnd->next=pNew;
		pEnd=pNew;
            continue;
        }
        if(p2 == NULL){
        pNew->zhishu = p1->zhishu;
        pNew->zhishu = p1->zhishu;
        p1 = p1->next;
		pNew->next=NULL;
		pEnd->next=pNew;
		pEnd=pNew;
            continue;
        }
    if(p1->zhishu > p2->zhishu){
        pNew->zhishu =  p2->zhishu;
        pNew->xishu = -p2->xishu;
        p2 = p2->next;
    }
    else if(p1->zhishu < p2->zhishu){
        pNew->zhishu = p1->zhishu;
        pNew->xishu = p1->xishu;
        p1 = p1->next;
    }
    else if(p1->zhishu = p2->zhishu){
        pNew->zhishu = p1->zhishu;
        pNew->xishu = p1->xishu - p2->xishu;
        p1 = p1->next;
        p2 = p2->next;
    }
		pNew->next=NULL;
		pEnd->next=pNew;
		pEnd=pNew;
    }
}

void Qiujie(struct huan *pHead)
{
    int sum = 0;
    int i;
    int x;
    int y;
    struct huan *p;

    printf("请输入x的值：\n");
    scanf("%d",&x);
    p=pHead->next;
    while(p != NULL){
        y = 1;
        for(i=0; i<p->zhishu; i++){
            y = y * x;
        }
        sum = sum + y * p->xishu;
        p = p->next;
    }
    printf("%d",sum);
}

int main()
{
    char t;
    struct huan *pHead1 = NULL;
    struct huan *pHead2 = NULL;
    struct huan *pHead = NULL;

    while (1) {
        system("clear");
        printf("1.输入多项式1\n");
        printf("2.输入多项式2\n");
        printf("3.输出多项式1\n");
        printf("4.输出多项式2\n");
        printf("5.多项式相加\n");
        printf("6.多项式相减\n");
        printf("7.多项式1求解\n");
        printf("8.多项式2求解\n");
        printf("0.退出\n");
        printf("请输入你的选择：");
        scanf("%c", &t);
        if ((t != '0') && (t != '1') && (t != '2') && (t != '3') && (t != '4') && (t != '5') &&(t != '6') && (t != '7') && (t != '8')){
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
                pHead1 = Create();
                break;
            case '2':
                pHead2 = Create();
                break;
            case '3':
		        Print(pHead1);
                break;
            case '4':
               	Print(pHead2);
                break;
            case '5':
               	pHead=Jia(pHead1,pHead2);
                Print(pHead);
                break;
            case '6':
                pHead=Jian(pHead1,pHead2);
                Print(pHead);
                break;
            case '7':
                Qiujie(pHead1);
                break;
            case '8':
                Qiujie(pHead2);
                break;
        }
        printf("输入回车键继续\n");
        getchar();
        getchar();
    }
    return 0;
}

