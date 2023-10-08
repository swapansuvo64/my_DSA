#include<stdio.h>
#include<stdlib.h>

void main()
{
	struct node{
		int data;
		struct node *left;
		struct node *right;	
	};
	struct node *root,*temp,*lef,*rig,*ptr;
	int item,num,flag,f,g,h,r;
	root=NULL;
	struct node* newnode(int item)
	{
		ptr=(struct node*)malloc(sizeof(struct node));
		ptr->data=item;
		ptr->left=NULL;
		ptr->right=NULL;
		return ptr;
	}
void pre(struct node* root) {
    if (root != NULL) {
    	
    	if(r==root->data)
    	{
    		printf("%d <-Root\n", root->data);
		}
		else{
			printf("%d\n", root->data);
		}
        pre(root->left);
        pre(root->right);
    }
}

void in(struct node* root) {
    if (root != NULL) {
        in(root->left);
        if(r==root->data)
    	{
    		printf("%d <-Root\n", root->data);
		}
		else{
			printf("%d\n", root->data);
		}
        in(root->right);
    }
}

void post(struct node* root) {
    if (root != NULL) {
        post(root->left);
        post(root->right);
        if(r==root->data)
    	{
    		printf("%d <-Root\n", root->data);
		}
		else{
			printf("%d\n", root->data);
		}
    }
}	
struct node* display(struct node* root)
	{
			printf("\nPress 1 to pre-order\nPress 2 to in order\n Press 3 to post-order\n");
			scanf("%d",&f);
			switch(f)
			{
				case 1: 
						pre(root);
				break;
				case 2: in(root);
				break;
				case 3: post(root);
				break;
			}

	}
struct node* search(struct node* lef, int num) {
    if (lef != NULL) {
        if (lef->data == num) {
//            printf("%d\n", lef->data);
            return lef;
        }
        struct node* result = search(lef->left, num);
        if (result == NULL) {
            result = search(lef->right, num);
        }
        return result;
    }
    return NULL;
}
	void insert()
	{
			printf("Enter the value where u want to put childs\n");
			scanf("%d",&num);
			temp=search(root,num);
			if(num==temp->data)
			{
				printf("\nnode found\n");
				printf("\npress 1 for left child\n press 2 for right chile\n");
				scanf("%d",&f);
				if(f==1)
				{
					printf("\nEnter data to insert: ");
					scanf("%d",&item);
					temp->left=newnode(item);	
//					printf("%d",temp->left->data);
				}	
				else if(f==2)
				{
					printf("\nEnter data to insert: ");
					scanf("%d",&g);
					temp->right=newnode(g);	
//					printf("%d",temp->right->data);
				}
			}	
	}
	while(1)
	{
		if(root==NULL)
		{
			printf("\nTree is empty\n");
			printf("Creating new tree\n");
			int item;
			printf("Enter the vale\n");
			scanf("%d",&item);
			r=item;
			root=newnode(item);
		}
	else
		{
				printf("\npress 1 for insert\n press 2 for display\n");
				scanf("%d",&f);
				switch(f)
				{
					case 1: insert();
					break;
					case 2: display(root);
					break;
				}
		}
		
	}
		

	
}