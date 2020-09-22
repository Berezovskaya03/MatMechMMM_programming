//программа находящая среднее арифметическое кубов последовательности чисел
#include <iostream>
using namespace std;
    int main() {
        int a, b=0, d;
        cin >> a;
    d=a;
    while ( a>0 ) {
            int c;
          cin >> c;
          a =a-1;
          b = b+ c*c*c;}
    cout << b/d;
    }
