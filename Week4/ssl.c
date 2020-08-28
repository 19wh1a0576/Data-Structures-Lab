#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
struct node *head=NULL,*tail=NULL,*cur,*prev,*next;
void create()
{
	int n,i;
	printf("Enter the number of nodes:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		cur=(struct node*)malloc(sizeof(struct node));
		printf("Enter current node data");
		scanf("%d",&(cur->data));
		cur->link=NULL;
		if(head==NULL)
		{
			head=tail=cur;
		}
		else
		{
			tail->link=cur;
			tail=cur;
		}
	}

}
void insert_at_begin()
{
	cur = (struct node*)malloc(sizeof(struct node));
	printf("Enter new beginning node data:\n");
	scanf("%d",&(cur->data));
	cur->link=head;
	head=cur;
}
void insert_at_pos()
{
	int pos,c=1;
	cur=(struct node*)malloc(sizeof(struct node));
	printf("enter new node data to be stored at a position:\n");
	scanf("%d",&(cur->data));
	printf("enter position where the data is to be store:\n");
	scanf("%d",&pos);
	next=head;
	while(c<pos)
	{
		prev=next;
		next=next->link;
		c++;
	}
	prev->link=cur;
	cur->link=next;
}
void insert_at_end()
{
	cur=(struct node*)malloc(sizeof(struct node));
	printf("Enter current node data");
	scanf("%d",&(cur->data));
	cur->link=NULL;
	tail->link=cur;
	tail=cur;
}
void insert_before_node()
{
	int value;
	cur=(struct node*)malloc(sizeof(struct node));
	printf("enter new node data:\n");
	scanf("%d",&(cur->data));
	printf("Enter data to insert");
	scanf("%d",&value);
	next=head;
	while(next->data!=value && next!= NULL)
	{
		prev=next;
		next=next->link;

	}
	prev->link=cur;
	cur->link=next;
}
void insert_after_node()
{
	int value;
	cur=(struct node*)malloc(sizeof(struct node));
	printf("enter new node data:\n");
	scanf("%d",&(cur->data));
	printf("Enter after which node we need to do insertion");
	scanf("%d",&value);
	next=head;
	while(next->data!=value && next!= NULL)
	{
		next=next->link;

	}
	cur->link=next->link;
	next->link=cur;
}
void delete_at_begin()
{
	cur=head;
	head=cur->link;
	cur->link=NULL;
	printf("Deleted element is %d\n",cur->data);
	free(cur);
}
void delete_at_end()
{
	cur=head;
	while(cur->link!=tail)
		cur=cur->link;
	cur->link=NULL;
	next=tail;
	printf("Deleted element is %d",next->data);
	free(next);
	tail=cur;
}
void delete_at_pos()
{
	int pos,c=1;
	printf("Enter position of deletion");
	scanf("%d",&pos);
	next=head;
	while(c<pos)
	{
		prev=next;
		next=next->link;
		c++;
	}
	prev->link=next->link;
	printf("Deleted element is %d\n",next->data);
	next->link=NULL;
	free(next);
}
void delete_before_node()
{
	int value;
	printf("Enter position of deletion");
	scanf("%d",&value);
	next=head;
	while(next->link->data!=value)
	{
		prev=next;
		next=next->link;
		
	}
	prev->link=next->link;
	next->link=NULL;
	printf("Deleted element is %d\n",next->data);
	free(next);
}
void delete_after_node()
{
	int value;
	printf("Enter position of deletion");
	scanf("%d",&value);
	next=head;
	while(next->data!=value)
	{
		prev=next;
		next=next->link;
		
	}
	prev=next->link;
	next->link=prev->link;
	printf("Deleted data is %d\n",prev->data);
	prev->link=NULL;
	free(prev);
}
void traversal()
{
	if(head==NULL)
		printf("list is empty\n");
	else
	{
		next=head;
		while(next!=NULL)
		{
			printf("%d->",next->data);
			next=next->link;
		}
		
	}
}
void reverse_array()
{
	int a[100];
	int i=0;
	cur=head;
	while(cur!=NULL)
	{
		a[i]=cur->data;
		cur=cur->link;
		i+=1;
	}
	i-=1;
	printf("NULL ");
	while(i>=0)
	{
		printf("%d->",a[i]);
		i--;
	}

}
void search_element()
{
	int value,c=0,flag=0;
	printf("Enter element to be searched:\n");
	scanf("%d",&value);
	next=head;
	while(next!=NULL)
	{
		if(next->data==value)
		{
			flag=1;
			break;
		}
		next=next->link;
		c++;
	}
	if(flag==1)
		printf("Element is present at the position=%d\n",c);
	else
		printf("Element is not present\n");
		
}
void bubblesort()
{
	struct node*p1,*p2;
	int t;
	p1=head;
	int c=0,i;
	while(p1!=NULL)
	{
		c++;
		p1=p1->link;
	}
	for(i=0;i<c;i++)
	{
		p2=head;
		while(p2->link!=NULL)
		{	
			if(p2->data>p2->link->data)
			{
				t=p2->data;
				p2->data=p2->link->data;
				p2->link->data=t;
			}
		}
		p2=p2->link;
	}

}
void reverse(struct node *head)
{
	if(head != NULL)
	{
		reverse(head->link);
		printf("<-%d",head->data);
	}
	else
		printf("NULL");
}
void sorting()
{
	struct node *p1,*p2,*last=NULL;
	int c,t;
	do
	{
		c=0;
		p1=head;
		while(p1->link != last)
		{
			if(p1->data > p1->link->data)
			{
				t=p1->data;
				p1->data=p1->link->data;
				p1->link->data=t;
				c=1;
			}
			p1=p1->link;
		}
		last=p1;
	}while(c);
}
int main()
{
	int ch;
	while(1)
	{
	printf("Program for single linked list\n");
	printf("1-create\n");
	printf("2-insert at begin\n");
	printf("3- insert at position\n");
	printf("4-insert at end\n");	
	printf("5-insert before\n");
	printf("6-insert after node\n");
	printf("7-delete at begin\n");
	printf("8-delete at end\n");	
	printf("9-delete at pos\n");	
	printf("10-delete before node\n");
	printf("11-delete after node\n");
	printf("12-traversal\n");
	printf("13-display in reverse array\n");	
	printf("14-searching for an element\n");
	printf("15-bubblesort\n");
	printf("16-reverse\n");
	printf("17-sorting\n");
	printf("18-Exit\n");
	printf("enter your choice\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1: create();
			break;
		case 2: insert_at_begin();
			break;
		case 3: insert_at_pos();
			break;
		case 4: insert_at_end();
			break;
		case 5:insert_before_node();
			break;
		case 6: insert_after_node();
			break;
		case 7: delete_at_begin();
			break;
		case 8: delete_at_end();
			break;
		case 9: delete_at_pos();
			break;
		case 10:delete_before_node();
			break;
		case 11:delete_after_node();
			break;
		case 12:traversal();
			break;
		case 13:reverse_array();
			break;
		case 14:search_element();
			break;
		case 15:bubblesort();
			break;
		case 16:reverse(head);
			break;
		case 17:sorting();
			break;
		case 18: exit(0);
	}
	}
	return 0;
}