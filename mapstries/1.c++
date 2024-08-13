#include<iostream>
#include<unordered_map>

using namespace std;

int main(){
    unordered_map<char,int>mapping;
    string s="lovebabbar";
    for(int i=0;i<s.size();i++){
        mapping[s[i]]++;
    }
    for(auto x:mapping){
        cout<<x.first<<" "<<x.second<<endl;
    }
    
    // pair<string,int>p =make_pair("sanjeev",25);
    // pair<string,int>r("sajeev",20);
    // pair<string,int>q;
    // q.first="arjun";
    // q.second=30;

    // mapping.insert(p);
    // mapping.insert(q);
    // mapping.insert(r);

    // for(auto x:mapping){
    //     cout<<x.first<<" "<<x.second<<endl;
    // }

    // //searching
    // cout<<mapping.at("sanjeev")<<endl;

    // cout<<mapping.count("sanjeev")<<endl;

    // if(mapping.find("babbar")!= mapping.end()){
    //     cout<<"found"<<endl;
    // }else{
    //     cout<<"not found"<<endl;
    // }
    
}