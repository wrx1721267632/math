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


#define N 24            //棋盘大小

int path[N][N];         //保存棋盘先后顺序的数组

struct seat             //保存二维数组位置的结构体（坐标x，y）
{
    int x;
    int y;
};
struct seat a;          //当前位置
struct seat b;          //下一步的位置

void Found(int i)       //找寻马的下一步的位置 ， 八个方向由i决定
{
    int around[9][2]={ {0,0}, {1,-2}, {2,-1}, {2,1}, {1,2}, {-1,2}, {-2,1}, {-2,-1}, {-1,-2}};  //保存的八个方向
    b.x=a.x+around[i][0];
    b.y=a.y+around[i][1];
}

void Tiao(int i)        //跳转位置的函数
{
    int around[9][2]={ {0,0}, {1,-2}, {2,-1}, {2,1}, {1,2}, {-1,2}, {-2,1}, {-2,-1}, {-1,-2}};  //保存的方向
    a.x=a.x+around[i][0];
    a.y=a.y+around[i][1];
}

void Selete()           //选择跳转路径的函数
{
    int x,y;
    int d[9];                   //数组a由1到8保存当前点跳转的八个方向中，若再次跳转可成功点的个数
    int i=1,j,min=9,k;
    int around[9][2]={ {0,0}, {1,-2}, {2,-1}, {2,1}, {1,2}, {-1,2}, {-2,1}, {-2,-1}, {-1,-2}};  //跳转的8个方向

    for(j=0; j<9; j++){         //初始化a数组
        d[j] = 9;
    }
    while(i != 9){

        Found(i);               //将b保存为a在i方向的位置
        if((b.x>=N) || (b.x<0) || b.y>=N || b.y <0 || (path[b.x][b.y]!=0)){     
            //若b不在正确位置或跳转的位置被占用了则其成功点的个数被保存未初始值9
            i++;
            continue;
        }
        d[i]=0;                 //已判断过该方向没有问题
        for(j=1; j<9; j++){
            if((b.x+around[j][0]<N) && (b.x+around[j][0] >=0) && (b.y+around[j][1] < N) && (b.y+around[j][1]>=0) && (path[b.x+around[j][0]][b.y+around[j][1]] == 0)){           //判断b的i方向是否可跳转，若可跳转则其权值加1
                d[i]++;
            }    
        }
        i++;                    //换a要跳转的下一个路径
    }
    for(i=1;i<9;i++){ 
        if(d[i]<min){           //找到权值最小的
            min = d[i];      
            k=i;                //权值最小的数组的下标就是a的真正下一个要跳的点
        }
    }
    Tiao(k);                    //运行跳转的函数
}

void In()                       //向path数组存入跳转的顺序
{
    int i=1;                    //i是存入的顺序，由1到N*N
   

    path[a.x][a.y] = i;         //将开始输入的坐标中存入1
    while (i != N*N){
        i++;
        Selete();               //选择路径的函数
        path[a.x][a.y] = i;     //将选择好的路径中存入相应的值
    }
   
}

void Print()                    //直接输出结果
{
    int i,j;
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            printf("%4d",path[i][j]);
        }
        printf("\n");
    }
}

void ShanShuo()                 //输出时有跳动的顺序的函数
{
    int a[N][N];                //新的函数，保存和path一样的结果
    int i, j;
    int flag=0;                 //结束的标志

    for(i=0; i<N; i++)          //初始化数组a
        for(j=0; j<N; j++)
                a[i][j] = -1;   
    

    while(flag != N*N){         //跳转的输出
        flag++;
        for(i=0; i<N; i++){     
            for(j=0; j<N; j++){
                    if(path[i][j] == flag){     //flag为1开始递增的数，正好用flag找到，path中马跳转的顺序
                        system("clear");        //清屏函数
                        a[i][j] = flag;         //将path数组中的值，按其递增的顺序传给a数组
                        for(i=0; i<N; i++){ 
                            for(j=0; j<N; j++){
                                if(a[i][j] >0 ){                            //因为开始全部初始化未-1，所以将大于0的数正常输出
                                    printf("\033[31m%4d\033[0m",a[i][j]);   //带颜色的输出数组
                                } 
                                else {                                      //将小于0的数输出*，然后加上清屏函数和循环可以有跳转的感觉
                                    printf("   *");
   
                                }
                            }
                            printf("\n");       //输出一行后用以换行
                        }
                        usleep(100000);         //在每多输出一个之后，停止0.1s
                    }
                }
            }
        }
}

int main()
{
    int i,j;                    //坐标位置
    for(i=0; i<N; i++){         //初始化棋盘数组
        for(j=0; j<N; j++){
            path[i][j] = 0;
        }
    }
    printf("x: ");              //输入第一个位置x坐标
    scanf("%d",&a.x);
    printf("y: ");              //输入第一个位置y坐标
    scanf("%d",&a.y);
   
    In();                       //向数组中保存跳转顺序
    Print();                    //输出保存完的数组的结果
    sleep(3);
    ShanShuo();                 //在输出时有一步一步跳的感觉（于本题无关，只为好看）
    return 0;
}
