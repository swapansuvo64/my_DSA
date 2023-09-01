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
	struct node *head,*temp,*tail,*ptr,*del,*small;
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
	void atbegdel()
	{
		if(head == NULL)
		{
			printf("node empty\n");
		}
		else
		{
			head=head->next;//head->next=temp;temp=head;temp->prev=NULL;
			head->prev=NULL;
		}	
	}	
	void atenddel()
	{
		if(head == NULL)
		{
			printf("node empty\n");
		}
		else
		{
			tail=(struct node*)malloc(sizeof(struct node));	
			tail=NULL;
			temp=head;
			while(temp->next != NULL)
			{
				temp=temp->next;
				
			}
			tail=temp->prev;
			tail->next=NULL;
			
		}	
	}
	void atposdel()
	{
		if(head == NULL)
		{
			printf("node empty\n");
		}
		else
		{
			del=(struct node*)malloc(sizeof(struct node));	
			printf("Enter your position\n");
			scanf("%d",&pos);
			int i=0;
			temp=head;
			while(i!=pos)
			{
				del=temp;
				temp=temp->next;
				++i;
			}
			del->prev->next=temp;
			temp->prev=del->prev;
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
	void displayrev()
	{
		int item;
		printf("After inserting : \n");
		if(head == NULL)
		{
			printf("node empty\n");
		}
		else
		{
//			temp=head;
//			while(temp->next != NULL)
//			{
//				item=temp->data;
//				printf("%d\n",item);
//				temp=temp->next;
//			}
//			printf("%d\n",temp->data);
			temp=tail;
			while(temp->prev!=NULL)
			{
				item=temp->data;
				printf("%d\n",item);
				temp=temp->prev;
			}
			printf("%d\n",temp->data);
		}
	}
	void sort()
	{
		int swap;
		if(head == NULL)
		{
			printf("node empty\n");
		}
		else
		{
			temp=head;
			while(temp != NULL)
			{
				small=temp;
				while(small != NULL)
				{
					if(temp->data>small->data)
					{
						swap=small->data;
						small->data=temp->data;
						temp->data=swap;
					}
					small=small->next;
				}
				temp=temp->next;
			}	
		}	
	}
//	binary()
//	{
//		
//	}

	while(1)
	{
		printf("Press--->1 to insert at first\n");
		printf("Press--->2 to insert at end\n");
		printf("Press--->3 to insert at pos\n");
		printf("Press--->4 to delete at first\n");
		printf("Press--->5 to delete at end\n");
		printf("Press--->6 to delete at pos\n");
		printf("Press--->7 to display\n");
		printf("Press--->8 to display at rev order\n");
		printf("Press--->9 to sort\n");
		printf("Press--->10 to Binary-search\n");
		printf("Press--->11 to exit\n");
		scanf("%d",&f);
		switch(f)
		{
			case 1: atbegin();
			break;
			case 2: atendin();
			break;
			case 3: atposin();
			break;
			case 4: atbegdel();
			break;
			case 5: atenddel();
			break;
			case 6: atposdel();
			break;
			case 7: display();
			break;
			case 8: displayrev();
			break;
			case 9: sort();
			break;
//			case 10: binary();
//			break;
			case 11: exit(0);
			break;
			default : printf("wrong option\n");
			break;
		}
	}

}