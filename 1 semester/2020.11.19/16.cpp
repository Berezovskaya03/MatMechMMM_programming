//решение задачи о рюкзаке
#include <iostream>
#include <cmath>
using namespace std;
struct segments{
    int price;//x
    int weight;//y
    int w;//óäåëüíûé âåñ
};
void quickSort(struct segments seg[], int left, int right) {
int i = left, j = right;
int pivot = seg[(left + right) / 2].w;
while (i <= j) {
    while (seg[i].w < pivot){
        i++;}
    while (seg[j].w > pivot){
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
    int maxweight;
    cin>>maxweight;
    struct segments seg[n];
    for(int i=0;i<n;i++){
        cin>>seg[i].price;
        cin>>seg[i].weight;
        seg[i].w=seg[i].price/seg[i].weight;
        }
        int mprice=0;
    quickSort(seg, 0, n-1);
    for(int i=n-1;(i>=0)&&(maxweight>0);i--){
            if ((maxweight-seg[i].weight)>0) {
                mprice+=seg[i].price;
            }
            else {mprice+=maxweight*seg[i].price;
                } maxweight-=seg[i].weight;
    }
    cout<<mprice;
}
