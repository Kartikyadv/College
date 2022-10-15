#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *link;
};
// ADDITION IS DONE AT THE END
// DELETION IS DONE AT THE BEGINING
    void addcirq(struct node **, struct node **, int);
    int delcirq(struct node**, struct node **);
    void cirq_display(struct node *);
    
int main() {
    
    struct node *front, *rear;
    front = rear = NULL;
    addcirq(&front, &rear, 10);
    addcirq(&front, &rear, 43);
    addcirq(&front, &rear, 99);
    addcirq(&front, &rear, 134);
    addcirq(&front, &rear, 634);
    cout << "Before Deletion" << endl;
    cirq_display(front);
    delcirq(&front, &rear);
    delcirq(&front, &rear);
    cout << "After Deletion" << endl;
    cirq_display(front);
    return 0;
}
int delcirq(struct node **f, struct node **r){
    struct node *q;
    int item;
    if(*f==NULL) cout << "Queue is Empty" << endl;
    else{
        if(*f==*r){//ONLY 1 ELEMENT
            item = (*f)->data;
            free(*f);
            *f=NULL;
            *r=NULL;
        }
        else{// MORE THAN 1 ELEMENT
            q=*f;
            item = q->data;
            *f = (*f)->link;
            (*r)->link = *f;
            free(q);
        }
        return item;
    }
    return NULL;
}
void addcirq(struct node **f, struct node **r, int item){
    struct node *q;
    q = (struct node *)malloc(sizeof(struct node));
    q->data = item;
    if(*f==NULL)
    {*f=q;}
    else
    {(*r)->link=q;}// AGR ELSE HATADIA TOH ONLY 1 ELEMENT WILL BE INSERTED THEN IT WILL STOP
    *r=q;
    (*r)->link = *f;
}
void cirq_display(struct node *f){
    if(f==NULL)
    cout << "Circular Queue is Empty" << endl;
    struct node *q = f, *p = NULL;
    while(q!=p)
    {
        cout << q->data << " ";
        q = q->link;
        p = f;
    }
    cout << endl;
}

