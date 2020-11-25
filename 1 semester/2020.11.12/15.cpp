# include <iostream>
using namespace std;
int main(){
    int length, sum=0, k,rasn=0, count=0;
    cin>>length>>k;
int a[length-1];
for (int i=0; i<length; i++){
    cin>>a[i];
}
for (int i=0; i<length; i++){
      if (sum+=a[i]<=k) {
      count+=i+1-rasn;
      }
      else {sum=0;
        for (int j=i; j>=rasn; j--) {
            if (sum+=a[j]<=k) count+=1;
            else break;
            rasn=i;
        }
        sum=0;
      }
}
cout<<count;
}
