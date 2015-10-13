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
    int num;
    char x[10];
    struct huan *next;
};

struct huan *Create()
{
	struct huan *pHead;
	struct huan *pNew,*pEnd;
	int count = 1;
    char a[100];
    int i=0;
    char b[10];
    char c[10];
    int n=1;
    int j=0;
    int sum;
    int k;
    int t;

    printf("请输入多项式：\n");
    scanf("%s",a);

	pHead=(struct huan*)malloc(sizeof(struct huan));
	pNew=(struct huan*)malloc(sizeof(struct huan));
    if(a[i] == '-'){
        n = -1;
        i++;
    }
    sum = 0;
    while(a[i] != 'x') {
        b[sum] = a[i];
        i++;
        sum ++;
    }
    pNew->num = 0;
    for(k=0; k<sum; k++){
        t = b[k]-48;
        for(j=0; j<sum-k-1; j++){
            t*=10;
        }
        pNew->num = pNew->num + t;
    }
    pNew->num*=n;
    j=0;
    while(1){
        if(a[i] == '+'){
            n = 1;
            i++;
            break;
        }
        if(a[i] == '-'){
            n = -1;
            i++;
            break;
        }
        if(a[i] == '\0'){
            n = 0;
            break;
        }
        pNew->x[j] = a[i];
        i++;
        j++;
    }		
	pNew->next=NULL;
	pHead->next=pNew;
	pEnd=pNew;
    if( n == 0 ){
        return pHead;
    }
	while(1)
    { 
	    pNew=(struct huan*)malloc(sizeof(struct huan));
        sum = 0;
        while(a[i] != 'x') {
            b[sum] = a[i];
            i++;
            sum ++;
        }
        pNew->num = 0;
        for(k=0; k<sum; k++){
            t = b[k]-48;
            for(j=0; j<sum-k-1; j++){
                t*=10;
            }
            pNew->num = pNew->num + t;
        }
        pNew->num*=n;
        j=0;
        while(1){
            if(a[i] == '+'){
                n = 1;
                i++;
                break;
            }
            if(a[i] == '-'){
                n = -1;
                i++;
                break;
            }
            if(a[i] == '\0'){
                n = 0;
                break;
            }
            pNew->x[j] = a[i];
            i++;
            j++;
        }
		pNew->next=NULL;
		pEnd->next=pNew;
		pEnd=pNew;
        if(n == 0){
            return pHead;
        }
    }
}

void Print(struct huan *pHead)
{
	struct huan *pTemp;
	
	if(pHead == NULL){
	    printf("不存在！\n");
	    return ;
	}
	pTemp=pHead->next;
    printf("%d%s", pTemp->num, pTemp->x);
    pTemp=pTemp->next;
    if(pTemp == NULL){
        printf("\n");
        return ;
    }
    while(pTemp != NULL)
	{
        if(pTemp->num > 0){
            printf("+");
        }
        printf("%d%s", pTemp->num, pTemp->x);
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
    if(strcmp(p1->x,p2->x)>0){
        strcpy(pNew->x, p2->x);
        pNew->num = p2->num;
        p2 = p2->next;
    }
    else if(strcmp(p1->x,p2->x) < 0){
        strcpy(pNew->x, p1->x);
        pNew->num = p1->num;
        p1 = p1->next;
    }
    else if(strcmp(p1->x,p2->x) == 0){
        strcpy(pNew->x, p1->x);
        pNew->num = p2->num+p1->num;
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
            strcpy(pNew->x, p2->x);
            pNew->num = p2->num;
            p2 = p2->next;
		pNew->next=NULL;
		pEnd->next=pNew;
		pEnd=pNew;
            continue;
        }
        if(p2 == NULL){
            strcpy(pNew->x, p1->x);
            pNew->num = p1->num;
            p1 = p1->next;
		pNew->next=NULL;
		pEnd->next=pNew;
		pEnd=pNew;
            continue;
        }
        if(strcmp(p1->x,p2->x)>0){
            strcpy(pNew->x, p2->x);
            pNew->num = p2->num;
            p2 = p2->next;
        }
        else if(strcmp(p1->x,p2->x)<0){
            strcpy(pNew->x, p1->x);
            pNew->num = p1->num;
            p1 = p1->next;
        }
        else if(strcmp(p1->x,p2->x) == 0){
            strcpy(pNew->x, p1->x);
            pNew->num = p2->num+p1->num;
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
    if(strcmp(p1->x,p2->x)>0){
        strcpy(pNew->x, p2->x);
        pNew->num = -p2->num;
        p2 = p2->next;
    }
    else if(strcmp(p1->x,p2->x) < 0){
        strcpy(pNew->x, p1->x);
        pNew->num = p1->num;
        p1 = p1->next;
    }
    else if(strcmp(p1->x,p2->x) == 0){
        strcpy(pNew->x, p1->x);
        pNew->num = p1->num-p2->num;
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
            strcpy(pNew->x, p2->x);
            pNew->num = -p2->num;
            p2 = p2->next;
		pNew->next=NULL;
		pEnd->next=pNew;
		pEnd=pNew;
            continue;
        }
        if(p2 == NULL){
            strcpy(pNew->x, p1->x);
            pNew->num = p1->num;
            p1 = p1->next;
		pNew->next=NULL;
		pEnd->next=pNew;
		pEnd=pNew;
            continue;
        }
        if(strcmp(p1->x,p2->x)>0){
            strcpy(pNew->x, p2->x);
            pNew->num = -p2->num;
            p2 = p2->next;
        }
        else if(strcmp(p1->x,p2->x)<0){
            strcpy(pNew->x, p1->x);
            pNew->num = p1->num;
            p1 = p1->next;
        }
        else if(strcmp(p1->x,p2->x) == 0){
            strcpy(pNew->x, p1->x);
            pNew->num = p1->num-p2->num;
            p1 = p1->next;
            p2 = p2->next;
        }
		pNew->next=NULL;
		pEnd->next=pNew;
		pEnd=pNew;
    }
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
        printf("0.退出\n");
        printf("请输入你的选择：");
        scanf("%c", &t);
        if ((t != '0') && (t != '1') && (t != '2') && (t != '3') && (t != '4') && (t != '5') &&(t != '6')){
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
        }
        printf("输入回车键继续\n");
        getchar();
        getchar();
    }
    return 0;
}

