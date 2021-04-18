#include <iostream>
using namespace std;
extern "C" void SelectionSort(int *A , int n) //сортировка выбором
{
int count, key, i, j;
for (i = 0; i < n - 1; i++)
{
count = A[i]; key = i;
for (j = i + 1; j < n; j++)
if (A[j] < A[key]) key = j;
if (key != i)
{
A[i] = A[key];
A[key] = count;
}
}
}
