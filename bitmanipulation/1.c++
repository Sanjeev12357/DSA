#include<iostream>
#include<vector>
using namespace std;

void checkEvenOdd(int n){
    if(n&1){
        cout<<"Odd"<<endl;
    }else{
        cout<<"Even"<<endl;
    }
}   
void getIthBit(int n,int i){
    if(n&(1<<i)){
        cout<<"1"<<endl;
    }else{
        cout<<"0"<<endl;
    }
}
void setIthBit(int n,int i){
    n=n|(1<<i);
    cout<<n<<endl;
}
void clearIthBit(int &n,int i){
    int mask=~(1<<i);
    n=n&mask;
    cout<<n<<endl;
}
void updateIthBit(int n,int i,int target){
    clearIthBit(n,i);
    n=n|(target<<i);
    cout<<n<<endl;
}
void clearLastIBits(int n,int i){
    int mask=(-1<<i);
    n=n& mask;
    cout<<n<<endl;
}
bool checkPowerOf2(int n){
    int count=0;
    while(n!=0){
        int lastbit=n&1;
        if(lastbit==1){
            count++;
        }
        n=n>>1;

    }
    if(count==1){
        return true;
    }else{
        return false;
    }
}

void clearBitsinRange(int n,int i,int j){
   int a=(-1<<i+1);
   int b=~(-1<<j);
    int mask=a|b;
    n=n&mask;
    cout<<n<<endl;
}

bool checkpowerOf2(int n){
    if(n==0){
        return false;
    }
    return (n&(n-1))==0;
}
void getSubsequences(string str){
    int n=str.length();
    vector<string>ans;
    for(int num=0;num<(1<<n);num++){
        // num mai jaha par set bit padi hai us character ko includer kar lenge
        string temp="";
        for(int i=0;i<n;i++){
            //i represent kr rha hai index ko
            char ch=str[i];
            // agar i index pr num ke nadar set bit present hai toh charcer include krlo
            if(num&(1<<i)){
                temp.push_back(ch);
            }
        }
        ans.push_back(temp);
    }
    for(auto x:ans){
        cout<<x<<endl;
    }
}
int main(){
   
   // checkEvenOdd(n);
//    int n=15;
//    int i=2;
//    getIthBit(n,i);
//     setIthBit(n,i);
//     clearIthBit(n,i);
//     updateIthBit(n,i,0);
    // clearLastIBits(n,i);
    //cout<<checkPowerOf2(15);
  //  cout<<checkpowerOf2(15);
//   int n=1023;
//   int i=8;
//   int j=1;
//     clearBitsinRange(n,i,j);
    string str="abc";
    getSubsequences(str);
    return 0;
}
// }