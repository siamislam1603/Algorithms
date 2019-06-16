#include<stdio.h>
#include<iostream>

using namespace std;
void heapSort(float a[],int n);
void BuildMinHeap(float a[],int n);
void MinHeapify(float a[],int i);
int left(int i);
int right(int i);
int heapSize;
int main(){
    int n ;
    cin>>n;
    float a[n];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    heapSize=n;
    heapSort(a,n);
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void heapSort(float a[],int n){
    BuildMinHeap(a,n);
    for(int i=n;i>=2;i--){
        swap(a[1],a[i]);
        heapSize=heapSize-1;
        MinHeapify(a,1);
    }
}
void BuildMinHeap(float a[],int n){
    for(int i=n/2;i>=1;i--){
        MinHeapify(a,i);
    }
}
void MinHeapify(float a[],int i){
    int l=left(i);
    int r=right(i);
    int smallest;
    if(l<=heapSize && a[l]<a[i]){
        smallest=l;
    }
    else{
        smallest=i;
    }
    if(r<=heapSize && a[r]<a[smallest]){
        smallest=r;
    }
    if(smallest!=i){
        swap(a[i],a[smallest]);
        MinHeapify(a,smallest);
    }
}
int left(int i){
    return 2*i;
}
int right(int i){
    return 2*i+1;
}
