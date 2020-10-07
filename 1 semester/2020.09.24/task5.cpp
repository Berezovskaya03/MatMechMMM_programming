# include <iostream>
using namespace std;
int func(int *begin1, int count1) {
int temp;
for (int i=0;i<count1-1;i++){
    for (int j=0; j<count1-i-1; j++){
        if (*(begin1+j)<*(begin1+j+1)) {
            temp=*(begin1+j);
            *(begin1+j)=*(begin1+j+1);
            *(begin1+j+1)=temp;
        }
    }
}
}
int main(){
int count;
cin>>count;
int a[count];
for (int i=0; i<count;i++){
        cin>>a[i];}
int *begin=a;
func(begin, count);
for (int i=0; i<count;i++){
        cout <<a[i];}
}
