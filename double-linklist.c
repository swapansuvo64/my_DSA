#include<stdio.h>
#include<stdlib.h>

void main()
{
	struct node
	{
		int data;
		struct node *next;
		struct node *prev;
	};
	struct node *head,*temp,*tail,*ptr;
	head=NULL;
	int num,f,pos;
	

	void atbegin()
	{
		if(head == NULL)
		{
			printf("Inserting 1st node\n");
			head=(struct node*)malloc(sizeof(struct node));
			printf("Enter your data\n");
			scanf("%d",&num);
			head->data=num;
			head->next=NULL;
			head->prev=NULL;
		}
		else
		{
			printf("Inserting at begining\n");
			ptr=(struct node*)malloc(sizeof(struct node));
			printf("Enter your data\n");
			scanf("%d",&num);
			ptr->next=head;
			ptr->prev=NULL;
			ptr->data=num;
			head->prev=ptr;
			head=ptr;
			ptr=NULL;
		}
	}
	void atendin()
	{
		if(head == NULL)
		{
			printf("node empty\n");
		}
		else
		{
			printf("Inserting at end\n");
			tail=(struct node*)malloc(sizeof(struct node));	
			printf("Enter data to insert t end\n");
			scanf("%d",&num);
			tail->data=num;
			tail->next=NULL;
			temp=head;
			while(temp->next != NULL)
			{
				temp=temp->next;
			}
			temp->next=tail;
			tail->prev=temp;
		}
	}
	void atposin()
	{
				
		if(head == NULL)
		{
			printf("node empty\n");
		}
		else
		{
			printf("inserting at position\n");
			ptr=(struct node*)malloc(sizeof(struct node));
			printf("Enter your position\n");
			scanf("%d",&pos);	
			printf("Enter your data\n");
			scanf("%d",&num);
			ptr->data=num;
			int i=0;
			temp=head;
			while(i!=pos-1)
			{
				temp=temp->next;
				++i;
			}
			ptr->next=temp->next;
			temp->next=ptr;
			ptr->prev=temp;
			temp->next->prev = ptr;
		}
		
		
	}
	void display()
	{
		int item;
		printf("After inserting : \n");
		if(head == NULL)
		{
			printf("node empty\n");
		}
		else
		{
			temp=head;
			while(temp != NULL)
			{
				item=temp->data;
				printf("%d\n",item);
				temp=temp->next;
			}
		}
	}
	

	while(1)
	{
		printf("Press--->1 to insert at first\n");
		printf("Press--->2 to insert at end\n");
		printf("Press--->3 to insert at pos\n");
		printf("Press--->7 to display\n");
		printf("Press--->8 to exit\n");
		scanf("%d",&f);
		switch(f)
		{
			case 1: atbegin();
			break;
			case 2: atendin();
			break;
			case 3: atposin();
			break;
			case 7: display();
			break;
			case 8: exit(0);
			break;
			default : printf("wrong option\n");
			break;
		}
	}

}