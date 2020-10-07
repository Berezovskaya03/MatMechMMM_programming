#include <iostream>
using namespace std;

int gcd (int a, int b){
    if (b==0) return a;
    return gcd (b, a%b);}

struct Rational {
int m;
unsigned int n;
Rational (int x, int y) {
m= x / gcd(x,y);
n= y / gcd (x,y);
cout<<m<<"/"<<n;}
Rational operator*=(Rational A) {
m*=A.m;
n*=A.n;
m=m / gcd(m,n);
n=n / gcd(m,n);
return Rational(m ,n);
}
Rational operator/=(Rational A){
m=m* A.n;
n=n* A.m;
return Rational (m, n);
}
};

int main() {
    int m, a;
    unsigned int n, b;
cin>>m >>n>>a>>b ;
Rational A(m, n);
cout<<endl;
Rational B(a, b);
cout<<endl;
Rational C(m, n);
cout<<endl;
Rational D(a, b);
cout<<endl;
A.operator*=(B);
cout<<endl;
C.operator/=(D);
}
