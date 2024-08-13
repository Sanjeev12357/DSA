#include<iostream>
#include<queue>
#include<map>
#include<vector>
using namespace std;


class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        this->data=val;
        this->left=NULL;
        this->right=NULL;
    }
};

Node *createtree(){
    cout<<"enter the value for node";
    int data;
    cin>>data;

    if(data==-1){
        return NULL;
    }

    Node * root=new Node(data);

    cout<<"enter the left child of "<<data;
    root->left=createtree();
    cout<<"enter the right child of "<<data;
    root->right=createtree();

    return root;


}

void preOrder(Node *root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";

    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node *root){
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void postOrder(Node *root){
    if(root==NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

void levelOrderTraversal(Node *root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* front=q.front();
        q.pop();

        if(front==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout<<" "<<front->data<<" ";

            if(front->left!=NULL){
                q.push(front->left);
            }
            if(front->right!=NULL){
                q.push(front->right);
            }
        }
    }
    
    }

    void printLeftView(Node* root,int level,vector<int>&leftView){
        if(root==NULL){
            return;
        }

        if(level==leftView.size()){
            //iska matlbh left view vali node  mil gyi hai
            leftView.push_back(root->data);

        }
        printLeftView(root->left,level+1,leftView);
        printLeftView(root->right,level+1,leftView);



    }

    void printTopView(Node* root){
        map<int,int>hdToNode;
        queue<pair<Node*,int>>q;
        q.push(make_pair(root,0));

        while(!q.empty()){
            pair<Node*,int>front=q.front();
            q.pop();

            Node* frontNode=front.first;
            int hd=front.second;
            // if there is no entry for hd in map than create a new entry
            //agr is horizontal distance ke liye answer abhi tk store nhi hua hai toh store krdo
            //for bottom view remove the if condition

            if(hdToNode.find(hd)==hdToNode.end()){
                hdToNode[hd]=frontNode->data;
            }

            //child ko dekhna hai
            if(frontNode->left!=NULL){
                q.push(make_pair(frontNode->left,hd-1));
            }
            if(frontNode->right!=NULL){
                q.push(make_pair(frontNode->right,hd+1));
            }
        }
        cout<<"printing top view"<<endl;
        for(auto i:hdToNode){
            cout<<i.second<<" ";
        }

    }

    void printLeftBoundary(Node *root){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            return;
        }

        cout<<root->data<<" ";

        if(root->left!=NULL){
            printLeftBoundary(root->left);
        }else{
            printLeftBoundary(root->right);
        }
    }

    void printLeafBoundary(Node* root){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            cout<<root->data<<" ";
        }
        printLeafBoundary(root->left);
        printLeafBoundary(root->right);

    }

    void printRightBoundary(Node* root){
         if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            return;
        }

      

        if(root->right!=NULL){
            printRightBoundary(root->right);
        }else{
            printRightBoundary(root->left);
        }
        cout<<root->data<<" ";
    }

    void boundaryTraversal(Node* root){
        if(root==NULL){
            return;
        }

        printLeftBoundary(root);
        printLeafBoundary(root);
        if(root->right!=NULL){
            printRightBoundary(root->right);
        }else{
            printRightBoundary(root->left);
        }
       
    }
int main(){
    Node * root=createtree();
   levelOrderTraversal(root);
   // vector<int> leftView;
   // printLeftView(root,0,leftView);
   //printTopView(root);
    // for(int i=0;i<leftView.size();i++){
    //     cout<<leftView[i]<<" ";
    // }

    boundaryTraversal(root);
}