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

ListNode* delete_node(ListNode *head,int k){
    if(k<0){
        cout<<"Invalid K value";
        return nullptr;
    }
    if(k==0){
        head=head->get_next();
    }
    else{
        ListNode *temp=head;
        int count=1;
        while(count<k){
            temp=temp->get_next();
            count++;
        }
        //node to be deleted;
        ListNode *next=temp->get_next()->get_next();
        temp->set_next(next);
    }
    return head;
}


int main(){
    ListNode *head=new ListNode(1);
    ListNode *node1=new ListNode(2);
    ListNode *node2=new ListNode(3);
    ListNode *node3=new ListNode(4);
    head->set_next(node1);
    node1->set_next(node2);
    node2->set_next(node3);
    traverse(head);
    cout<<endl;
    head=delete_node(head,1);
    traverse(head);
    return 0;
}