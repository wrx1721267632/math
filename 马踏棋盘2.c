/*************************************************************************
	> File Name: 马踏棋盘2.c
	> Author: 
	> Mail: 
	> Created Time: 2015年10月12日 星期一 23时24分51秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>


#define N 8

int path[N][N];
struct seat
{
    int x;
    int y;
};
struct seat a;
struct seat b;

void Found(int i)
{
    switch(i) {
        case 1:b.x=a.x+1; b.y=a.y-2; break;
        case 2:b.x=a.x+2; b.y=a.y-1; break;
        case 3:b.x=a.x+2; b.y=a.y+1; break;
        case 4:b.x=a.x+1; b.y=a.y+2; break;
        case 5:b.x=a.x-1; b.y=a.y+2; break;
        case 6:b.x=a.x-2; b.y=a.y+1; break;
        case 7:b.x=a.x-2; b.y=a.y-1; break;
        case 8:b.x=a.x-1; b.y=a.y-2; break;
    }
}

void Tiao(int i)
{
    switch(i) {
        case 1:a.x=a.x+1; a.y=a.y-2; break;
        case 2:a.x=a.x+2; a.y=a.y-1; break;
        case 3:a.x=a.x+2; a.y=a.y+1; break;
        case 4:a.x=a.x+1; a.y=a.y+2; break;
        case 5:a.x=a.x-1; a.y=a.y+2; break;
        case 6:a.x=a.x-2; a.y=a.y+1; break;
        case 7:a.x=a.x-2; a.y=a.y-1; break;
        case 8:a.x=a.x-1; a.y=a.y-2; break;
    }
}

void Selete()
{
    int x,y, d[9];
    int i=1,j,min=9,k;

    for(j=0; j<9; j++){
        d[j] = 9;
    }
    while(i != 9){

        Found(i);
        if((b.x>=N) || (b.x<0) || b.y>=N || b.y <0 || (path[b.x][b.y]!=0)){
            i++;
            continue;
        }
        d[i]=0;
        if((b.x+1<N) && (b.y-2>=0) && (path[b.x+1][b.y-2] == 0)){
            d[i]++;
        }
        if((b.x+2<N) && (b.y-1>=0) && (path[b.x+2][b.y-1] == 0)){
            d[i]++;
        }
        if((b.x+2<N) && (b.y+1<N) && (path[b.x+2][b.y+1] == 0)){
            d[i]++;
        }
        if((b.x+1<N) && (b.y+2<N) && (path[b.x+1][b.y+2] == 0)){
            d[i]++;
        }
        if((b.x-1>0) && (b.y+2<N) && (path[b.x-1][b.y+2] == 0)){
            d[i]++;
        }
        if((b.x-2>=0) && (b.y+1<N) && (path[b.x-2][b.y+1] == 0)){
            d[i]++;
        }
        if((b.x-2>=0) && (b.y-1>=0) && (path[b.x-2][b.y-1] == 0)){
            d[i]++;
        }
        if((b.x-1>=0) && (b.y-2>0) && (path[b.x-1][b.y-2] == 0)){
            d[i]++;
        }
        i++;
    }
    for(i=1;i<9;i++){
        printf("%d",d[i]);
        if(d[i]<min){
            min = d[i];
            k=i;
        }
    }
    printf("\n");
    Tiao(k);
}

void In()
{
    int i=1;
   

    path[a.x][a.y] = i;
    while (i != N*N){
        i++;
        Selete();
        printf("i:%d   %d,%d\n",i,a.x,a.y);
        path[a.x][a.y] = i;
    }
   
}

void Print()
{
    int i,j;
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            printf("%4d",path[i][j]);
        }
        printf("\n");
    }
}

void ShanShuo()
{
    int a[N][N];
    int i, j, flag=0;

    for(i=0; i<N; i++) 
        for(j=0; j<N; j++)
                a[i][j] = -1;
    

    while(flag != N*N){
        flag++;
        for(i=0; i<N; i++){
   
            for(j=0; j<N; j++){
                    if(path[i][j] == flag){
                        system("clear");
                        a[i][j] = flag;
                        for(i=0; i<N; i++){
                            for(j=0; j<N; j++){
                                if(a[i][j] >0 ){
                                    printf("\033[31m%4d\033[0m",a[i][j]);
                                }
                                else {
                                    printf("   *");
   
                                }
                            }
                            printf("\n");
                        }
                        usleep(500000);
                    }
                }
            }
        }
}

int main()
{
    int i,j;
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            path[i][j] = 0;
        }
    }
    printf("x: \n");
    scanf("%d",&a.x);
    printf("y: \n");
    scanf("%d",&a.y);
   
    In();
    Print();
    ShanShuo();
    return 0;
}
