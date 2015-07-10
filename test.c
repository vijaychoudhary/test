#include <stdio.h>
#include <stdlib.h>


typedef struct stack
{
    
    int stk;
    struct stack *top;
    struct stack *pre;
};
typedef struct stack ST;
ST *head;
ST *tail;
ST *temp;
int value;

void push();
void  pop();
void display();
void main ()
{
int choice;
	int stk;
	
	while(1) {
		printf("What do you want to do?\n\n");
		printf("1. Push \n2. Pop \n3. display \n4. Exit\n");
		scanf("%d", &choice);
		
		switch(choice) {
			case 1:
				printf("\nEnter the value you want to insert!\n");
				scanf("%d", &stk);
				push(stk);
				printf("\nInserted the value %d into Stack\n", stk); 
				break;
			case 2:
				
				 pop();
				 //need to fetch real value
				break;
			case 3:
				
				display();
                break;
           case 4:
                   printf("\nExiting...\n"); 
                  exit(0);   
			default:
				break;
		}
	}
}

void push (stk)
{
   
   ST *var;
     var=( ST *)malloc(sizeof(ST));
     var->stk=stk;
     if(head==NULL)
        {
          head=var;
          head->pre=NULL;
          head->top=NULL;
          tail=head;
        }
     else
        {
         temp=tail;
         tail=tail->top;
         tail=var;
         temp->top=tail;
         tail->pre=temp;
         tail->top=NULL;
         }

}

void pop ()
{
    
if(head == NULL) {
		printf("Stack is empty\n");
        return;
	}
    else
        {
		
	ST *p = tail;
    tail=tail->pre;
    value=p->stk;
    p->stk=NULL;
    free(p);
    printf("\npoped value is %d\n",value);
    }
}

void display ()
{
  
 ST *im;
 im=tail;
 while(im!=NULL)
 {
     printf(" %d\n",im->stk);
     im=im->pre;
 }
   
}
    