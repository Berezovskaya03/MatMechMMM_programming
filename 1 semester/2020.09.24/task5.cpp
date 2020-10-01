# include <iostream>
using namespace std;
int main(){
int count;
cin>>count;
int a[count];
for (int i=0; i!=count;i++){
        cin>>a[i];}
int *begin=a, *end=a+count;
int temp;
for (int i=0;i<count-1;i++){
    for (int j=0; j<count-i-1; j++){
        if (*(begin+j)>*(begin+j+1)) {
            temp=*(begin+j);
            *(begin+j)=*(begin+j+1);
            *(begin+j+1)=temp;
        }
    }
}
for (int i=0; i<count;i++){
        cout <<a[i];}
}
