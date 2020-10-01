#include <iostream>
using namespace std;
int gcd (int a, int b){
    if (b==a) return a;
    return gcd (b, a%b);}
struct rational {
int m;
unsigned int n;
rational (int x, unsigned int y) {
m=x/gcd(x,y);
n=y/gcd (x,y);}
}
int main() {
int numerator, s;
unsigned int denominator;
cin>>numerator>>denominator;
cout<<rational s (numerator, denominator);}
