#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *link;
};

int main() {
    void append(struct node **, int);
    void display(struct node *);
    // void addatbeg(struct node **, int);
    // void addafter(struct node **, int, int);
    int count(struct node *);
    void delete2(struct node **, int);
    
    struct node *p;
    p = NULL;
    cout << "No. of elements in Linked List = "<< count(p) << endl;
    display(p);
    append(&p, 23);
    append(&p, 99);
    append(&p, 0);
    append(&p, 42);
    append(&p, 2);
    cout << "No. of elements in Linked List = "<< count(p) << endl;
    display(p);
    delete2(&p, 42);
    delete2(&p, 23);
    delete2(&p, 999);
    cout << "After deleting 2 elements" << endl;
    cout << "No. of elements in Linked List = "<< count(p) << endl;
    display(p);
    return 0;
}
void delete2(struct node **q, int num){
    struct node *old, *temp;
    temp = *q;
    while(temp!=NULL){
        if(temp->data==num){
            if(temp==*q)
            {   *q = temp->link;   }
            else
            {   old->link = temp->link;  }
            free(temp);
            return ;
        }
        else{
            old=temp;
            temp = temp->link;
        }
    }
    cout << "Element "<< num << " not found" << endl;
}
void display(struct node *q){
    if(q==NULL)
    cout << "Linked list is empty";
    while(q!=NULL){
        cout << q->data << " ";
        q = q->link;
    }cout << endl;
}
void append(struct node **q, int num){
    struct node *temp, *r;
    if(*q==NULL){
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = num;
        temp->link = NULL;
        *q=temp;
    }
    else{
        temp = *q;
        while(temp->link != NULL){
            temp = temp->link;
        }
        r = (struct node *)malloc(sizeof(struct node));
        r->data = num;
        r->link = NULL;
        temp->link = r;
    }
}
    int count(struct node *q){
        int c = 0;
        while(q != NULL){
            c++;
            q = q->link;
        }
        return c;
    }