//"распараллелить" проект из 2ого семестра
#include <iostream>
#include <thread>

using namespace std;

template <class Ta, class Tb>
class Pair
{
    private:
    Ta A;
    Tb B;
    public:
    Pair <Ta, Tb>(Ta A_c=0.0, Tb B_c=0.0) :A(A_c), B(B_c) { };
    Pair <Ta, Tb>();
    Pair <Ta, Tb>(const Pair<Ta, Tb>& c) :A(c.A), B(c.B) { };
    ~Pair<Ta, Tb>();
    Pair <Ta, Tb>& operator =(const Pair<Ta, Tb>&);
    Ta& getA();
    Tb& getB();
    void setA(Ta value);
    void setB(Tb value);
    template<class U, class V>
    friend ostream& operator <<(ostream&, const Pair<U, V>&);
};

template <class Ta, class Tb>
Pair<Ta, Tb>::~Pair()
{
cout << "delete" << endl;
}

template<class Ta, class Tb>
Pair<Ta, Tb>& Pair<Ta, Tb>::operator =(const Pair<Ta, Tb>& c2) {
A = c2.A;
B = c2.B;
return *this;
}

template<class Ta, class Tb>
Ta& Pair<Ta, Tb>::getA(){
return A;
}

template<class Ta, class Tb>
Tb& Pair<Ta, Tb>::getB(){
return B;
}

template<class Ta, class Tb>
void Pair<Ta, Tb>::setA(Ta value){
A=value;
}

template <class Ta, class Tb>
void Pair<Ta, Tb>::setB(Tb value){
B=value;
}

template<class Ta, class Tb>
ostream& operator  << (ostream& cout, const Pair<Ta, Tb>& c) {
cout << c.A << " and " << c.B << endl;
return cout;
}

void geta(Pair<int, double> c1)
{
cout << c1.getA() << endl;
cout << c1.getB() << endl;
}

int main() {
Pair<int, double> c1(1, 3.0), c2(2, 10.5);
cout << "c1 pair " << c1 << endl;
cout << "c2 pair " << c2 << endl;
c1=c2;
cout << "c1 pair now " << c1 << endl;
cout << c1.getA() << endl;
cout << c1.getB() << endl;
//std:: thread t(geta, c1);
//geta(c1);
double k=8;
c2.setA(k);
//t.join();
cout << "c2 pair after setA " << c2 << endl;
return 0;
}
