#include<iostream>
#include <string>
#include<vector>
using namespace std;

class TrieNode{
    public:
    char val;
    TrieNode * children[26];
    bool isEnd;

    TrieNode(char val){
        this->val=val;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        this->isEnd=false;
    }
};

void insertNode(TrieNode * root,string s){
    // cout<<"recieving end"<<s<<endl;
    //using recursion
    if(s.length()==0){
        root->isEnd=true;
        return;
    }

    char ch=s[0];
    int index=ch-'a';
    TrieNode* child;
    if(root->children[index]!=NULL){
        //child is present
        child=root->children[index];
    }else{
        //absent
        child=new TrieNode(ch);
        root->children[index]=child;
    }

    //recursion
    insertNode(child,s.substr(1));
}
bool searchWord(TrieNode * root,string word){
    //base case
    if(word.length()==0){
        return root->isEnd;
    }

    char ch=word[0];
    int index=ch-'a';
    TrieNode * child;
    if(root->children[index]!=NULL){
        child=root->children[index];
    }else{
        return false;
    }
    bool reckaans=searchWord(child,word.substr(1));
    return reckaans;

}

void deleteWord(TrieNode* root,string word){
    if(word.length()==0){
        root->isEnd=false;
        return;
    }

    //1 case mea
    char ch=word[0];
    int index=ch-'a';
    TrieNode* child;

    if(root->children[index]!=NULL){
        child=root->children[index];
    }else{
        return;
    }

    deleteWord(child,word.substr(1));
}
void storeString(TrieNode * root,vector<string>&ans,string &input, string &prefix){
    if(root->isEnd == true) {
    //ans store
    ans.push_back(prefix + input);
    //return ?
  }

  for(char ch='a'; ch<='z'; ch++) {
    int index = ch - 'a';
    TrieNode* next = root->children[index];
    if(next != NULL) {
      //child exist
      input.push_back(ch);
      //baaaki recursion
      storeString(next, ans, input, prefix);
      //backtrack
      input.pop_back();
    }
  }
}

void findPrefixstring(TrieNode * root,string input,vector<string> &ans,string& prefix){
    if(input.length()==0){
        //1st step is traverse the whole input string
        TrieNode* lastchar=root;
        storeString(lastchar,ans,input,prefix);
        return;
    }
    char ch=input[0];
    int index=ch-'a';
    TrieNode *child;
    if(root->children[index]!=NULL){
        child=root->children[index];
    }else{
        return;
    }

    findPrefixstring(child,input.substr(1),ans,prefix);
}
int main(){
    TrieNode * root=new TrieNode('-');

   insertNode(root,"cater");
   insertNode(root,"care");
   insertNode(root,"com");
   insertNode(root,"lover");
   insertNode(root,"loved");
   insertNode(root,"load");
   insertNode(root,"lov");
   insertNode(root,"bat");
   insertNode(root,"cat");

   string input="ca";
   string prefix =input;
   vector<string>ans;
   findPrefixstring(root,input,ans,prefix);
   for(auto i:ans){
    cout<<i<<endl;
   }



    // if(searchWord(root,"sanju")){
    //     cout<<"found";
    // }else{
    //     cout<<"not found";
    // }

    // deleteWord(root,"sanju");
    // if(searchWord(root,"sanju")){
    //     cout<<"found";
    // }else{
    //     cout<<"not found";
    // }

    

} 