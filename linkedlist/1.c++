#include<iostream>
using namespace std;


class Node{
    public:
    int data;
    Node* next;

    Node(){
       // cout<<"in constructor"<<endl;
        this->next=NULL;
    }
    Node(int data){
      //  cout<<"data constructor"<<endl;
        this->data=data;
        this->next=NULL;
    }
    ~Node(){
        cout<<"in destructor"<<this->data<<endl;
    }
};

void printL(Node * head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int getlength(Node*head){
    Node*temp=head;
    int count=0;
    while(temp->next!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}
void insertAthead(Node *& head,Node *& tail,int data){//always pass by reference while inserting
   if(head==NULL){
    Node *newNode=new Node(data);
    head=newNode;
   }else{
     //create new node
    Node* newNode=new Node(data);
    //newnode should point to the first node
    newNode->next=head;
    head=newNode;
   }
}

void insertAtTail(Node *& head,Node*&tail,int data){
    if(head==NULL){
        Node* newNode=new Node(data);
        newNode=head;
    }else{
        Node* newNode=new Node(data);
        tail->next=newNode;
        tail=newNode;
    }
}

void createTail(Node* head,Node* tail){
    Node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    tail=temp;
}

void insertAtNewPosition(Node*&head,Node*&tail,int data,int position){
    int length=getlength(head);
   
    if(position<1){
        cout<<"Invalid position"<<endl;
        return;
    }else if(position==1){
        insertAthead(head,tail,data);
    }else if(position==length+1){
        insertAtTail(head,tail,data);
    }else{
         Node *temp=new Node(data);
        Node  *prev=NULL;
        Node *curr=head;
        while(position!=1){
            prev=curr;
            curr=curr->next;
            position--;
        }

        prev->next=temp;
        temp->next=curr;
    }
}

void deleteNode(Node*&head,Node*&tail,int position){
    int length=getlength(head);
    if(head==NULL){
        cout<<"List is empty"<<endl;
        return;
    }

    if(head==tail){
        Node *temp=head;
        delete temp;
        head=NULL;
        tail=NULL;
        return;
    }
    if(position==1){
        Node*temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }else if(position==length){
        Node* prev=head;
        while(prev->next!=tail){
            prev=prev->next;
        }
        prev->next=NULL;
        delete tail;
        tail=prev;
    }else{
        Node*prev=NULL;
        Node*curr=head;

        while (position!=1){
            position--;
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;

    }
}
int main(){
    Node*head=NULL;
    Node*tail=NULL;
    insertAthead(head,tail,50);
    insertAthead(head,tail,40);
    insertAthead(head,tail,30);
    insertAthead(head,tail,20);
    insertAthead(head,tail,10);

    printL(head);
    // insertAthead(head,tail,5);
    // printL(head);
    // insertAtTail(head,tail,60);
    // printL(head);
    // insertAtNewPosition(head,tail,25,8);
    // printL(head);

    deleteNode(head,tail,3);
    printL(head);
   
}