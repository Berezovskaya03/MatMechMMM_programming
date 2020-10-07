#include <iostream>
using namespace std;

int gcd (int a, int b){
    if (b==0) return a;
    return gcd (b, a%b);}

struct Rational {
int m;
unsigned int n;
Rational (int x, unsigned int y) {
m=x/gcd(x,y);
n=y/gcd (x,y);
cout<<m<<"/"<<n;}
};

int main() {
    int m;
    unsigned int n;
cin>>n >>m ;
Rational (n, m);
}
