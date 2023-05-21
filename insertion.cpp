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
class LinkedList{
        ListNode *head;
    public:
        LinkedList(){
            this->head=nullptr;
        }
        void insert(int data){
            ListNode *newNode=new ListNode(data);

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

void insertAtK(ListNode *head,int item,int k){
    ListNode *newNode=new ListNode(item);
    
    if(k==0){
        ListNode *newNode=new ListNode(item);
        newNode->set_next(head);
        head=newNode;
        return;
    }
    //Finding the node at k-1 position
    ListNode *temp=head;
    int count=1;
    while(count<k){
        temp=temp->get_next();
        count++;
    }
    //Now temp will be at k-1 position
    newNode->set_next(temp->get_next());
    temp->set_next(newNode);
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
    insertAtK(head,5,0);
    traverse(head);
    return 0;
}