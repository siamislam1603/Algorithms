#include<stdio.h>
#include<iostream>
using namespace std;

void HeapSort(int a[],int n);
void Build_Max_Heap(int a[],int n);
void Max_Heapify(int a[],int i);
int left(int i);
int right(int i);
int heapSize;
int main(){
    int n;
    cout<<"Enter no of elements:";
    cin>>n;
    int a[n];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    heapSize=sizeof(a)/sizeof(a[0]);
    HeapSort(a,n);
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void HeapSort(int a[],int n){
    Build_Max_Heap(a,n);
    for(int i=n;i>=2;i--){
        swap(a[1],a[i]);
        heapSize=heapSize-1;
        Max_Heapify(a,1);
    }
}

void Build_Max_Heap(int a[],int n){
    for(int i=n/2;i>=1;i--){
        Max_Heapify(a,i);
    }
}

void Max_Heapify(int a[],int i){
    int l=left(i);
    int r=right(i);
    int largest;
    if(l<=heapSize && a[l]>a[i]){
        largest=l;
    }
    else{
        largest=i;
    }
    if(r<=heapSize && a[r]>a[largest]){
        largest=r;
    }
    if(largest!=i){
        swap(a[i],a[largest]);
        Max_Heapify(a,largest);
    }
}

int left(int i){
    return 2*i;
}

int right(int i){
    return 2*i+1;
}
