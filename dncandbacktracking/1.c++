//merge sort

#include <iostream>
using namespace std;


void merge(int arr[],int s,int e){
    int mid=(s+e)/2;
    int lenleft=mid-s+1;
    int lenright=e-mid;

    int *left =new int[lenleft];
    int *right =new int[lenright];

    int k=s;
    for(int i=0;i<lenleft;i++){
        left[i]=arr[k++];
    }
    k=mid+1;
    for(int i=0;i<lenright;i++){
        right[i]=arr[k++];
    }

    int leftIndex=0;
    int rightIndex=0;
    int mainIndex=s;

    while(leftIndex<lenleft && rightIndex<lenright){
        if(left[leftIndex]<right[rightIndex]){
            arr[mainIndex++]=left[leftIndex++];
        }else{
            arr[mainIndex++]=right[rightIndex++];
        
        }
    }

    while(leftIndex<lenleft){
        arr[mainIndex++]=left[leftIndex++];
    }
    while(rightIndex<lenright){
        arr[mainIndex++]=right[rightIndex++];
    }

    delete [] left;
    delete [] right;
}

void mergeSort(int arr[],int s,int e){
    if(s>e){
        return;

    }
    if(s==e){
        return;
    }
    int mid=(s+e)/2;

    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);

    merge(arr,s,e);
}
int main(){
    int arr[]={2,1,3,5,4,6};
    int size=6;
    int s=0;
    int e=size-1;

    mergeSort(arr,s,e);
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}