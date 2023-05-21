#include<iostream>
using namespace std;

class ListNode{
        int data;          //info
        ListNode *next;    //address of next node
    public:
        ListNode(int data){
            this->data=data;
            this->next=nullptr;
        }
        void set_data(int data){
            this->data=data;
        }
        int get_data(){
            return data;
        }
        ListNode* get_next(){
            return next;
        }
        void set_next(ListNode *next){
            this->next=next;
        }
};

void traverse(ListNode *head){
    // ListNode *temp=head;
    if(head==NULL)
       return;

    while(head!=NULL){
        cout<<head->get_data()<<"->";
        head=head->get_next();
    }
}

int sizeOfLoop(ListNode *head){
    bool loop=false;
    ListNode *slow=head;
    ListNode *fast=head;
    while(fast!=NULL || slow!=NULL){
        slow=slow->get_next();
        fast=fast->get_next()->get_next();
        if(fast==slow){
            loop=true;
            break;
        }
    }
    ListNode *temp=slow;
    int count=1;
    while(temp->get_next()!=slow){
        temp=temp->get_next();
        count++;
    }
    return count;
}

int main(){
    ListNode *head=new ListNode(1);
    ListNode *node1=new ListNode(2);
    ListNode *node2=new ListNode(3);
    ListNode *node3=new ListNode(4);
    ListNode *node4=new ListNode(5);
    ListNode *node5=new ListNode(6);
    ListNode *node6=new ListNode(7);
    head->set_next(node1);
    node1->set_next(node2);
    node2->set_next(node3);
    node3->set_next(node4);
    node4->set_next(node5);
    node5->set_next(node6);
    node6->set_next(node2);
    cout<<sizeOfLoop(head);
}