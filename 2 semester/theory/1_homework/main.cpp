//реализация структуры циклического массвива
#include <iostream>
using namespace std;


struct c_array {
	int* data;
	size_t size;
	c_array(size_t N) {
		size = N;
		data = new int[size];
	}
	~c_array() {
		delete[] data;
	}
	c_array(const c_array& A) {
		if (data) {
			delete[] data;
		}
		size = A.size;
		data = new int[size];
		for (int i = 0; i < size; i++) {
			data[i] = A.data[i];
		}
	}
	c_array operator=(const c_array& A) {
		if (data) {
			delete[] data;
		}
		size = A.size;
		data = new int[size];
		for (int i = 0; i < size; i++) {
			data[i] = A.data[i];
		}
		return *this;
	}
	int operator[](size_t i) const{
		return data[i % size];
	}
	int& operator[](size_t i){
		return data[i % size];
	}
};

int main() {
	int N;
	cin >> N;
	c_array A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	int k;
	cin>> k;
	k+=N;
		cout << A[k]<<" ";
	return 0;
}
