#include <iostream>
using namespace std;

template <typename T, int str, int stolb>
class MATRIX {
public:  T** a = new T * [str];

    MATRIX() {
        for (int i = 0; i < str; i++)
            a[i] = new T[stolb];
        for (int i = 0; i < str; i++)
            for (int j = 0; j < stolb; j++)
                a[i][j] = 0;
    }

    ~MATRIX() {
        for (int i = 0; i < str; i++)
            delete[] a[i];
        delete[] a;
    }

    void set(int i, int j, T value) {
        a[i-1][j-1] = value;
    }

    T get(int i, int j) {
        return a[i-1][j-1];
    }

    void transposition() {
        MATRIX<T, stolb, str> M;
        for (int i = 0; i < str; i++)
            for (int j = 0; j < stolb; j++)
                M.a[j][i] = a[i][j];
        M.print();
    }

    void print() {
        for (int i = 0; i < str; i++) {
            for (int j =0; j < stolb; j++)
                std::cout<<a[i][j]<<"  ";
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    MATRIX& operator =(const MATRIX& M) {
        for (int i = 0; i < str; i++)
            for (int j = 0; j < stolb; j++)
                a[i][j] = M.a[i][j];
        return *this;
    }

    MATRIX& operator +(const MATRIX& M) {
        for (int i = 0; i < str; i++)
            for (int j = 0; j < stolb; j++)
                a[i][j] = a[i][j] + M.a[i][j];
        return *this;
    }

    MATRIX& operator -(const MATRIX& M) {
        for (int i = 0; i < str; i++)
            for (int j = 0; j < stolb; j++)
                a[i][j] = a[i][j] - M.a[i][j];
        return *this;
    }

    MATRIX& operator *(const MATRIX& M) {
        if (str != stolb) {
            std::cout << "Matrix isn't square " << std::endl; 
            return *this;
        }
        else {
            MATRIX M1;
            for (int i = 0; i < str; i++) {
                for (int j = 0; j < str; j++)
                {
                    M1.a[i][j] = 0;
                    for (int k = 0; k < str; k++)
                        M1.a[i][j] += M.a[i][k] * a[k][j];
                }
            }
            for (int i = 0; i < str; i++)
                for (int j = 0; j < str; j++) 
                    a[i][j] = M1.a[i][j];
            return *this;
        }
    }
};

template<typename T, int str> // специализация вектора
class MATRIX<T, str, 1> {
private:
    T* a = new T[str];
public:
    MATRIX() {
        for (int i = 0; i < str; i++)
            a[i] = 0;
    }
    ~MATRIX() {
        delete[] a;
    }
    void set(int i, T value) {
        a[i] = value;
    }
    T get(int i) {
        return a[i];
    }
    void print() {
        for (int i = 0; i < str; i++) 
                std::cout << a[i] << "  ";
            std::cout << std::endl<<std::endl;
    }
    void transposition() {
        MATRIX<T, 1, str> M;
        for (int i = 0; i < str; i++)
                M.set(i,a[i]);
        M.print();
    }
   
    MATRIX& operator =(const MATRIX& M) {
        for (int i = 0; i < str; i++)
            a[i] = M.a[i];
        return *this;
    }
    MATRIX& operator +(const MATRIX& M) {
        for (int i = 0; i < str; i++)
            a[i] = a[i] + M.a[i];
        return *this;
    }
    MATRIX& operator -(const MATRIX& M) {
        for (int i = 0; i < str; i++)
            a[i] = a[i] - M.a[i];
        return *this;
    }
    MATRIX& operator *(MATRIX<T,1,str>& M) {
        for (int i = 0; i < str; i++)
            a[i] = a[i] * M.get(i);
        return *this;
    }
};

template<typename T, int stolb>
class MATRIX<T, 1, stolb> {
private:
    T* a = new T[stolb];
public:
    MATRIX() {
        for (int j = 0; j < stolb; j++)
            a[j] = 0;
    }
    ~MATRIX() {
        delete[] a;
    }
    void set(int i, T value) {
        a[i] = value;
    }
    T get(int i) {
        return a[i];
    }
    void print() {
            for (int j = 0; j < stolb; j++)
                std::cout << a[j] << std::endl;
            std::cout << std::endl;
    }
    void transposition() {
        MATRIX<T, stolb, 1> M;
        for (int i = 0; i < stolb; i++)
            M.set(i, a[i]);
        M.print();
    }
   
    MATRIX& operator =(const MATRIX& M) {
        for (int j = 0; j < stolb; j++)
            a[j] = M.a[j];
        return *this;
    }
    MATRIX& operator +(const MATRIX& M) {
        for (int j = 0; j < stolb; j++)
            a[j] = a[j] + M.a[j];
        return *this;
    }
    MATRIX& operator -(const MATRIX& M) {
        for (int j = 0; j < stolb; j++)
            a[j] = a[j] - M.a[j];
        return *this;
    }
	MATRIX& operator *(MATRIX<T, stolb, 1>& M) {
        for (int i = 0; i < stolb; i++)
            a[i] = a[i] * M.get(i);
        return *this;
    }
};

int main() {
   cout<<"Hello world!";
}
