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

//��������
linklist* creat() {
	linklist* L, * h, * p;
	int n = 0;
	int i;
	h = NEW(L);
	h->next = NULL;
	if (!h) {
		printf("�׽ڵ㴴��ʧ��\n");
		return 0;
	}
	L = h;
	printf("������ѧ������\n");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		p = NEW(L);
		printf("�������%d��ѧ����ѧ��\n", i + 1);
		scanf("%d", &p->num);
		printf("�������%d��ѧ��������\n", i + 1);
		scanf("%s", p->name);
		printf("�������%d��ѧ���ĳɼ�\n", i + 1);
		scanf("%f", &p->score);
		L->next = p;
		p->next = NULL;
		L = L->next;
	}

}

//��������
void find(linklist* h) {
	linklist* p = h->next;
	int n = 0;
	printf("������Ҫ��ѯ��ѧ��ѧ��");
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
	printf("�Ҳ�����ѧ����\n");

}

void add(linklist* h) {
	linklist* p = NEW(p);
	printf("������ѧ������\n");
	scanf("%s", p->name);
	printf("������ѧ��ѧ��\n");
	scanf("%d", &p->num);
	printf("������ѧ���ɼ�\n");
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
		printf("����ɹ���\n");		
	}
	else
	{
		printf("�����ڸ�����");
	}
}

void del(linklist* h) {
	int num = 0;
	linklist* p = h;
	linklist* q;
	printf("������Ҫɾ����ѧ��ѧ��");
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
	printf("�Ҳ�����ѧ����\n");


}

void sizeOp()
{
	linklist* p = nullptr;
	int k; /*����ѭ���ı�־*/
	while (1)
	{
		printf(" ----------------------------------\n");
		printf(" | ѧ���ɼ����� |\n");
		printf(" |�ߣߣߣߣߣߣߣߣߣߣߣߣߣߣߣ�|\n");
		printf(" | 1.�Ǽǳɼ� |\n");
		printf(" | 2.��ѯ�ɼ� |\n");
		printf(" | 3:����ɼ� |\n");
		printf(" | 4.ɾ���ɼ� |\n");
		printf(" | 5.�������ѧ���ɼ� |\n");
		printf(" | 0.�˳����� |\n");
		printf(" ----------------------------------\n");
		printf(" ���������ѡ��\n");
		scanf("%d", &k);
		switch (k)
		{
		case 1: p = creat(); break;
		case 2: find(p); break;
		case 3: add(p); break;
		case 4: del(p); break;
		case 5: break;
		case 0: break;
		default: printf("ѡ��������¿�ʼ!\n");
		}
	}
}
#if 0
//Linux�ű�����ʱ�������
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
//Linux�µ�ʱ������ű�
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