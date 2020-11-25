#include <iostream>
#include <vector>
using namespace std;
int main(){
int k, n;
cout<<"k=";
cin>>k;
cout<<endl<<"n=";
cin>>n;
cout<<endl<<"¬вод массива";
int aa[n+1];
for (int i=0; i<n; i++){
    cin>>aa[i];
}
vector<int> v;
int bb[k+1];
for (int i=0; i<k+1; i++){
    bb[i]=i;
}
for (int i=2; i<k+1; i++){
    if (bb[i]!=0){
        v.push_back(bb[i]);
        for (int j=i*i; j<k+1; j+=i){
            bb[j]=0;
        }
    }
}
for (int i=0; i<n; i++){
    for (int j=0; j<v.size(); j++) {
        if (aa[i]==v[j]) cout<<aa[i]<<" ";
    }
}
}
