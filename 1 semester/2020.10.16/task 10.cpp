# include <iostream>
using namespace std;
int binpow (int x, int n, int mod) {
if (n==0) return 0;
if (n%2) return (x%mod)*binpow(x, n-1, mod);
if (!n%2) return (x%mod)*binpow (x*x, n-1, mod);
}
int main(){
int x1, n1, mod1;
cin >> x1 >> n1 >> mod1;
binpow (x1, n1, mod1);
cout<<(x1%mod1);}
