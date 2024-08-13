#include<iostream>
using namespace std;



class Node{
    public:
    int data;
    Node* next;
    Node*prev;

    Node(){
        this->next=NULL;
        this->prev=NULL;

    }
    Node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
};

void printl(Node *head){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;

    }
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

void insertAtHead(Node*&head,Node*&tail,int data){
   if(head==NULL){
    Node* newNode=new Node(data);
    head=newNode;
    tail=newNode;
   }else{
     Node* newNode=new Node(data);

    newNode->next=head;
    head->prev=newNode;
    head=newNode;
   }
}

void insertAtTail(Node*&head,Node*&tail,int data){
    if(head == NULL){
        Node* newNode=new Node(data);
        head=newNode;
        tail=newNode;
    }
    else{
        Node *newNode=new Node(data);
        tail->next=newNode;
        newNode->prev=tail;
        tail=newNode;
    }
}

void insertAtPosition(Node *&head,Node*&tail,int data,int position){
    int len=getlength(head);
    if(position==1){
        insertAtHead(head,tail,data);
    } 
    else if(position==len+1){
        insertAtTail(head,tail,data);
    }else{
        Node*newNode=new Node(data);
        Node *prevNode=NULL;
        Node *currNode=head;

        while(position!=1){
            prevNode=currNode;
            currNode=currNode->next;
            position--;
        }

        prevNode->next=newNode;
        newNode->prev=prevNode;
        newNode->next=currNode;
        currNode->prev=newNode;
    }

    
}

void deleteNode(Node*&head,Node*&tail,int position){
    if(head==NULL){
        cout<<"List is empty"<<endl;    

    }
    int len=getlength(head);
    if(head==tail){
        Node*temp=head;
        temp->next=NULL;
        temp->prev=NULL;
        delete temp;
    }

    if(position==1){
        Node*temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }else if(position ==len+1){
        Node*prevNode=tail->prev;
        prevNode->next=NULL;
        tail->prev=NULL;
        delete tail;
        tail=prevNode;
           


    }else{
        Node *prevNode=NULL;
        Node *currNode=head;

        while(position!=1){
            position--;
            prevNode=currNode;
            currNode=currNode->next;
        }
        Node* nextNode=currNode->next;
        prevNode->next=nextNode;
        currNode->prev=NULL;
        currNode->next=NULL;
        nextNode->prev=prevNode;
    }
}



int main(){
    Node*head=NULL;
    Node*tail=NULL;
    insertAtHead(head,tail,1);
    insertAtHead(head,tail,2);
    insertAtHead(head,tail,3);
    insertAtHead(head,tail,4);
    insertAtHead(head,tail,5);
    printl(head);
    cout<<endl;
    //insertAtTail(head,tail,9);
    

    insertAtPosition(head,tail,10,3);
    printl(head);
    cout<<endl;
    deleteNode(head,tail,6);

    printl(head);

}