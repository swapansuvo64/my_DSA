#include<stdio.h>
#include<string.h>
void main()
{
	char eqs[] = "x+y/k-r+t",stack[2];
	int len = strlen(eqs),top=-1,i;
	//printf("%d",len);
	for(i=0;i<len;i++)
	{
		if(eqs[i] == '+' || eqs[i] == '-' || eqs[i] == '/' || eqs[i] == '*')
		{
			if(top == -1)
			{
				++top;
				stack[top] = eqs[i];
			}
			else                 
			//	printf("top = %c ",stack[top]);
			{
				if((stack[top] == '+' || stack[top] == '-') && (eqs[i] == '*' || eqs[i] == '/'))
				{
					++top;
					stack[top] = eqs[i];
				}
				else if( (stack[top] == '*' || stack[top] == '/') && (eqs[i] == '-' || eqs[i] == '+') )
				{
					printf("%c",stack[top]);
					--top;
					if((top >= 0) && (stack[top] == '+' || stack[top] == '-'))
					{
						printf("%c",stack[top]);
						stack[top]=eqs[i];
					}
					else{
						++top;
						stack[top]=eqs[i];
					}
				}
				else if((stack[top] == '*' || stack[top] == '/') && (eqs[i] == '*' || eqs[i] == '/'))
				{
					printf("%c",stack[top]);
					stack[top]=eqs[i];
				}
				else if((stack[top] == '+' || stack[top] == '-') && (eqs[i] == '+' || eqs[i] == '-'))
				{
					printf("%c",stack[top]);
					stack[top]=eqs[i];
				}
			}
		}
		else
		{
			printf("%c",eqs[i]);
		}
	}
	if(top>=0)
	{	
		for(i=top;i>=0;i--)
		{
			printf("%c",stack[i]);
		}
	}
}