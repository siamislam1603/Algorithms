#include <bits/stdc++.h>
using namespace std;

void quickSort(int a[],int lo,int hi);
int Partition(int a[],int lo,int hi);
int main(){
    int n;
    cout<<"Enter size of array:";
    cin>>n;
    int a[n],m;
    for(int i=0;i<n;i++){
        cin>>m;
        a[i]=m;
    }
    quickSort(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" "<<endl;
    }
}
void quickSort(int a[],int lo,int hi){
    if(lo<hi){
        int p=Partition(a,lo,hi);
        quickSort(a,lo,p-1);
        quickSort(a,p+1,hi);
    }
}
int Partition(int a[],int lo,int hi){
    int pivot=a[hi];
    int i=lo-1;
    for(int j=lo;j<=hi-1;j++){
        if(a[j]>=pivot){
            i=i+1;
            swap(a[i],a[j]);
        }

    }
    swap(a[i+1],a[hi]);
    return i+1;
}
