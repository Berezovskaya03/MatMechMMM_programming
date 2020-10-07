//вычисление биномиального коэффицента из n по k
#include <iostream>
using namespace std;
int get_res (int n,int k){
    int den=max(n-k, k), del=1, result=1;
    while (del<=min (n-k,k)) {
        den=++den;
        result=result*den/del;
        del=++del;
    }
    while(den<n) {
        den=++den;
        result=result*den;
}
return result;
}
int main(){
    int n1,k1, coefficent;
    cin>> n1>>k1;
    coefficent=get_res(n1,k1);
    cout<< coefficent;
}
