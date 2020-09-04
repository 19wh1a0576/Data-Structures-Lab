#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*prev;
	struct node*next;
};
struct node*head=NULL,*tail=NULL,*cur,*temp1,*temp2;
void create()
{
	int n;
	printf("Enter number of nodes:\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		cur = (struct node*)malloc(sizeof(struct node));
		printf("Enter current node data:\n");
		scanf("%d",&(cur->data));
		cur->prev=NULL;
		cur->next=NULL;
		if(head==NULL)
			head=tail=cur;
		else
		{
			tail->next=cur;
			cur->prev=tail;
			tail=cur;
		}
	}

}
void insert_at_begin()
{
	cur=(struct node*)malloc(sizeof(struct node));
	printf("Enter current node data:\n");
	scanf("%d",&(cur->data));
	cur->prev=NULL;
	cur->next=head;
	head->prev=cur;
	head=cur;
}
void insert_at_end()
{
	cur=(struct node*)malloc(sizeof(struct node));
	printf("Enter current node data:\n");
	scanf("%d",&(cur->data));
	cur->next=NULL;
	tail->next=cur;
	cur->prev=tail;
	tail=cur;
}
void insert_at_pos()
{
	int pos;
	cur=(struct node*)malloc(sizeof(struct node));
	printf("Enter current node data:\n");
	scanf("%d",&(cur->data));
	printf("Enter the position of insertion\n");
	scanf("%d",&pos);
	int c=1;
	temp1=head;
	while(c<pos && temp1 != NULL)
	{
		temp2=temp1;
		temp1=temp1->next;
		c++;
	}
	temp2->next=cur;
	cur->prev=temp2;
	cur->next=temp1;
	temp1->prev=cur;
}
void insert_before_node()
{
	int value;
	cur=(struct node*)malloc(sizeof(struct node));
	printf("Enter current node data:\n");
	scanf("%d",&(cur->data));
	printf("Enter before which node we need to insert:\n");
	scanf("%d",&value);
	temp1=head;
	while(temp1->data != value && temp1!=NULL)
	{
		temp2=temp1;
		temp1=temp1->next;
	}
	temp2->next=cur;
	cur->prev=temp2;
	cur->next=temp1;
	temp1->prev=cur;
}
void insert_after_node()
{
	int value;
	cur=(struct node*)malloc(sizeof(struct node));
	printf("Enter current node data:\n");
	scanf("%d",&(cur->data));
	printf("Enter after which node we need to insert:\n");
	scanf("%d",&value);	
	temp1=head;
	while(temp1->data!=value && temp1 != NULL)
	{
		temp1=temp1->next;
	}
	temp2=temp1->next;
	cur->next=temp2;
	temp2->prev=cur;
	temp1->next=cur;
	cur->prev=temp1;

}
void delete_at_begin()
{
	cur=head;
	head=head->next;
	head->prev=NULL;
	cur->next=NULL;
	printf("%d",(cur->data));
	free(cur);
}
void delete_at_end()
{
	cur=tail;
	tail=tail->prev;
	tail->next=NULL;
	cur->prev=NULL;
	printf("%d",(cur->data));
	free(cur);
}
void delete_at_pos()
{
	int pos;
	printf("Enter the position of deletion:\n");
	scanf("%d",&pos);
	int c=1;
	temp1=head;
	while(c<pos && temp1 !=NULL)
	{
		temp2=temp1;
		temp1=temp1->next;
		c++;
	}
	temp2->next=temp1->next;
	temp1->next->prev=temp2;
	temp1->prev=NULL;
	temp1->next=NULL;
	printf("The deleted data is %d",temp1->data);
	free(temp1);
}
void delete_before_node()
{
	int value;
	printf("Enter before which node we need to delete:\n");
	scanf("%d",&value);
	temp1=head;
	while(temp1->next->data!=value && temp1->next!=NULL)
	{
		temp2=temp1;
		temp1=temp1->next;
	}
	temp2->next=temp1->next;
	temp1->next->prev=temp2;
	temp1->prev=NULL;
	temp1->next=NULL;
	printf("%d",temp1->data);
	free(temp1);
	
}
void delete_after_node()
{
	int value;
	printf("Enter before which node we need to delete:\n");
	scanf("%d",&value);
	temp1=head;
	while(temp1!=NULL && temp1->data != value)	
	{
		temp1=temp1->next;
	}
	temp2=temp1->next;
	temp1->next=temp2->next;
	temp2->next->prev=temp1;
	printf("%d",temp2->data);
	free(temp2);
}
void display_forward()
{
	if(head==NULL)	
		printf("Double linked list is empty\n");
	else
	{
		cur=head;
		while(cur!=NULL)
		{
			printf("%d<->",cur->data);
			cur=cur->next;
		}
	}
}
void display_reverse()
{
	if(head==NULL)
		printf("Double linked list is empty\n");
	else
	{
		cur=tail;
		while(cur!=NULL)
		{
			printf("%d<->",cur->data);
			cur=cur->prev;
	    }
    }
}
void sorting()
{
	struct node *p1 , *p2,*last = NULL;
	int c,t;
	do
	{
		c=0;
		p1 = head;
		while(p1 -> next != last)
		{
			if(p1 -> data > p1->next->data)
			{
				t = p1 ->data;
				p1 -> data = p1 -> next ->data;
				p1 -> next-> data = t;	
				c = 1;			
			}
		p1 = p1-> next;	
		}
		last = p1;
	}while(c);
}
void search_for_element()
{
	int value,c=1,flag=0;
	printf("Enter the element to be searched:\n");
	scanf("%d",&value);
	temp1=head;
	while(temp1!=NULL)
	{
		if(temp1->data==value)
		{
			flag=1;
			break;
		}
		temp1=temp1->next;
		c++;
	}
	if(flag==1)
	{
		printf("Element present at %d position\n",c);
	}
	else
	{
		printf("Element not present\n");
	}
}
int main()
{
	int ch;
	while(1)
	{
		printf("Program for Double linked list\n");
		printf("------------------------------------------------------\n");
		printf("1:Creating a Double linked list\n");
		printf("2:Insert at begin\n");
		printf("3:insert at end\n");
		printf("4:Insert at position\n");
		printf("5:Insert before node\n");
		printf("6:Insert after node\n");
		printf("7:Delete at begin\n");
		printf("8:Delete at end\n");
		printf("9:Delete at position\n");
		printf("10:Delete before node\n");
		printf("11:Delete after node\n");
		printf("12:Display in forward direction\n");
		printf("13:Display in reverse direction\n");
		printf("14:Sorting of elements in double linked list\n");
		printf("15:searching for an element in double linked list\n");
		printf("16:Exit\n");
		printf("-------------------------------------------------------\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:create();
			break;
			case 2:insert_at_begin();
			break;
			case 3:insert_at_end();
			break;
			case 4:insert_at_pos();
			break;
			case 5:insert_before_node();
			break;
			case 6:insert_after_node();
			break;
			case 7:delete_at_begin();
			break;
			case 8:delete_at_end();
			break;
			case 9:delete_at_pos();
			break;
			case 10:delete_before_node();
			break;
			case 11:delete_after_node();
			break;
			case 12:display_forward();
			break;
			case 13:display_reverse();
			break;
			case 14:sorting();
			break;
			case 15:search_for_element();
			break;
			case 16:exit(0);
		
		}
		
	}
	return 0;
}




