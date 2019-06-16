#include<bits/stdc++.h>
using namespace std;

void quickSort(double a[],int b[],int lo,int hi);
int Partition(double a[],int b[],int lo,int hi);
int main(){
    int Id,n;
    double Cg;
    cin>>n;
    int id[n];
    double cg[n];
    for(int i=0;i<n;i++){
        cin>>id[i];
        cin>>cg[i];
    }
    quickSort(cg,id,0,n-1);
    cout<<"Output:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<id[i]<<" "<<cg[i]<<endl;
    }
}
void quickSort(double a[],int b[],int lo,int hi){
    if(lo<hi){
        int p=Partition(a,b,lo,hi);
        quickSort(a,b,lo,p-1);
        quickSort(a,b,p+1,hi);
    }
}
int Partition(double a[],int b[],int lo,int hi){
    double pivot=a[hi];
    int i=lo-1;
    for(int j=lo;j<=hi;j++){
        if(a[j]>=pivot){
            i=i+1;
            swap(a[i],a[j]);
            swap(b[i],b[j]);
        }
    }
    swap(a[i+1],a[hi]);
    swap(b[i+1],b[hi]);
    return i+1;
}
