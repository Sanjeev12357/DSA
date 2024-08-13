#include<iostream>
using namespace std;



int paintways(int n,int k){
    if(n==1){
        return k;
    }
    if(n==2){
        return k+k*(k-1);

    }

    int ans=(k-1)*(paintways(n-1,k)+paintways(n-2,k));

    return ans;
}
int main(){
    int n=3,k=3;

    cout<<paintways(n,k);
}