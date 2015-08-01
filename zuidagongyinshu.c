/*************************************************************************
	> File Name: zuidagongyinshu.c
	> Author: 
	> Mail: 
	> Created Time: 2015年07月29日 星期三 15时04分43秒
 ************************************************************************/

#include<stdio.h>

int GCD(int a, int b)
{
    if(b== 0)
        return a;
    return GCD(b,a%b);
}

int main()
{
    int a, b;
    printf("请输入两个值： ");
    scanf("%d %d" , &a,&b);
    printf("最大公因数：%d\n",GCD(b,a%b));
    return 0;
}
