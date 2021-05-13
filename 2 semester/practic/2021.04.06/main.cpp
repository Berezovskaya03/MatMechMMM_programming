//реализация структуры циклического массвива
#include <iostream>
using namespace std;


struct array {
	int* data;
	size_t size;
public:
	array(){
	size=0;
	data=NULL;
}
	array(size_t mysize){
	size=mysize;
	data=new int[mysize];
}
	~array(){
	delete [] data;
}
	array(const array& a){
	if (data) {delete[] data;}
	size=a.size;
	data=new int[size];
	for (int i=0; i<size; i++){
		data[i]=a.data[i];
	}
}
	array& operator =(const array& a){
	if(data) {delete[] data;}
	size=a.size;
	data=new int[size];
	for(int i=0; i<size; i++){
		data[i]=a.data[i];
	}
	return *this;
}
	int& operator[](size_t i){
	return data [i % size];
}
};

int main() {
	int size;
	cin >> size;
	array a(size);
	for (int i = 0; i < size; i++) {
		cin >> a[i];
	}
	int k;
	cin>> k;
	k+=size;
		cout << a[k]<<" ";
	return 0;
}
