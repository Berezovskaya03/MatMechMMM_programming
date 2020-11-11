#include <iostream>
#include <vector>
using namespace std;
int main(){
int count;
cin>> count;
int a[count];
int svec, number, maxsvec, maxnumb;
svec=0;
maxsvec=1;
for (int i=0;i<count; i++){
        cin>>a[i];}
number=0;
for (int i=1;i<count; i++){
        if (a[i]>a[i-1]) {
          svec=svec+1;
        }
        else { if (svec>maxsvec)
                   { maxnumb=number;
                       maxsvec=svec;
                   }
                number=i;
                svec=1;
        }
}
if (svec>maxsvec)
                   { maxnumb=number;
                       maxsvec=svec;
                   }
        vector <int> ivec (&a[maxnumb], &a[maxnumb+maxsvec-1]);
        for (int i=maxnumb;i<maxnumb+maxsvec; i++){
        cout<<a[i];}
}
