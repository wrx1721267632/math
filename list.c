/*************************************************************************
    > File Name: list.c
    > Author: zhanghaoran
    > Mail: chilumanxi@gmail.com 
    > Created Time: 2015年07月22日 星期三 20时17分07秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>


struct student 
{
	int number;
	char name[10];
	int cursor;
};

int create_list(struct student list[])
{
	int i = 1;
	list[0].cursor = 1;
	while(list[i-1].number != 0) {
		printf("请输入学生学号:  ");
		scanf("%d",&list[i].number);
		printf("请输入学生姓名:  ");
		scanf("%s",list[i].name);
		list[i].cursor = i+1; 
		i++;
	}
	list[i-2].cursor = -1;
	return 0;
}

int print_list(struct student list[])
{
	int i ;
	i = list[0].cursor;
	while(i != -1) {
		printf("学号： %d\n",list[i].number);
		printf("姓名:  %s\n",list[i].name);
		i = list[i].cursor;
	}
	return 0;
}

int delete_list(struct student list[])
{
	int i = 0, t, n;
	printf("请输入要删除的信息:");
	scanf("%d",&n);
	t = list[i].cursor;
	while(i != -1) {
		if(list[t].number == n)
			break;
		i = t;
		t = list[i].cursor;
	}
	list[i].cursor = list[t].cursor;
	return 0;
}

int add_list(struct student list[])
{
	printf("请输入需要添家的学号姓名：");
	scanf("%d",&list[9].number);
	scanf("%s",list[9].name);
    list[9].cursor = list[0].cursor;
	list[0].cursor = 9;
}

int main()
{
	struct student list[10];
	create_list(list);
	print_list(list);
	delete_list(list);
	print_list(list);
	add_list(list);
	print_list(list);
	return 0;
}
