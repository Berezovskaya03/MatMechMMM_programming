#include <iostream>

using namespace std;

template < typename T >
void subtree(T* a, int n, int i)
{
    int root = i;   
    int left = 2*i + 1; 
    int right = 2*i + 2; 
    if (left < n && a[left] > a[root])
        root = left;
    if (right < n && a[right] > a[root])
        root = right;
    if (root != i)
    {
        swap(a[i], a[root]);
        subtree(a, n, root);
    }
}

template < typename T >
void heapSort(T* a, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        subtree(a, n, i);
    for (int i=n-1; i>=0; i--)
    {
        swap(a[0], a[i]);
        subtree(a, i, 0);
    }
}

template < typename T >
void swap ( T & first , T & second )
{
    T temp = first ;
    first = second ;
    second = temp ;
}

int main()
{
int* a=new int[6];
	for (int i=0; i<6; ++i)
        cin >> a[i];
	
    heapSort<int>(a, 6);
	for (int i=0; i<6; ++i)
        cout << a[i] << " ";
}
