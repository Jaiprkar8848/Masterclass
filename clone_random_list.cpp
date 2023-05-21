#include<iostream>
using namespace std;

class ListNode{
    public:
        int data;          //info
        ListNode *next;    //address of next node
        ListNode *random;  //random pointer
        ListNode(int data){
            this->data=data;
            this->next=nullptr;
            this->random=nullptr;
        }
        // void set_data(int data){
        //     this->data=data;
        // }
        // int get_data(){
        //     return data;
        // }
        // ListNode* get_next(){
        //     return next;
        // }
        // void set_next(ListNode *next){
        //     this->next=next;
        // }
};

ListNode* copyRandomList(ListNode *head){
    if(head==NULL){
        return NULL;
    }

    //Create duplicates of each node and Insert after original node
    ListNode *temp=head;
    while(temp!=NULL){
        ListNode *newNode=new ListNode(temp->data);
        newNode->next=temp->next;
        temp->next=newNode;
        temp=newNode->next;
    }

    //Set random pointer of duplicate nodes as clone to the originals
    ListNode *tempOriginal=head;
    ListNode *tempDuplicate=head->next;
    while(tempOriginal!=NULL){

        if(tempOriginal->random==NULL)
            tempDuplicate->random=NULL;
        else
            tempDuplicate->random=tempOriginal->random->next;

        tempOriginal=tempDuplicate->next;

        if(tempOriginal==NULL)
            tempDuplicate=NULL;
        else
            tempDuplicate=tempOriginal->next;
    }

    //Extract original nodes from list 
    ListNode *node=head;
    ListNode *result=head->next;
    ListNode *tempRes=head->next;
    while(node!=NULL){
        node->next=tempRes->next;
        if(node->next==NULL)
            tempRes->next=NULL;
        else
            tempRes->next=node->next->next;
        
        node=node->next;
        tempRes=tempRes->next;
    }
    return result;
}
void traverse(ListNode *head){
    // ListNode *temp=head;
    if(head==NULL)
       return;

    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }
}


int main(){
    ListNode *head=new ListNode(1);
    ListNode *node1=new ListNode(2);
    ListNode *node2=new ListNode(3);
    ListNode *node3=new ListNode(4);
    head->next=node1;
    head->random=node2;
    node1->next=node2;
    node1->random=head;
    node2->next=node3;
    node2->random=node3;
    node3->next=NULL;
    node3->random=node1;
    traverse(head);
    cout<<endl;
    copyRandomList(head);
    traverse(head);
}