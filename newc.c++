#include<iostream>
#include<vector>
using namespace std;

void solve(int arr[],int size,int index,vector <int> &ans){
    if(index>=size){
        return;
    }
    if(arr[index]%2 == 0){
        ans.push_back(arr[index]);

    }
    solve(arr,size,index+1,ans);

}
int main(){
    // cout<<"heelo";
    // int arr[5]={1,2,3,4,5};
    // int *p=arr;
    // cout<<p;
    // string ans="";
    //  vector<string> dictionary={"cat","rat","the"};
    //  cout<<dictionary[0];
    // string s="the cat was rattled by the rat";
    // cout<<s[0];
    // int i=0;
    // while(i<s.length()){
    //     for(auto c:dictionary){
            
    //     }
    // }

    int arr[5]={1,2,3,4,5};
    vector<int> ans;
    solve(arr,5,0,ans);
    for(auto i:ans){
        cout<<i<<" ";
    }


   

    
}