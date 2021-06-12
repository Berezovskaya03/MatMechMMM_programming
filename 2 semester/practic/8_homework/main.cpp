//Реализовать обработку ошибок для программы из задачи 4, используя стандартные исключения
#include <iostream> 
#include <cmath>
 using namespace std;
class Complex
{
public:
    double Re;                                          //действительная часть
    double Im; 
 	friend ostream& operator << (ostream&, Complex&);
	friend istream& operator >>(istream&, Complex&);                                        //мнимая часть
    Complex();                                    //конструктор по умолчанию
    Complex(double Real, double Imaginary);       //конструктор от двух действ-х чисел
    Complex(const Complex &Orig);           //конструктор копирования
    Complex operator + (const Complex &c)   
  {
    return Complex (Re + c.Re, Im + c.Im);
  }  //оператор сложения
    Complex operator - (const Complex &c)   
  {
    return Complex(Re - c.Re, Im - c.Im);
  }  //оператор вычитания
    Complex operator * (const Complex &c)   
  {
    return Complex(Re * c.Re - Im * c.Im, Re * c.Im + Im * c.Re);
  } //оператор умножения
    Complex operator / (const Complex &c)   
  {
    Complex temp;
    double r = c.Re * c.Re + c.Im * c.Im;
    temp.Re = (Re * c.Re + Im * c.Im) / r;
    temp.Im = (Im * c.Re - Re * c.Im) / r;

    return temp;
  }  //оператор деления
    Complex operator/(double op2)
	{
	return Complex(Re/op2, Im/op2);
	}                //оператор деления на действ-е число
    Complex operator=(const Complex &op2);  //оператор присваивания
	Complex& operator += (Complex); 
    Complex& operator -= (Complex); 
    Complex& operator *= (Complex); 
    Complex& operator /=(Complex ); 
    bool operator==(const Complex &op2);          //оператор равенства
    bool operator!=(const Complex &op2);          //оператор неравентсва
    Complex Conj();                               //функция получения комплексно сопряженного
    double Mod();                                 //функция получения модуля комплексного числа
};

ostream& operator << (ostream& cout, Complex& com) 
{  
    if(com.Im < 0) 
        cout << com.Re << "+i(" << com.Im << ")"; 
    else 
        cout << com.Re << "+i" << com.Im; 
    return cout;
} 

istream& operator >> (istream& cin, Complex& com) 
{   
    cout << "Введите действительную часть комплексного числа ";
    cin >> com.Re; 
    cout << "Введите мнимую часть комплексного числа "; 
    cin >> com.Im;
    return cin; 
}
Complex::Complex()
{
    Re=0.0;
    Im=0.0;
}
 
 
//конструктор от двух действ-х чисел - реализация
Complex::Complex(double Real, double Imaginary)
{
    Re=Real;
    Im=Imaginary;
}
 
 
//конструктор копирования - реализация
Complex::Complex(const Complex &Orig)
{
    Re=Orig.Re;
    Im=Orig.Im;
}
 
 

 
//оператор присваивания - реализация
Complex Complex::operator =(const Complex &op2)
{
    Re=op2.Re;
    Im=op2.Im;
    return *this;
}

Complex& Complex::operator +=(Complex com)
{
	Re+=com.Re;
	Im+=com.Im;
	return *this;
}
 
Complex& Complex::operator -=(Complex com)
{
	Re-=com.Re;
	Im-=com.Im;
	return *this;
}

Complex& Complex::operator *=(Complex com)
{
	double temp;
	temp=Re;
	Re=Re*com.Re-Im*com.Im;
    Im=temp*com.Im+Im*com.Re;
    return *this;
}

Complex& Complex::operator /=(Complex com)
{
    double r = com.Re * com.Re + com.Im * com.Im;
    Re = (Re * com.Re + Im * com.Im) / r;
    Im = (Im * com.Re - Re * com.Im) / r;
    return *this;
}
//оператор равенства - реализация
bool Complex::operator ==(const Complex &op2)
{
    if((Re==op2.Re)&&(Im==op2.Im)) return true;
    else return false;
}
 
//оператор неравенства - реализация
bool Complex::operator !=(const Complex &op2)
{
    return !(*this==op2);
}
 
//функция получения комплексно сопряженного - реализация
Complex Complex::Conj()
{
    Complex temp;
    temp.Re=Re;
    temp.Im=-Im;
    return temp;
}
 
//функция получения модуля комплексного числа - реализация
double Complex::Mod()
{
    return sqrt(Re*Re+Im*Im);
}
int main() 
{ 
	Complex c(2, 1);
	Complex a;
	Complex com;
    

try // ищем исключения внутри этого блока и отправляем их в соответствующий обработчик catch
    {
cin >> com;

if (cin.fail())

{
 throw "Incorrect input.";

       cin.clear();

       while(cin.get()!='\n');

} else {

       cout << "You have entered: " << a << endl;

} 
    }    
    catch (const char* exception) // обработчик исключений типа const char*
    {
        std::cerr << "Error: " << exception << '\n';
    }
	
	a=com+c;
	cout << a << endl;
	a=com-c;
	cout << a << endl;
	a=com+c;
	cout << a << endl;
	a=com/c;
	cout << a << endl;
	double b=com.Mod();
	cout << b << endl;
	a= com.Conj();
	cout << a << endl;
	if (a==c) {a+=c;}
	else {a-=c;}
	cout << a << endl;
	if (a!=c) {a*=c;}
	else {a/=c;}
	cout << a << endl;
return 0;
}
