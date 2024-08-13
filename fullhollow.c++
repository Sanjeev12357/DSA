/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;

int main()
{
    int n;
    
    cin>>n;
    
    for(int i = 0 ;i < n;i++){
        for (int j =0 ;j< n-i-1;j++){
            cout<<" ";
        }
        for(int j =0 ;j<i+1;j++){
            if(j == 0 || j == i + 1  - 1){
                cout<< "* ";
            }else{
                cout<<" ";
            }
        }
        cout << endl;
    }

   
}