//Написать недружественные функции, предоставляющие доступ к закрытым полям

#include <iostream>
#include "A.h"
using namespace std;


int main() {
	int x;
	double y;
	char t;
	long long z;
	cin >> x >> y >> t >> z;
	A example(x,y,t,z);
	cout<<example.get_a()<<" "<< example.get_b() << " "<<example.get_c() << " "<<example.get_d() << endl;
	cin >> x >> y >> t >> z;
	example.put_a(x);
	example.put_b(y);
	example.put_c(t);
	example.put_d(z);
	cout << example.get_a() << " " << example.get_b() << " " << example.get_c() << " " << example.get_d() << endl;
}
	
