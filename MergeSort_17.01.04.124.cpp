#include<bits/stdc++.h>
using namespace std;

void mergeSort(int a[],int lo,int hi);
void Merge(int a[],int lo,int mid,int hi);
int main(){
    int n;
    cout<<"Enter size of array:";
    cin>>n;
    int a[n],m;
    for(int i=0;i<n;i++){
        cin>>m;
        a[i]=m;
    }
    mergeSort(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" "<<endl;
    }
}
void mergeSort(int a[],int lo,int hi){
    if(lo<hi){
        int mid=(lo+hi)/2;
        mergeSort(a,lo,mid);
        mergeSort(a,mid+1,hi);
        Merge(a,lo,mid,hi);
    }
}
void Merge(int a[],int lo,int mid,int hi){
    int n1=mid-lo+1;
    int n2=hi-mid;
    int L[n1],R[n2];
    for(int i=0;i<n1;i++){
        L[i]=a[lo+i];
    }
    for(int j=0;j<n2;j++){
        R[j]=a[mid+1+j];
    }
    L[n1]=INT_MAX;
    R[n2]=INT_MAX;
    int i=0,j=0;
    for(int k=lo;k<=hi;k++){
        if(L[i]<R[j]){
            a[k]=L[i];
            i=i+1;
        }
        else{
            a[k]=R[j];
            j=j+1;
        }
    }
}
