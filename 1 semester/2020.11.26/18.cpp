//поиск разложения натурального числа на сумму квадратов с наименьшим числом слагаемых
#include <iostream>
#include <cmath>
using namespace std;
int main(){
int n;
cin>>n;
int a[n];//количество множителей
int counter=1;
for (int i=1; i<=n; i++){
  if  (i==(counter*counter)) {
    a[i]=1;
  ++counter;
  }
  else { int min=2147483647;
  int sq=sqrt(i);
    for (int j=1; j<=sq; j++){
        if (a[i-j*j]<min) min=a[i-j*j];
       }
       a[i]=++min;
}
}
int term;//каждое новое слагаемое
while (a[n]!=1) {int min=2147483647;
  int sq=sqrt(n);
    for (int j=1; j<=sq; j++){
        if (a[n-j*j]<min) {min=a[n-j*j];
        term=j;
       }
    }
    cout<<term<<" ";
       n-=term*term;
}
cout<<sqrt(n);
}
