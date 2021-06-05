#include<stdio.h>
#define maxstack 10
typedef struct stack{
	int data[maxstack];
	int top;
}stack;
void push(stack *,int);
int pop(stack *);
int peep(stack);
void display(stack);
int main()
{
	stack s1;
	s1.top=-1;
	int ch,item;
	do
	{
		printf("\n1. Push\n2. Pop\n3. Peep\n4. Display\n5. Exit\nEnter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the item you want to push\n");
				scanf("%d",&item);
				push(&s1,item);
				break;
			case 2:
				item=pop(&s1);
				if(item!=-1)
				{
					printf("The popped item is %d\n",item);
				}
				break;
			case 3:
				item=peep(s1);
				if(item!=-1)
				{
					printf("The pepped item is %d\n",item);
				}
				break;
			case 4:
				display(s1);
				break;
		}
	}while(ch!=5);
	return 0;
}
void push(stack *s1,int item)
{
	if(s1->top==maxstack-1)
		printf("Stack is full OR Overflow\n");
	s1->top++;
	s1->data[s1->top]=item;
	return;
}
int pop(stack *s1)
{
	int item;
	if(s1->top==-1)
	{
		printf("Stack is empty OR Underflow\n");	
		return -1;
	}	
	else
	{
		item=s1->data[s1->top];
		s1->top--;
		return item;
	}	
}
int peep(stack s1)
{
	int item;
	if(s1.top==-1)
	{
		printf("The stack is empty\n");
		return -1;
	}
	else
	{
		item=s1.data[s1.top];
		return item;
	}	
}
void display(stack s1)
{
	if(s1.top==-1)
	{
		printf("Stack is empty\n");
		return;
	}
		
	int i=0;
	printf("Stack is: \n");
	for(i=s1.top;i>=0;i--)
	{
		printf("%d\t",s1.data[i]);
	}
	printf("\n");
	return;
}
