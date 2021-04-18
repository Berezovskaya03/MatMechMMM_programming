#include <iostream>
#include <dlfcn.h>

/*
int main() {
    return 0;
}
*/


typedef void (*bubbleSort_t)(int*, int); 

using namespace std;

int main(int argc, char** argv)
{
    void *lib_handler = dlopen("./libsort.so", RTLD_LAZY);
    bubbleSort_t bubbleSort;
    bubbleSort = (bubbleSort_t)dlsym(lib_handler, "bubbleSort");
	void (*insertionsort)(int*, int*);
    insertionsort = (void (*)(int*,int*))dlsym(lib_handler, "insertionsort");
    void (*MergeSort)(int*, int, int);
    MergeSort = (void (*)(int*,int, int))dlsym(lib_handler, "MergeSort");
    void (*SelectionSort)(int*, int);
    SelectionSort = (void (*)(int*,int))dlsym(lib_handler, "SelectionSort");


	int i, n;

	cout <<"Размер массива > "; cin >> n;
	int* A = new int[n];
	for (i = 0; i < n; i++)
	{
		cout << (i+1) << " элемент > "; cin >> A[i];
	}
    int* B = new int[n];
	for (i = 0; i < n; i++)
	{
		B[i]=A[i];
	}
	MergeSort(B, 0, n-1); //вызов сортирующей процедуры
	cout << "Упорядоченный массив: "; //вывод упорядоченного массива
	for (i = 0; i < n; i++) cout << B[i] << " ";
    cout << endl;

	for (i = 0; i < n; i++)
	{
		B[i]=A[i];
	}
    bubbleSort(B, n); //вызов сортирующей процедуры
    cout << "Упорядоченный массив: "; //вывод упорядоченного массива
    for (i = 0; i < n; i++) cout << B[i] << " ";
    cout << endl;
    for (i = 0; i < n; i++)
	    {
		    B[i]=A[i];
	    }
    insertionsort(B, B+n); //вызов сортирующей процедуры
    cout << "Упорядоченный массив: "; //вывод упорядоченного массива
    for (i = 0; i < n; i++) cout <<B[i] << " ";
    cout << endl;
    for (i = 0; i < n; i++)
	    {
		    B[i]=A[i];
	    }
    SelectionSort(B, n); //вызов сортирующей процедуры
    cout << "Упорядоченный массив: "; //вывод упорядоченного массива
    for (i = 0; i < n; i++) cout << B[i] << " ";
    delete[]B;

    dlclose(lib_handler);
    return 0;
}
