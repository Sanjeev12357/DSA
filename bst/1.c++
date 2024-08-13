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

    Node * max(Node* root){
        if(root==NULL){
            cout<<"tree is empty"<<endl;
            return NULL;
        }

        while(root->right!=NULL){
            root=root->right;
        }
        return root;
    }

    //deleting a node from bst
    Node * deleteFromBST(Node *root,int target){
        if(root==NULL){
            return NULL;
        }

        if(root->data==target){
            // 4 case bante hai
            if(root->left==NULL && root->right==NULL){
                delete root;
                return NULL;
            }else if(root->left!=NULL && root->right==NULL){
                Node * childSubtree=root->left;
                delete root;
                return childSubtree;
            }else if(root->right!=NULL && root->left==NULL){
                Node * childSubtree=root->right;
                delete root;
                return childSubtree;
            }else{
                //when both root right and left are not null
                Node * maxi=max(root->left);
                root->data=maxi->data;
                root->left=deleteFromBST(root->left,maxi->data);
                return root;
            }
        }else if(root->data>target){
            root->left=deleteFromBST(root->left,target);
        }else{
            root->right=deleteFromBST(root->right,target);
        }
        return root;
    }

    Node * treefrominorder(int inorder[],int s,int e){
        if(s>e){
            return NULL;
        }
        int mid=(s+e)/2;
        int root=inorder[mid];
        Node * rootnode=new Node(root);
        rootnode->left=treefrominorder(inorder,s,mid-1);
        rootnode->right=treefrominorder(inorder,mid+1,e);
        return rootnode;
    }
 int main(){

    int inorder[]={1,2,3,4,5,6,7};
    Node * root=treefrominorder(inorder,0,6);
    levelOrdertraversal(root);
    // Node *root=NULL;
    // createBST(root);
    // levelOrdertraversal(root);
    // Node * maxNode=max(root);
    // cout<<"max node is "<<maxNode->data<<endl;  
    
    // cout<<"enter the node to delete"<<endl;
    // int target;
    // cin>>target;
    // root=deleteFromBST(root,target);
    // levelOrdertraversal(root);
    return 0;
 }  