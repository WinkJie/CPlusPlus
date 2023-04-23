#pragma once
#pragma warning(disable:4996)
#include<conio.h>
#include<stdio.h>
#include<malloc.h>
#define maxsize 100
#define NEW(L) (linklist*) malloc(sizeof(L))

typedef struct node {
	int num;
	char name[maxsize];
	float score;
	struct node* next;
}linklist;

//创建链表
linklist* creat() {
	linklist* L, * h, * p;
	int n = 0;
	int i;
	h = NEW(L);
	h->next = NULL;
	if (!h) {
		printf("首节点创建失败\n");
		return 0;
	}
	L = h;
	printf("请输入学生人数\n");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		p = NEW(L);
		printf("请输入第%d名学生的学号\n", i + 1);
		scanf("%d", &p->num);
		printf("请输入第%d名学生的姓名\n", i + 1);
		scanf("%s", p->name);
		printf("请输入第%d名学生的成绩\n", i + 1);
		scanf("%f", &p->score);
		L->next = p;
		p->next = NULL;
		L = L->next;
	}

}

//查找链表
void find(linklist* h) {
	linklist* p = h->next;
	int n = 0;
	printf("请输入要查询的学生学号");
	scanf("%d", &n);
	while (p) 
	{
		if (p->num == n)
		{
			printf("%s", p->name);
			break;
		}
		p = p->next;
	}
	printf("找不到该学生！\n");

}

void add(linklist* h) {
	linklist* p = NEW(p);
	printf("请输入学生姓名\n");
	scanf("%s", p->name);
	printf("请输入学生学号\n");
	scanf("%d", &p->num);
	printf("请输入学生成绩\n");
	scanf("%f", &p->score);
	p->next = NULL;
	linklist* r = nullptr;
	linklist* q = h;
	if (!h)
	{
		while (q)
		{
			r = q;
			q = q->next;
		}
		r->next = p;
		printf("插入成功！\n");		
	}
	else
	{
		printf("不存在该链表！");
	}
}

void del(linklist* h) {
	int num = 0;
	linklist* p = h;
	linklist* q;
	printf("请输入要删除的学生学号");
	scanf("%d", &num);

	while (p) {
		q = p;
		p = p->next;
		if (p->num == num)
		{
			q->next = p->next;
			free(p);
		}

	}
	printf("找不到该学生！\n");


}

void sizeOp()
{
	linklist* p = nullptr;
	int k; /*控制循环的标志*/
	while (1)
	{
		printf(" ----------------------------------\n");
		printf(" | 学生成绩管理 |\n");
		printf(" |＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿|\n");
		printf(" | 1.登记成绩 |\n");
		printf(" | 2.查询成绩 |\n");
		printf(" | 3:插入成绩 |\n");
		printf(" | 4.删除成绩 |\n");
		printf(" | 5.输出所有学生成绩 |\n");
		printf(" | 0.退出程序 |\n");
		printf(" ----------------------------------\n");
		printf(" 请输入你的选择\n");
		scanf("%d", &k);
		switch (k)
		{
		case 1: p = creat(); break;
		case 2: find(p); break;
		case 3: add(p); break;
		case 4: del(p); break;
		case 5: break;
		case 0: break;
		default: printf("选择错误，重新开始!\n");
		}
	}
}
#if 0
//Linux脚本关于时间的问题
#/!usr/bin/bash
t1 = 202210220000
ID = 'ps -ef |grep test.sh |grep -v grep |awk '{print $2}''
echo $ID
while true
do
var_time = $(date "+ %Y%m%d%H%M")
if[$var_time - eq $t1]; then
for id in $ID
do
kill - 9 $id
echo "kill $id"
break
else
echo $t1
echo $var_time
echo
fi
done
#endif // 0

#if 0
//Linux下的时间操作脚本
#!/bin/bash
date1 = "180609"
date2 = "180610"

day = $(date "+%Y-%m-%d" - d "$date1 0 day")
echo $day

t1 = `date - d "$date1" + % s`
t2 = `date - d "$date2" + % s`

echo t1 = $t1
echo t2 = $t2

if[$t1 - gt $t2]; then
	echo "$date1 > $date2"
elif[$t1 - eq $t2]; then
	echo "$date1 == $date2"
else
	echo "$date1 < $date2"
fi

#endif // 0

//