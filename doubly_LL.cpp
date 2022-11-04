#include<bits/stdc++.h>
using namespace std;
struct dnode{
    struct dnode *prev;
    int data;
    struct dnode *next;
};
void d_append(struct dnode **, int);
void d_display(struct dnode *);
int d_count(struct dnode *);
void d_delete(struct dnode **, int);
void d_addatbeg(struct dnode **, int);
void d_addafter(struct dnode **, int, int);

int main(){
    struct dnode *p;
    p = NULL;
    cout<< "No. of element in doubly LL are: " << d_count(p) << endl;
    d_append(&p, 11);
    d_append(&p, 64);
    d_append(&p, 185);
    d_append(&p, 421);
    d_display(p);
    cout<< "No. of element in doubly LL are: " << d_count(p) << endl;
    d_addatbeg(&p, 1234);
    d_delete(&p, 185);
    d_delete(&p, 999);
    d_addafter(&p, 2, 91);
    d_display(p);
    cout<< "No. of element in doubly LL are: " << d_count(p) << endl;
    cout << "Sab sahi chalra h" << endl;
    return 0;
}

void d_addafter(struct dnode **s, int loc, int num){
    struct dnode *temp, *r;
    int i;
    temp = *s;
    // SKIP TO THE DESIRED ELEMENT
    for(i = 1; i<loc; i++){
        temp = temp->next;
        // ENTERED LOC IS NOT THERE
        if(temp==NULL){
 cout << "There are less than " << loc << " elements" << endl;
    return ;
        }
    }
    r = (struct dnode*)malloc(sizeof(struct dnode));
    r->data = num;
    r->prev = temp;
    r->next = temp->next;
    temp->next = r;
}

void d_addatbeg(struct dnode **s, int num){
    struct dnode *q;
    q = (struct dnode*)malloc(sizeof(struct dnode));
    q->data = num;
    q->prev = NULL;
    q->next = *s;
    (*s)->prev = q;
    *s = q;
}

void d_delete(struct dnode **s, int num){
    struct dnode *q = *s;
    while(q!=NULL){
        if(q->data==num){
            if(q==*s){
                *s = (*s)->next;// IF DELETED ITEM IS FIRST ELEMENT
                (*s)->prev = NULL;// NOT ONLY 1 ELEMENT
            }
            else{
                if(q->next==NULL){
                    q->prev->next = NULL;// IF DELETED ITEM IS LAST ELEMENT
                }
                else{
                    q->prev->next = q->next;
                    q->next->prev = q->prev;
                }
                free(q);
            }
            return;
        }
    q = q->next;
    }
    cout << num << " not found " << endl;
}

int d_count(struct dnode *s){
    int c = 0;
    while(s!=NULL){
        s = s->next;
        c++;
    }
    return c;
}

void d_append(struct dnode **s, int num){
    struct dnode *r, *q = *s;
    //if linked list is empty
    if(*s == NULL){
        *s = (struct dnode*)malloc(sizeof(struct dnode));
        (*s)->prev = NULL;
        (*s)->data = num;
        (*s)->next = NULL;
    }
    else{// traverse till the end
        while(q->next != NULL){
            q = q->next;
        }
        r = (struct dnode*)malloc(sizeof(struct dnode));
        r->data = num;
        r->next = NULL;
        r->prev = q;
        q->next = r;
    }
}

void d_display(struct dnode *s){
    while(s!=NULL){
        cout << s->data << " ";
        s = s->next;
    }
    cout << endl;
}
