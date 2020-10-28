# include <iostream>
using namespace std;
int binpow (int x, int n) {
if (n==0) return 1;
if (n%2 == 1) return x*binpow(x, n-1);
if (n%2 == 0)  {int b = binpow(x, n/2);
    return b*b;
}
}
int main(){
int x1, n1;
cin >> x1 >> n1;
cout<<binpow (x1, n1);}
