#include <stdio.h>
#include <stdlib.h>
#define maxVol 16
/*
this is stack done by c and used array to implement
int Stack[maxVol];

typedef struct stack {
    int top;
    int data[maxVol];
}stack;
void push(stack *s, int n){
    if(s->top<maxVol-1)s->data[++s->top]=n;
    else printf("fail!");
}
int pop(stack *s ){
    if(s->top != -1)return s->data[s->top--];
    else {
    printf("fail!");
    return 0;}
}
int get_size(stack *s){
    return s->top+1;
}
int main(void){
    stack st;
    st.top=-1;
    pop(&st);
    push(&st,1);
    push(&st,2);
    push(&st,3);
    push(&st,4);
    printf("size now is %d\n",get_size(&st));
    push(&st,1);push(&st,2);push(&st,3);push(&st,4);
    push(&st,1);push(&st,2);push(&st,3);push(&st,4);
    push(&st,1);push(&st,2);push(&st,3);push(&st,4);
    printf("size now is %d\n",get_size(&st));
    push(&st , 200);
    // pop(&st);
    for(int i=0;i<st.top+1;i++){
        printf("%d",st.data[i]);
    }
}
/*this is stack done by c and used array to implement*/

typedef struct node{
    int top;
    struct node *next;
}node;


void push(node **head , int n){
    node *newnode = (node *)malloc(sizeof(node));
    newnode->top = n;
    newnode->next = *head;
    *head = newnode;
}
int pop(node **head){
    if(*head==NULL)return -1;
    int n = (*head)->top;
    node *ptr = *head;
    *head = (*head)->next;
    free(ptr);
    return n ;
}
void print_stack(node *nd){
    node *tmp = nd;
    while(tmp!=NULL){
        printf("%d\t",tmp->top);
        tmp = tmp->next;
    }

}

int main(int argc , char* argv[]){
    node *st1=NULL,*st2=NULL;
    push(&st1,1);
    push(&st1,2);
    push(&st2,3);
    push(&st2,4);
    pop(&st1);
    print_stack(st1);
    printf("\n");
    print_stack(st2);
    
}

