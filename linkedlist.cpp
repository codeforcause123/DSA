#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }
};

void insertatTail(node* &head,int val){

    node* n = new node(val);

    if(head==NULL){
        head=n;
        return;
    }
    node* temp = head;
    while(temp->next != NULL){
        temp=temp->next;
    }
    temp->next=n;

}

void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

void insertatHead(node* &head,int val){

    node* n = new node(val);
    n->next=head;
    head=n;
}
void insertatPos(node *&head,int pos,int val){
    node *n = new node(val);
    node *temp=head;
    if(pos==1){
        n->next=temp;
        head=n;
        return;
    }
    for(int i=1;i<pos-1;i++){
        temp=temp->next;
    }
    n->next=temp->next;
    temp->next=n;
}

bool search(node* head,int key){
    node* temp = head;
    while(temp!=NULL){
        if(temp->data==key){
            return true;
        }
        temp=temp->next;
    }
    return false;

}
void deleteatHead(node* &head){
    if(head==NULL){
        return;
    }
    node* todelete=head;
    head=head->next;

    delete todelete;
}
void deletion(node* &head,int val){

    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        deleteatHead(head);
        return;
    }
    node* temp=head;
    while(temp->next->data!=val){
        temp=temp->next;
    }
    node* todelete = temp->next;
    temp->next=temp->next->next;

    delete todelete;
}
node *reverse(node *&head){
    node *prevptr=NULL;
    node *currptr=head;
    node *nextptr;

    while(currptr!=NULL){
        nextptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
    }
    return prevptr;
}
node* reverseRecursive(node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    node* newhead = reverseRecursive(head->next);
    head->next->next=head;
    head->next=NULL;

    return newhead;
}

node* reversek(node* &head,int k){
    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr; 
     
    int count=0;
    while(currptr!=NULL && count<k){
        nextptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
        count++;
    }
    if(nextptr!=NULL){
        head->next=reversek(nextptr,k);
    }
    return prevptr;
    
}
void makecycle(node *&head,int pos){
    node *temp=head;
    node *startNode;

    int count=1;
    while(temp->next!=NULL){
        if(count==pos){
            startNode=temp;
        }
        temp=temp->next;
        count++;
    }
    temp->next=startNode;
}
bool detectCycle(node *&head){
    node *slow=head;
    node *fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow){
            return 1;
        }
    }
    return false;
}
void removeCycle(node *&head){
    node *slow=head;
    node *fast=head;
    do
    {
        slow=slow->next;
        fast=fast->next->next;
    } while (slow!=fast);
    fast=head;
    while(slow->next!=fast->next){
        slow=slow->next;
        fast=fast->next;
    }
    slow->next=NULL;
}
int length(node *head){
    int l=0;
    node *temp=head;
    while(temp!=NULL){
        l++;
        temp=temp->next;
    }
    return l;
}
node *kappend(node *&head,int k){
    node *newhead;
    node *newtail;
    node *tail=head;
    int l=length(head);
    k=k%l;
    int count=1;
    while(tail->next!=NULL){
        if(count==l-k){
            newtail=tail;
        }
        if(count==l-k+1){
            newhead=tail;
        }
        tail=tail->next;
        count++;
    }
    newtail->next=NULL;
    tail->next=head;
    return newhead;

}
void intersect(node *&head1,node *&head2,int pos){
    node *temp1=head1;
    while(pos--){
        temp1=temp1->next;
    }
    node *temp2=head2;
    while(temp2->next!=NULL){
        temp2=temp2->next;
    }
    temp2->next=temp1;
}
int checkinstersection(node *&head1,node *&head2){
    int l1=length(head1);
    int l2=length(head2);
    int d=0;
    node *ptr1;
    node *ptr2;
    if(l1>l2){
        d=l1-l2;
        ptr1=head1;
        ptr2=head2;
    }
    else{
        d=l2-l1;
        ptr1=head2;
        ptr2=head1;
    }
    while(d--){
        ptr1=ptr1->next;
        if(ptr1==NULL){
            return -1;
        }
    }
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1==ptr2){
            return ptr1->data;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return -1;
}
node *merge(node *&head1,node *&head2){
    node *p1=head1;
    node *p2=head2;
    node *dummy=new node(-1);
    node *p3=dummy;
    while(p1!=NULL && p2!=NULL){
        if(p1->data<p2->data){
            p3->next=p1;
            p1=p1->next;
        }
        else{
            p3->next=p2;
            p2=p2->next;
        }
        p3=p3->next;
    }
    while(p1!=NULL){
        p3->next=p1;
        p1=p1->next;
        p3=p3->next;
    }
    while(p2!=NULL){
        p3->next=p2;
        p2=p2->next;
        p3=p3->next;
    }
    return dummy->next;
    
}
node *mergeRecursive(node *&head1,node *&head2){

    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }

    node *result;
    if(head1->data<head2->data){
        result=head1;
        result->next=mergeRecursive(head1->next,head2);
    }
    else{
        result=head2;
        result->next=mergeRecursive(head1,head2->next);
    }
    return result;
}
void evenafterodd(node *&head){
    node *odd=head;
    node *even=head->next;
    node *evenstart=even;
    while(odd->next!=NULL && even->next!=NULL){
        odd->next=even->next;
        odd=odd->next;
        even->next=odd->next;
        even=even->next;
    }
    odd->next=evenstart;
    if(odd->next==NULL){
        even->next=NULL;
    }
}
int main(){

    node *head1=NULL;
    node *head2=NULL;
    insertatTail(head1,1);
    insertatTail(head1,6);
    insertatTail(head1,4);
    insertatTail(head1,8);
    insertatTail(head1,3);
    insertatTail(head1,5);
    insertatTail(head1,7);
    evenafterodd(head1);
    display(head1);
    // insertatTail(head2,4);
    // insertatTail(head2,6);
    // display(head1);
    // display(head2);
    // node *mergehead=mergeRecursive(head1,head2);
    // display(mergehead);
    // evenafterodd(head1);
    // display(head1);
    // intersect(head1,head2,3);
    // display(head1);
    // display(head2);
    // cout<<checkinstersection(head1,head2)<<endl;

    // node *nhead=kappend(head,5);
    // display(nhead);
    // //cout<<search(head,3)<<endl;
    // //deletion(head,3);
    // //deleteatHead(head);
    // //display(head);
    // // node* newhead = reverse(head);
    // // display(newhead);
    // // node* newhead = reverseRecursive(head);
    // // display(newhead);
    // makecycle(head,2);
    // cout<<detectCycle(head)<<endl;
    // removeCycle(head);
    // cout<<detectCycle(head)<<endl;
    // display(head);
    // //display(head);
    return 0;
}