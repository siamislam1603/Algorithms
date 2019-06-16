#include<stdio.h>
#include<iostream>
#include<map>
#include<vector>

using namespace std;

int main(){
    map<double,string> mp;
    vector<double> v;
    vector<double> v2;
    string s;
    double cg;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s;
        cin>>cg;
        mp[cg]=s;
        v.push_back(cg);
    }
    for(int j=0;j<n;j++){
        v2.push_back(v[j]);
        for(int k=j+1;k<n;k++){
            if(v[k]>v[j]){
                v2[j]=v[k];
            }
        }
        cout<<mp[v2[j]]<<endl;
    }
}
