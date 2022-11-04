#include<stdio.h>
#include<conio.h>
#define MAX 5
struct stack{
int arr[MAX];
int top;
};
void initstack(struct stack*);
void push(struct stack*, int);
void display(struct stack*);
int pop(struct stack*);

void main(){
struct stack s;
int i;
clrscr();
initstack(&s);
push(&s,11);
push(&s,67);
push(&s,99);
push(&s,-1);
display(&s);
i = pop(&s);
printf("Item popped = %d\n", i);
display(&s);
getch();
}

int pop(struct stack *s){
int data;
if(s->top==-1){
printf("Stack is empty\n");
return NULL;
}
data = s->arr[s->top];
s->top--;
return data;
}

void display(struct stack *s){
int x = s->top;
if(s->top==-1){
    printf("stack is Empty\n");
}
while(x > -1){
int item;
item =  s->arr[x];
printf("%4d\n", item);
x--;
}
}


void push(struct stack *s, int item){
if(s->top==MAX-1){
printf("Stack is full\n");
return ;
}
s->top++;
s->arr[s->top] = item;
}
void initstack(struct stack *s){
s->top = -1;
}