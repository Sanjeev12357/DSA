#include<iostream>
#include<queue>
using namespace std;



class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int value){
        this->data=value;
        this->left=NULL;
        this->right=NULL;
    }

};

Node * insertIntoBST(Node * root,int data){
    if(root==NULL) {
        root=new Node(data);
        return root;
    }
    //its not the first node
    if(data > root->data){
        root->right=insertIntoBST( root->right, data);
    }else{
        root->left=insertIntoBST(root->left, data);
    
    }
    return root;
}

void  createBST(Node * &root){
    cout<<"enter the data for the node"<<endl;
    int data;
    cin>>data;

    while(data!=-1){
        root=insertIntoBST(root,data);
        cout<<"enter the data for the node"<<endl;
        cin>>data;
    }
   

}

void levelOrdertraversal(Node* root){
    if(root==NULL){
        return;
    }
    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node * temp=q.front();
        q.pop();

        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
        }
    }
    }}


void convertBSTtoDLL(Node* root,Node* &head){
    if(root==NULL){
        return;
    }
    //rnl
    convertBSTtoDLL(root->right,head);
    root->right=head;
    if(head!=NULL){
        head->left=root;
    }
    head=root;
    convertBSTtoDLL(root->left,head);
}

Node* convertDLLtoBST(Node* &head,int n/2){
    if(head==NULL){
        return;
    }
    Node * leftsubtree=convertDLLtoBST(head,n/2);
    Node *root=head;
    root->left=leftsubtree;
    head=head->right;
    Node* rightsubtree=convertDLLtoBST(head,n-n/2-1);
    root->right=rightsubtree;
}
int main(){
    Node * root=NULL;
    createBST(root);
    Node * head=NULL;
    convertBSTtoDLL(root,head);
    while(head->right!=NULL){
        cout<<head->data<<" ";
        head=head->right;
    }

}