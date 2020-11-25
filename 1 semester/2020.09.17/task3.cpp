//вычисление биномиального коэффицента из n по k
#include <iostream>
using namespace std;
long double get_res (long n, long k){
    if (k==n or k==0){return 1;
    }
    if (k!=1) {
        return get_res (n-1, k-1)*n/k;
    }
    else {
        return n;
    }
    }
int main(){
    long n1,k1;
    cin>> n1>>k1;
    cout<< get_res(n1,k1);
}
