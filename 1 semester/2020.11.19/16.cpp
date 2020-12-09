//задача о рюкзаке
#include <iostream>
#include <cmath>
using namespace std;
struct segments{
    int price;
    int w;
    double specw;
};
void quickSort(struct segments seg[], int left, int right) {
int i = left, j = right;
double pivot = seg[(left + right) / 2].specw;
while (i <= j) {
    while (seg[i].specw < pivot){
        i++;}
    while (seg[j].specw > pivot){
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

int main(int argc, const char * argv[]) {
    int n, maxw;
    cin>>n>>maxw;
    struct segments seg[n];
    for(int i=0;i<n;i++){
        cin>>seg[i].price;
        cin>>seg[i].w;
        seg[i].specw =(double)seg[i].price/seg[i].w;
    }
    quickSort(seg, 0, n-1);
    cout<<endl;
    double maxprice= 0;
    for(int i = n-1;(i>=0)&&(maxw>=0);i--){
            if ((maxw-seg[i].w)>=0) {
                maxprice+=seg[i].price;
            }
            else {maxprice+=maxw*seg[i].specw;
            }
           maxw-=seg[i].w;
        }
    cout<<maxprice;
    return 0;
}
