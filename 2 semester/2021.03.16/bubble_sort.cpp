#include <iostream>
using namespace std;
extern "C" void bubbleSort(int *B, int last)
{
  for(int i = 0;i<last;i++){
    for(int j = (last-1);j>i;j--){
      if(B[j]<B[j-1]){
        int tmp = B[j];
        B[j]=B[j-1];
        B[j-1]=tmp;
      }
    }
  }
}
