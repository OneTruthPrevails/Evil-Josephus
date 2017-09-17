#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct soldier
{
	int id;
	struct soldier *next;
}soldier;

typedef struct nibba
{
	soldier *last;
}nibba;

void recruit(nibba *t,int ele)
{
	soldier *p;
	p=(soldier *)malloc(sizeof(soldier));
	p->id=ele;
	if(t->last==NULL)
	{
		p->next=p;
		t->last=p;
	}
	else
	{
		p->next=t->last->next;
		t->last->next=p;
		t->last=p;
	}
}

void kill(nibba *t,int start,int n)
{
	int x,count=0,i;
	soldier *p,*q;
	if(t->last==NULL)
		return ;
	q=t->last->next;
	do
	{
		count++;
		q=q->next;
	}while(q!=t->last->next);
	while((start-1)!=0)
	{
		q=q->next;
		start--;
	}
	p=q;
	while(count>1)
	{
		for(i=0;i<=n;i++)
			p=p->next;
		for(i=1;i<=n;i++)
			q=q->next;
		if(p==t->last)
		{
			q->next=t->last->next;
			t->last=q;
			printf("niBBa %d is ded\n",p->id);
		}
		else if(p==t->last->next)
		{
			t->last->next=p->next;
			printf("niBBa %d is ded\n",p->id);
		}
		else
		{
			q->next=p->next;
			printf("niBBa %d is ded\n",p->id);
		}
		free(p);
		p=q;
		count--;
	}
	printf("niBBa %d survived!\n",t->last->id);
	getch();
}

void main()
{
	nibba x;
	int start,n,i,skeep,ch;
	x.last=NULL;
	clrscr();
	while(1)
	{
		clrscr();
		fflush(stdin);
		printf("O M A E   W A   M O U   S H I N D E I R U ! ! !\n");
		printf("What do you wanna do?\n1)Kill some soldiers    2)Get outta this Fantasy!!\nEnter choice:");
		scanf("%d",&ch);
		if(ch==1)
		{
			printf("\nHou many soldiers be there? :");
			scanf("%d",&n);
			for(i=0;i<n;i++)
				recruit(&x,i+1);
			printf("Whu be the first? :");
			scanf("%d",&start);
			printf("Hou many to skeep? :");
			scanf("%d",&skeep);
			kill(&x,start,skeep);
		}
		else if(ch==2)
			return;
		else
		{
			printf("niBBa dont insert unvalid option!!\n");
			getch();
		}
	}
}















