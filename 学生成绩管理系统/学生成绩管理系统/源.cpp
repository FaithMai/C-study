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
student *create()//¼����Ϣ����
{
	int num;
	printf("����������Ҫ¼���ѧ��������");
	scanf("%d", &num);
	student *pf,*pb;
	if ((head = (student *)malloc(sizeof(student))) == NULL)
	{
		printf("¼��ʧ��");
		exit(0);
	}
	pf = head;
	for (int i = 0; i < num; i++)
	{
		pb = (student *)malloc(sizeof(student));
		printf("�������ѧ���༶��");
		scanf("%d", &pb->classroom);
		printf("�������ѧ��ѧ�ţ�");
		scanf("%d", &pb->number);
		printf("�������ѧ��������");
		scanf("%s", pb->name);
		printf("�������ѧ���Ա���1Ů0����");
		scanf("%d", &pb->sex);
		printf("�������ѧ�����䣺");
		scanf("%d", &pb->age);
		printf("�������ѧ���γ̱�ţ�");
		scanf("%d", &pb->bianhao);
		printf("�������ѧ���γ����ƣ�");
		scanf("%s", pb->subject);
		printf("�������ѧ��ѧ�֣�");
		scanf("%d", &pb->credit);
		printf("�������ѧ�����Գɼ���");
		scanf("%f", &pb->test_score);
		printf("�������ѧ��ƽʱ�ɼ���");
		scanf("%f", &pb->daily_score);
		printf("***********************\n");
		pb->score= pb->test_score*0.7 + pb->daily_score*0.3;
		pb->next = NULL;
		pf->next = pb;
		pf = pb;
	}
	printf("�Ѿ�¼�����\n");
	return (head);
}
student *search(student *searc)//��ѯ����
{
	int m;
	char namee[10];
	student *p = searc;
	p = searc->next;
	printf("ѡ��1��������ѯ��ѡ��2��ѧ�Ų�ѯ\n");
	scanf("%d", &m);
	if (m == 1)
		goto usename;
	else goto usenumber;
usename:	
	printf("�������������\n");
	scanf("%s", namee);
	while(p!= NULL)
	{
		if (strcmp(p->name, namee)==0)
		{
			printf("������Ϣ�ǣ�\n");
			printf("�༶%d\nѧ��%d\n����%s\n�Ա���1Ů0��%d\n����%d\n�γ̱��%d \n�γ�����%s \nѧ��%d \n���Գɼ�%f \nƽʱ�ɼ�%f\n�ۺϳɼ�%f\n", p->classroom, p->number, p->name, p->sex, p->age, p->bianhao, p->subject, p->credit, p->test_score, p->daily_score,p->score);
			return(p);
		}
		else p = p->next; 
	}
	printf("δ�ҵ�����\n");
	return(p);
usenumber:
	int t;
	printf("���������ѧ��\n");
	scanf("%d", &t);
	while(p != NULL)
	{
		if (p->number==t)
		{
			printf("������Ϣ�ǣ�\n");
			printf("�༶%d\nѧ��%d\n����%s\n �Ա���1Ů0��%d\n ����%d\n �γ̱��%d \n�γ�����%s \nѧ��%d \n���Գɼ�%f \nƽʱ�ɼ�%f\n �ۺϳɼ�%f\n", p->classroom, p->number, p->name, p->sex, p->age, p->bianhao, p->subject, p->credit, p->test_score, p->daily_score, p->score);
			return(p);
		}

		else p = p->next;  
	}
	printf("δ�ҵ�����\n");
	return(p);
	
}
void change()//��Ϣ�޸ĺ���
{
	int m;
	student *p;
	printf("�����������ѧ��\n");
	scanf("%d", &m);
	p= head->next;
	while (p != NULL)
	{
		if (p->number == m)
		{
			printf("�������ѧ���༶��");
			scanf("%d", &p->classroom);
			printf("�������ѧ��ѧ�ţ�");
			scanf("%d", &p->number);
			printf("�������ѧ��������");
			scanf("%s", p->name);
			printf("�������ѧ���Ա���1Ů0����");
			scanf("%d", &p->sex);
			printf("�������ѧ�����䣺");
			scanf("%d", &p->age);
			printf("�������ѧ���γ̱�ţ�");
			scanf("%d", &p->bianhao);
			printf("�������ѧ���γ����ƣ�");
			scanf("%s", p->subject);
			printf("�������ѧ��ѧ�֣�");
			scanf("%d", &p->credit);
			printf("�������ѧ�����Գɼ���");
			scanf("%f", &p->test_score);
			printf("�������ѧ��ƽʱ�ɼ���");
			scanf("%f", &p->daily_score);
			p->score = p->test_score*0.7 + p->daily_score*0.3;
			printf("�޸����\n");
			break;
		}
		else if(p->next!=NULL)p = p->next;
		else {
			printf("δ�ҵ�����\n"); break;
		}
	}
}
void insert()//���뺯��
{
	student *p,*q;
	p = head->next;
	while (p->next != NULL)
		p = p->next;
	q = (student *)malloc(sizeof(student));
	printf("�������ѧ���༶��");
	scanf("%d", &q->classroom);
	printf("�������ѧ��ѧ�ţ�");
	scanf("%d", &q->number);
	printf("�������ѧ��������");
	scanf("%s", q->name);
	printf("�������ѧ���Ա���1Ů0����");
	scanf("%d", &q->sex);
	printf("�������ѧ�����䣺");
	scanf("%d", &q->age);
	printf("�������ѧ���γ̱�ţ�");
	scanf("%d", &q->bianhao);
	printf("�������ѧ���γ����ƣ�");
	scanf("%s", q->subject);
	printf("�������ѧ��ѧ�֣�");
	scanf("%d", &q->credit);
	printf("�������ѧ�����Գɼ���");
	scanf("%d", &q->test_score);
	printf("�������ѧ��ƽʱ�ɼ���");
	scanf("%d", &q->daily_score);
	q->score = q->test_score*0.7 + q->daily_score*0.3;
	q->next = NULL;
	p->next = q;
	printf("����ɹ�\n");
}
void del()//����ɾ������
{
	int m;
	student *pf, *pb;
	printf("��������Ҫɾ����ѧ��ѧ�ţ�");
	scanf("%d", &m);
	pf = head;
	pb = head->next;
	while (pb != NULL)
	{
		if (pb->number == m)
		{
			pf->next = pb->next;
			free(pb);
			printf("ɾ�����\n");
			break;
		}
		else if (pb->next != NULL) {
			pf = pb;
			pb = pb->next;
		}
		else {
			printf("δ�ҵ�����\n");
			break;
		}
	}
}
void main()
{
	int num;
	printf("\t\t***************************************************\n");
	printf("\t\t*          ��ӭ����ѧ���ɼ�����ϵͳ               *\n");
	printf("\t\t***************************************************\n");
    printf("������������еĹ���\n");
	while (1)
	{
		printf("ѡ��1��¼��ѧ����Ϣ\nѡ��2����ѯѧ����Ϣ\nѡ��3���޸�ѧ������\nѡ��4��ɾ��ѧ����Ϣ\nѡ��5������ѧ������\nѡ��6���˳�\n");
		scanf("%d", &num);
	    switch (num)
		{
	       case 1:system("cls");
		          printf("\t\t***************************************************\n");
		          printf("\t\t*          ��ӭ����ѧ���ɼ�����ϵͳ               *\n");
		          printf("\t\t***************************************************\n");
	              create(); break;
		   case 2:system("cls");
			      printf("\t\t***************************************************\n");
			      printf("\t\t*          ��ӭ����ѧ���ɼ�����ϵͳ               *\n");
			      printf("\t\t***************************************************\n");
			      search(head); break;
		   case 3:system("cls");
			      printf("\t\t***************************************************\n");
			      printf("\t\t*          ��ӭ����ѧ���ɼ�����ϵͳ               *\n");
			      printf("\t\t***************************************************\n");
			      change(); break;
		   case 4:system("cls");
			      printf("\t\t***************************************************\n");
			      printf("\t\t*          ��ӭ����ѧ���ɼ�����ϵͳ               *\n");
			      printf("\t\t***************************************************\n");
				  del(); break;
		   case 5:system("cls");
			      printf("\t\t***************************************************\n");
			      printf("\t\t*          ��ӭ����ѧ���ɼ�����ϵͳ               *\n");
			      printf("\t\t***************************************************\n"); 
				  insert(); break;
		   case 6:exit(0);
		}
	}
}
