//среднее арифметическое кубов последовательности
#include <iostream>
using namespace std;
    int main() {
        int count, sum=0, d;
        cin >> count;
    d=count;
    while ( d>0 ) {
            int c;
          cin >> c;
          d=d-1;
          sum = sum+ c*c*c;}
    cout << sum/count;
    }
