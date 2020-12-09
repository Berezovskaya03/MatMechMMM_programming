#include <iostream>/*Написать программу, находящую разложение натурального числа в сумму натуральных квадратов, с наименьшим числом слагаемых*/
#include <cmath>
using namespace std;
bool lagrange(double number){
    int k = (int)sqrt(number);
    for(int a = 0; a<=k;a++){
        for(int b = a; b<=k;b++){
            for(int c = b; c<=k;c++){
                for(int d = c; d<=k;d++){
                    if(a*a+b*b+c*c+d*d==number){
                        cout<<a<<"-"<<b<<"-"<<c<<"-"<<d<<endl;
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    lagrange(n);
    cout<<endl;
    return 0;
}
