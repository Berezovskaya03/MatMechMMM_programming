#include <iostream>

using namespace std;
void del(int *aa,int *bb,int j){
    int *pp=aa+j;
    int *c=bb;
    for(int *qq=aa;qq<pp;qq++){
        if((*qq)%(2)!=0){
            *c=*qq;
            c++;
    }
}
    delete []aa;
}
int main(){
    int n=0;
    cin>>n;
    int *a= new int [n];
    for(int i=0;i<n;cin >> a[i++]){}
    int *p=a+n;
    int k=0;
    for(int *q=a;q<p;q++){
        if(*q%2!=0){
            k++;
        }
    }
    int *b=new int[k];
    del(a,b,n);
    for(int i=0;i<k;cout << b[i++]<<endl){}
    delete []b;
    return 0;
}
