#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
	int classroom;
	int number;
	char name[10];
	int sex;
	int age;
	int bianhao;
	char subject[10];
	int credit;
	float test_score;
	float daily_score;
	float score;
	struct node *next;
}student;
student *head;
student *create()//录入信息函数
{
	int num;
	printf("请输入您想要录入的学生人数：");
	scanf("%d", &num);
	student *pf,*pb;
	if ((head = (student *)malloc(sizeof(student))) == NULL)
	{
		printf("录入失败");
		exit(0);
	}
	pf = head;
	for (int i = 0; i < num; i++)
	{
		pb = (student *)malloc(sizeof(student));
		printf("请输入该学生班级；");
		scanf("%d", &pb->classroom);
		printf("请输入该学生学号：");
		scanf("%d", &pb->number);
		printf("请输入该学生姓名：");
		scanf("%s", pb->name);
		printf("请输入该学生性别（男1女0）：");
		scanf("%d", &pb->sex);
		printf("请输入该学生年龄：");
		scanf("%d", &pb->age);
		printf("请输入该学生课程编号：");
		scanf("%d", &pb->bianhao);
		printf("请输入该学生课程名称：");
		scanf("%s", pb->subject);
		printf("请输入该学生学分：");
		scanf("%d", &pb->credit);
		printf("请输入该学生考试成绩：");
		scanf("%f", &pb->test_score);
		printf("请输入该学生平时成绩：");
		scanf("%f", &pb->daily_score);
		printf("***********************\n");
		pb->score= pb->test_score*0.7 + pb->daily_score*0.3;
		pb->next = NULL;
		pf->next = pb;
		pf = pb;
	}
	printf("已经录入完成\n");
	return (head);
}
student *search(student *searc)//查询函数
{
	int m;
	char namee[10];
	student *p = searc;
	p = searc->next;
	printf("选择1、姓名查询，选择2、学号查询\n");
	scanf("%d", &m);
	if (m == 1)
		goto usename;
	else goto usenumber;
usename:	
	printf("请输入该生姓名\n");
	scanf("%s", namee);
	while(p!= NULL)
	{
		if (strcmp(p->name, namee)==0)
		{
			printf("该生信息是：\n");
			printf("班级%d\n学号%d\n姓名%s\n性别（男1女0）%d\n年龄%d\n课程编号%d \n课程名称%s \n学分%d \n考试成绩%f \n平时成绩%f\n综合成绩%f\n", p->classroom, p->number, p->name, p->sex, p->age, p->bianhao, p->subject, p->credit, p->test_score, p->daily_score,p->score);
			return(p);
		}
		else p = p->next; 
	}
	printf("未找到该生\n");
	return(p);
usenumber:
	int t;
	printf("请输入该生学号\n");
	scanf("%d", &t);
	while(p != NULL)
	{
		if (p->number==t)
		{
			printf("该生信息是：\n");
			printf("班级%d\n学号%d\n姓名%s\n 性别（男1女0）%d\n 年龄%d\n 课程编号%d \n课程名称%s \n学分%d \n考试成绩%f \n平时成绩%f\n 综合成绩%f\n", p->classroom, p->number, p->name, p->sex, p->age, p->bianhao, p->subject, p->credit, p->test_score, p->daily_score, p->score);
			return(p);
		}

		else p = p->next;  
	}
	printf("未找到该生\n");
	return(p);
	
}
void change()//信息修改函数
{
	int m;
	student *p;
	printf("请输入该生的学号\n");
	scanf("%d", &m);
	p= head->next;
	while (p != NULL)
	{
		if (p->number == m)
		{
			printf("请输入该学生班级；");
			scanf("%d", &p->classroom);
			printf("请输入该学生学号：");
			scanf("%d", &p->number);
			printf("请输入该学生姓名：");
			scanf("%s", p->name);
			printf("请输入该学生性别（男1女0）：");
			scanf("%d", &p->sex);
			printf("请输入该学生年龄：");
			scanf("%d", &p->age);
			printf("请输入该学生课程编号：");
			scanf("%d", &p->bianhao);
			printf("请输入该学生课程名称：");
			scanf("%s", p->subject);
			printf("请输入该学生学分：");
			scanf("%d", &p->credit);
			printf("请输入该学生考试成绩：");
			scanf("%f", &p->test_score);
			printf("请输入该学生平时成绩：");
			scanf("%f", &p->daily_score);
			p->score = p->test_score*0.7 + p->daily_score*0.3;
			printf("修改完成\n");
			break;
		}
		else if(p->next!=NULL)p = p->next;
		else {
			printf("未找到该生\n"); break;
		}
	}
}
void insert()//插入函数
{
	student *p,*q;
	p = head->next;
	while (p->next != NULL)
		p = p->next;
	q = (student *)malloc(sizeof(student));
	printf("请输入该学生班级；");
	scanf("%d", &q->classroom);
	printf("请输入该学生学号：");
	scanf("%d", &q->number);
	printf("请输入该学生姓名：");
	scanf("%s", q->name);
	printf("请输入该学生性别（男1女0）：");
	scanf("%d", &q->sex);
	printf("请输入该学生年龄：");
	scanf("%d", &q->age);
	printf("请输入该学生课程编号：");
	scanf("%d", &q->bianhao);
	printf("请输入该学生课程名称：");
	scanf("%s", q->subject);
	printf("请输入该学生学分：");
	scanf("%d", &q->credit);
	printf("请输入该学生考试成绩：");
	scanf("%d", &q->test_score);
	printf("请输入该学生平时成绩：");
	scanf("%d", &q->daily_score);
	q->score = q->test_score*0.7 + q->daily_score*0.3;
	q->next = NULL;
	p->next = q;
	printf("插入成功\n");
}
void del()//数据删除函数
{
	int m;
	student *pf, *pb;
	printf("请输入您要删除的学生学号：");
	scanf("%d", &m);
	pf = head;
	pb = head->next;
	while (pb != NULL)
	{
		if (pb->number == m)
		{
			pf->next = pb->next;
			free(pb);
			printf("删除完成\n");
			break;
		}
		else if (pb->next != NULL) {
			pf = pb;
			pb = pb->next;
		}
		else {
			printf("未找到该生\n");
			break;
		}
	}
}
void main()
{
	int num;
	printf("\t\t***************************************************\n");
	printf("\t\t*          欢迎来到学生成绩管理系统               *\n");
	printf("\t\t***************************************************\n");
    printf("请输入您想进行的功能\n");
	while (1)
	{
		printf("选择1、录入学生信息\n选择2、查询学生信息\n选择3、修改学生数据\n选择4、删除学生信息\n选择5、插入学生数据\n选择6、退出\n");
		scanf("%d", &num);
	    switch (num)
		{
	       case 1:system("cls");
		          printf("\t\t***************************************************\n");
		          printf("\t\t*          欢迎来到学生成绩管理系统               *\n");
		          printf("\t\t***************************************************\n");
	              create(); break;
		   case 2:system("cls");
			      printf("\t\t***************************************************\n");
			      printf("\t\t*          欢迎来到学生成绩管理系统               *\n");
			      printf("\t\t***************************************************\n");
			      search(head); break;
		   case 3:system("cls");
			      printf("\t\t***************************************************\n");
			      printf("\t\t*          欢迎来到学生成绩管理系统               *\n");
			      printf("\t\t***************************************************\n");
			      change(); break;
		   case 4:system("cls");
			      printf("\t\t***************************************************\n");
			      printf("\t\t*          欢迎来到学生成绩管理系统               *\n");
			      printf("\t\t***************************************************\n");
				  del(); break;
		   case 5:system("cls");
			      printf("\t\t***************************************************\n");
			      printf("\t\t*          欢迎来到学生成绩管理系统               *\n");
			      printf("\t\t***************************************************\n"); 
				  insert(); break;
		   case 6:exit(0);
		}
	}
}
