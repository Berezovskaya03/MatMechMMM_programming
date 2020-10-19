#include <iostream>
using namespace std;
void numb (int *aa, int*bb, int n1) {
   int m=0;
   for (int j=2; j<n1+1; j++) {
    if (aa[j]==0) {bb[m]=j;
    m=++m;}
   }
}
int main (){
int n;
cin>>n;
int *a=new int[n+1];
for (int i=0;i<n+1;i++){
        a[i]=i;
    }
  for (int i=2;i<n+1;i++){
        if (a[i]!=0) {
            for (int j=i*i; j<n+1; j+=i){
                a[j]=0;
                }
            }
        }
    int count=0;
    for (int j=2; j<n+1; j++) {
            if (a[j]==0) {count=++count;};
        }
int  *b=new int[count];
numb (a, b, n);
for (int i=0;i<count;i++) {cout<<b[i]<<endl;}
}

