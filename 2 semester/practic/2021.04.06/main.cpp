 #include <iostream>
using namespace std;

template<typename T>
class Pair {
    private:
        T A;
        T B;
    public:
        Pair <T>(T A_c=0.0, T B_c=0.0)
            :A(A_c), B(B_c) { };
	Pair <T>();
        Pair <T>(const Pair<T>& c)
            :A(c.A), B(c.B) { };
		~Pair<T>();
		Pair <T>& operator =(const Pair<T>&);
		T& getA();
		T& getB();
		void setA(T value);
		void setB(T value);
        template<typename U>
        friend ostream& operator <<(ostream&, const Pair<U>&);
};

template <typename T>
Pair<T>::~Pair()
{
	cout<<"delete"<< endl;
}


template<typename T>
Pair<T>& Pair<T>::operator =(const Pair<T>& c2) {
    A = c2.A;
    B = c2.B;
	return *this;
}

template<typename T>
T& Pair<T>::getA(){
	return A;
}

template<typename T>
T& Pair<T>::getB(){
	return B;
}

template<typename T>
void Pair<T>::setA(T value){
	A=value;
}

template <typename T>
void Pair<T>::setB(T value){
	B=value;
}


template<typename T>
ostream& operator <<(ostream& cout, const Pair<T>& c) {
    cout << c.A << " and " << c.B << endl; 
    return cout;
}

int main() {
    Pair<double> c1(1, 3), c2(2, 10.5), c3();
    cout << "c1 pair " << c1 << endl;
    cout << "c2 pair " << c2 << endl;
	c1=c2;
	cout<< "c1 pair now "<< c1 << endl;
	cout<< c1.getA() << endl;
	cout<< c1.getB() << endl;
	double k=8;
	c1.setA(k);
	cout<< "c1 pair after setA "<< c1 << endl;
    return 0;
}
