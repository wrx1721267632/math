/*************************************************************************
	> File Name: 马踏棋盘.c
	> Author: 
	> Mail: 
	> Created Time: 2015年10月08日 星期四 14时01分51秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>

#define STACK_SIZE 1000
#define STACKINCREMENT 1000
#define N 8

int weight[N][N];
int borad[N][N][8];
int path[N][N];

struct around
{
    int x;
    int y;
};

struct zhan
{
    int ord;
    struct around seat;
    int di;
};

struct stack
{
    struct zhan base[STACK_SIZE];
    int top;
}s;

struct zhan GetTop()
{
    if(s.top == 0){
        exit(0);
    }
    return (s.base[s.top-1]);
}

void Push(struct zhan elem)
{
    s.base[s.top++] = elem;
}


int Pop(struct zhan *elem){
    if (s.top == 0)
        return 0;
    *elem = s.base[--s.top];
    return 1;
}

void OutputPath()
{ 
    int i, f, k;
    struct stack s1 = s;

    for (i=0; i < N*N; i++) {
        path[(s1.base[i]).seat.x][(s1.base[i].seat.y)] = i+1;
    } 
    for (f=0; f<N; f++) {
        printf("\n");
        for (k=0; k<N; k++) {
            printf("\t%d", path[f][k]);
        }
    }
    printf("\n");
    /*for(i=0;i<N;i++){
        for(f=0;f<N;f++){
            for(k=0;k<8;k++){
                printf("%4d",borad[i][f][k]);
            }
            printf("\n");
        }
    }*/
}

int Pass(struct around curpos)
{
    struct stack s1=s;
    if((curpos.x<0) || (curpos.x>(N-1)) || (curpos.y<0) || (curpos.y>(N-1))){
        return 0;
    }
    for(;s1.top != 0;) {
        --s1.top;
        if((curpos.x == (s1.base)[s1.top].seat.x) && (curpos.y == (s1.base[s1.top]).seat.y)) {
            return 0;
        }
    }
    return 1;
}

struct around NextPos(struct around curpos, int direction)
{
    switch(direction) {
        case 1:curpos.x+=1; curpos.y-=2; break;
        case 2:curpos.x+=2; curpos.y-=1; break;
        case 3:curpos.x+=2; curpos.y+=1; break;
        case 4:curpos.x+=1; curpos.y+=2; break;
        case 5:curpos.x-=1; curpos.y+=2; break;
        case 6:curpos.x-=2; curpos.y+=1; break;
        case 7:curpos.x-=2; curpos.y-=1; break;
        case 8:curpos.x-=1; curpos.y-=2; break;
    }
    return curpos;
}

void setweight()
{
    int i,j,k;
    struct around m;
    struct zhan elem;
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++) {
            elem.seat.x = i;
            elem.seat.y = j;
            weight[i][j] = 0;
            for(k=0; k<8; k++) {
                m=NextPos(elem.seat,k+1);
                if(m.x>=0 && m.x<N && m.y>=0 && m.y<N){
                    weight[i][j]++;
                }
            }
        }
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
                        sleep(1);
                    }
                }
            }
        }
}

void setmap()
{
    int a[8];
    int i,j,k,m,min,s,h;
    struct around n1,n2;

    for(i=0; i<N; i++){
        for (j=0; j<N; j++) {
            for (h=0; h<8; h++) {
                n2.x = i;
                n2.y = j;
                n1 = NextPos(n2,h+1);
                if((n1.x>=0) && (n1.x<N) && (n1.y>=0) && (n1.y<N)) {
                    a[h] = weight[n1.x][n1.y];
                }
                else a[h]=0;
            }
            for (m=0; m<8; m++) {
                min = 9;
                for (k=0; k<8; k++) {
                    if(min > a[k]) {
                        min = a[k];
                        borad[i][j][m] = k;
                        s = k; 
                    }
                }
                a[s] = 9;
            }
        }
    }
}

int HorsePath(struct around start)
{
    struct around curpos;
    int horsestep=0, off;
    struct zhan elem;
    int i;

    curpos = start;
    do{
        i++;
        if(Pass(curpos)) {
            horsestep++;
            elem.di = 0;
            elem.ord = horsestep;
            elem.seat = curpos;
            Push(elem);
            if(N*N == horsestep) {
                printf("%d\n",i);
                return 1;
            }
            off = borad[elem.seat.x][elem.seat.y][elem.di]+1;
            curpos = NextPos(elem.seat, off);
        }
        else {
            if(s.top) {
                while(s.top && elem.di == 8){
                    Pop(&elem);
                    if(s.top) {
                        elem = GetTop();
                        horsestep = elem.ord;
                    }
                }
                if(s.top && elem.di < 8) {
                    Pop(&elem);
                    off = borad[elem.seat.x][elem.seat.y][++elem.di];
                    curpos = NextPos(elem.seat, off+1);
                    Push(elem);
                }
            }
        }
    }while(s.top != 0);
    printf("no way\n");
    exit(0);
}

int main()
{
    struct around start;
    s.top = 0;
    printf("input: (0-7)\nX:");
    scanf("%d",&start.x);
    printf("Y:");
    scanf("%d",&start.y);
    setweight();
    setmap();
    HorsePath(start);
    OutputPath();
    //ShanShuo();
    return 0;
}
