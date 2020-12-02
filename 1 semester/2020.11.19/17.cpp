#include <iostream>
#include <cmath>
using namespace std;
struct segmentspart{
    int endhour, endminute;
    int beginhour, beginminute;
};
struct segments{
    int end;
    int begin;
};
void quickSort(struct segments seg[], int left, int right) {
int i = left, j = right;
int pivot = seg[(left + right) / 2].end;
while (i <= j) {
    while (seg[i].end < pivot){
        i++;}
    while (seg[j].end > pivot){
        j--;}
    if (i <= j) {
        swap(seg[i],seg[j]);
        i++;
        j--;
    }
};
if (left < j){
    quickSort(seg, left, j);
}
if (i < right){
    quickSort(seg, i, right);
}
};

int main() {
    int n;
    cin>>n;
    struct segments seg[n];
    struct segmentspart segpart[n];
    for(int i=0;i<n;i++){
        cin>>segpart[i].endhour>>segpart[i].endminute;
        seg[i].end=100*segpart[i].endhour+segpart[i].endminute;
        cin>>segpart[i].beginhour>>segpart[i].beginminute;
        seg[i].begin=100*segpart[i].beginhour+segpart[i].beginminute;
        if(seg[i].end<seg[i].begin){
            swap(seg[i].end, seg[i].begin);
        }
        }
    quickSort(seg, 0, n-1);//сортировка по концам отрезков в порядке неубывания
     cout<<seg[0].begin/100<<":";
              if ((seg[0].begin%100)<10) {cout<<"0";}
             cout<<seg[0].begin%100<<"-"<<seg[0].end/100<<":";
             if ((seg[0].end%100)<10) {cout<<"0";}
             cout<<seg[0].end%100<<endl;
    int counter=0;
    for(int i = 1;i<n;i++){//жадный алгоритм по теореме по поиску минимальной базы матроида
          if(seg[i].begin>=seg[counter].end){
             cout<<seg[i].begin/100<<":";
              if ((seg[i].begin%100)<10) {cout<<"0";}
             cout<<seg[i].begin%100<<"-"<<seg[i].end/100<<":";
             if ((seg[i].end%100)<10) {cout<<"0";}
             cout<<seg[i].end%100<<endl;
            counter=i;}
            }
    return 0;
}
