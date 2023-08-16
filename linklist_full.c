#include<stdio.h>
#include<stdlib.h>

void main()
{
	struct node{
		int data;
		struct node *next;	
	};
	struct node *head,*temp,*tail,*del,*bel;
	int item,num,flag,f,g,h;
void choice()
{
		void display()
		{
			printf("After inserting:\n");
		    if (head == NULL) 
			{
		        printf("Node empty\n");
		    }
		    else 
				{
			        temp=head;
			        while (temp != NULL) {
			                
			                item = temp->data;
			                
			                printf("%d \n", item);
			                temp = temp->next;
			        }
				}
	
		}
	void insert()
	{
		void atbeg()
		{
			if(head==NULL)
			{
				printf("Inserting First node \n");
				head = (struct node*)malloc(sizeof(struct node));
				printf("enter the data \n");
				scanf("%d",&item);
				head->data=item;
				head->next= NULL;
			}
			else
			{   
		        struct node *ptr = (struct node*)malloc(sizeof(struct node));
				printf("Inserting at first pos \n");
				printf("enter the data \n");
				scanf("%d",&item);
				ptr->data=item;
				ptr->next=head;
				head=ptr;
	        
			}
		}
		void atend()
		{
			if(head==NULL)
			{
				printf("your link is empty\n");
				atbeg();	
			}
			else
			{
				struct node *last = (struct node*)malloc(sizeof(struct node));
				printf("Inserting at last pos \n");
				printf("enter the data \n");
				scanf("%d",&item);
				last->data=item;
				last->next=NULL;
				
				temp=head;
		
	        	while (temp->next != NULL)
	        	{
	                temp = temp->next;
	        	}
				temp->next=last;
			}
		}
		void atpos()
		{
			if(head==NULL)
				{
					printf("your link is empty\n");
					atbeg();	
				}
			else
			{
				struct node *pos = (struct node*)malloc(sizeof(struct node));
				printf("Enter the positin u want to enter\n");
				scanf("%d",&flag);
				printf("Inserting at pos %d \n",flag);
				printf("enter the data \n");
				scanf("%d",&item);
				pos->data=item;
				temp=head;
				int i=0;
				while(i!=flag-1)
				{
					temp = temp->next;
					++i;	
				}
				pos->next=temp->next;
				temp->next=pos;
				
			}
		}
		while(1)
		{
			printf("choose--> 1 to Inserting First node\n");
			printf("choose--> 2 to Inserting at last pos\n");
			printf("choose--> 3 to Inserting at pos\n");
			printf("choose--> 4 to display\n");
			printf("choose--> 5 to return home menu\n");
			scanf("%d",&g);
			switch(g)
			{
				case 1: atbeg();
				break;
				case 2: atend();
				break;
				case 3: atpos();
				break;
				case 4: display();
				break;
				case 5: choice();
				break;
				default: printf("Check your choosed option\n");
				break;
			}
		}
				
	}
	void delet()
	{
		void delbeg()
		{
			if(head==NULL)
			{
				printf("your link is empty\n");
				choice();
			}
			else
			{
				head=head->next;
			}
		}
		void delend()
		{
			if(head==NULL)
			{
				printf("your link is empty\n");
				choice();
			}
			else
			{
				temp=head;
				tail=NULL;
	        	while (temp->next != NULL)
	        	{
	        		tail=temp;
	                temp = temp->next;
	        	}
				tail->next=NULL;
			}
		}
		void delpos()
		{
			if(head==NULL)
			{
				printf("your link is empty\n");
			    choice();
			}
			else
			{
				printf("Enter the positin u want to delete\n");
				scanf("%d",&flag);
				temp=head;
				del=NULL;
				int i=0;
				while(i<flag-1)
				{
					del=temp;
					temp = temp->next;
					++i;	
				}
				del->next=temp->next;	
			}
				
		}
		while(1)
		{
			printf("choose--> 1 to Deleting First node\n");
			printf("choose--> 2 to Deleting End node\n");
			printf("choose--> 3 to Deleting from chossen position node\n");
			printf("choose--> 4 to Display\n");
			printf("choose--> 5 to return home menu\n");
			scanf("%d",&h);
			switch(h)
			{
				case 1: delbeg();
				break;
				case 2: delend();
				break;
				case 3: delpos();
				break;
				case 4: display();
				break;
				case 5: choice();
				break;
				default: printf("you enter wrong option\n");
				break;
			}
		}
		
	}
	void search()
		{
			int num;
			if(head==NULL)
			{
				printf("your link is empty\n");
				choice();
			}
			else
			{
				printf("Enter the data for searching");
				scanf("%d",&num);
				temp=head;
				int i=0;
	        	while (temp->next != NULL)
	        	{
	        		if(temp->data==num)
	        		{
	        			printf("%d found in %d position in %d times\n",num,i);
	        			break;
					}
	                temp = temp->next;
	                i++;
				}
	        	if(f=0)
				{
					printf("value not found\n");	
				}	
			}	
		}
//	void sorting()
//	{
//		int small,num;
//		temp=head;
//		small=temp->data;
//		while(temp->next!=NULL)
//		{
//			temp = temp->next;
//			num=temp->data;
//			if(small>num)
//			{
//				
//			}
//		}
//	}
	while(1)
	{
		printf("press--->1 to insert\n");
		printf("press-->2 to delete\n");
		printf("press-->3 to display\n");
		printf("press-->4 to search\n");
		scanf("%d",&f);
		switch(f)
		{
			case 1: insert();
			break;
			case 2:delet();
			break;
			case 3: display();
			break;
			case 4: search();
			break;
			default: printf("Check your choosed option\n");
			break;
		}
	}
}
choice();	
} 
