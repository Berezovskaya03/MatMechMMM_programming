#include <iostream>
using namespace std;
extern "C" void insertionsort(int* l, int* r) {
	for (int *i = l + 1; i < r; i++) {
		int* j = i;
		while (j > l && *(j - 1) > *j) {
			swap(*(j - 1), *j);
			j--;
		}
	}
}
