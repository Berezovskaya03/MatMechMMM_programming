#include <iostream>
using namespace std;
int main() {
int N;
cin>> N;
int *a=new int [N+1];
for (int i=0; i<N+1; i++){
    a[i]=i;
}
for (int i=2; i<N+1; i++){
    if (a[i]!=0){
        cout<<a[i]<<endl;
        for (int j=i*i; j<N+1; j+=i){
            a[j]=0;
        }
    }

}
}
