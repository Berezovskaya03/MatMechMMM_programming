//фунцция Аккермана
#include <iostream>
using namespace std;
    int f(int m, int  n) {
        if (m==0) return n+1;
        if (n==0 && m>0) return f(m-1,1);
        if (m>0 && n>0) return f(m-1, f(m, n-1));
    }
    int main() {
        int x, y;
        cin>> x>> y;
    int res= f(x, y);
    cout<< res;
    return 0;
    }
