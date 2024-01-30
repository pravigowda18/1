//#include<stdio.h>
#include<cstdlib>
#include<iostream>

using namespace std;
struct node
{
	int info;
	struct node *link;
};

struct node *create_list(struct node *start);
void display(struct node *start);
struct node *insertatbeg(struct node *start,int data);
struct node *insertatend(struct node *start,int data);
void Split(struct node *start, int value, struct node **start1);

int main()
{
	struct node *start=NULL,*start1=NULL;
	int value;
	
	start=create_list(start);
	display(start);
	cout<<"Enter node after which u want to Split : ";
	cin>>value;
	
	Split(start, value, &start1);
	display(start);
	display(start1);
	
	return 0;
}

void Split(struct node *start, int value, struct node **start1)
{
	struct node *p=start;
	while(p!=NULL)
	{
		if(p->info==value)
			break;
		p=p->link;
	}
	
	if(p==NULL){
		cout<<"\nValue does not exist\n";
		return;
	}
	
	*start1=p->link;
	p->link=NULL;
}

struct node *create_list(struct node *start)
{
	int i,n,data;
	cout<<"Enter the number of nodes : ";
	cin>>n;
	
	start=NULL;
	if(n==0)
		return start;
		
	cout<<"\nEnter the element to be inserted : ";
	cin>>data;
	start=insertatbeg(start,data);
	
	for(i=2;i<=n;i++){
		cout<<"\nEnter the element to be inserted : ";
		cin>>data;
		start=insertatend(start,data);
	}
	return start;
}

void display(struct node *start)
{
	struct node *p;
	if(start==NULL){
		cout<<"\nList is empty\n";
		return;
	}
	p=start;
	cout<<"\nList is :\n";
	while(p!=NULL){
		cout<<p->info<<" ";
		p=p->link;
	}
	
	cout<<"\n\n";
}

struct node *insertatbeg(struct node *start,int data)
{
	struct node *tmp;

	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	tmp->link=start;
	start=tmp;
	return start;
}

struct node *insertatend(struct node *start,int data)
{
	struct node *p,*tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	p=start;
	while(p->link!=NULL)
		p=p->link;
	p->link=tmp;
	tmp->link=NULL;
	return start;
}
