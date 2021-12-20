//имитация ожидания в аэропорте вылета
#include <future>
#include <iostream>
using namespace std;

int find_the_answer_to_ltuae(int W, int nervous){
	if (W<=12) return 8;//boarding way number
	if (nervous<0) {cout<<"people die"; return 0;}
	return find_the_answer_to_ltuae(W-12, nervous-1000);
};
int do_other_stuff(int T, int M){
	if (T>4) {M-=4000; return M;}
	if (T>3) {M-=200; return M;}
return M;
}
int main(){
int money=5000, wind=0, time=0, nervous=10000;
cout<<"time before departure=";
cin>>time;
cout<<endl;
cout<< "wind=";
cin>> wind;
std::future<int> the_answer=std::async(find_the_answer_to_ltuae, wind, nervous);
do_other_stuff(time, money);
std::cout<<"Ответ равен "<<the_answer.get()<<std::endl;
return 0;
}
