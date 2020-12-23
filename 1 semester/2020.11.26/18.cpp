<<<<<<< HEAD
//ïîèñê ðàçëîæåíèÿ íàòóðàëüíîãî ÷èñëà íà ñóììó êâàäðàòîâ ñ íàèìåíüøèì ÷èñëîì ñëàãàåìûõ
=======
//Ð¿Ð¾Ð¸ÑÐº Ñ€Ð°Ð·Ð»Ð¾Ð¶ÐµÐ½Ð¸Ñ Ð½Ð°Ñ‚ÑƒÑ€Ð°Ð»ÑŒÐ½Ð¾Ð³Ð¾ Ñ‡Ð¸ÑÐ»Ð° Ð½Ð° ÑÑƒÐ¼Ð¼Ñƒ ÐºÐ²Ð°Ð´Ñ€Ð°Ñ‚Ð¾Ð² Ñ Ð½Ð°Ð¸Ð¼ÐµÐ½ÑŒÑˆÐ¸Ð¼ Ñ‡Ð¸ÑÐ»Ð¾Ð¼ ÑÐ»Ð°Ð³Ð°ÐµÐ¼Ñ‹Ñ…
>>>>>>> e101011e1cacd760cb6dc619658b726fd2fe18d6
#include <iostream>
#include <cmath>
using namespace std;
int main(){
int n;
cin>>n;
<<<<<<< HEAD
int a[n];//êîëè÷åñòâî ìíîæèòåëåé
=======
int a[n];//ÐºÐ¾Ð»Ð¸Ñ‡ÐµÑÑ‚Ð²Ð¾ Ð¼Ð½Ð¾Ð¶Ð¸Ñ‚ÐµÐ»ÐµÐ¹
>>>>>>> e101011e1cacd760cb6dc619658b726fd2fe18d6
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
<<<<<<< HEAD
int term;//êàæäîå íîâîå ñëàãàåìîå
=======
int term;//ÐºÐ°Ð¶Ð´Ð¾Ðµ Ð½Ð¾Ð²Ð¾Ðµ ÑÐ»Ð°Ð³Ð°ÐµÐ¼Ð¾Ðµ
>>>>>>> e101011e1cacd760cb6dc619658b726fd2fe18d6
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
