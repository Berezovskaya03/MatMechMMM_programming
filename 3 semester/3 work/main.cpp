#include <iostream>
#include<exception>
#include<memory>
#include<mutex>
#include<stack>
#include <thread>
using namespace std;

struct empty_stack: std::exception
{
	const char* what() const throw();
};

template<typename T>
class thread_stack
{
private: 
	stack<T> data;//
	mutable mutex m;
public:
	thread_stack(){}
	thread_stack(const thread_stack& other)
	{
		lock_guard<mutex> lock(other.m);//
		data=other.data;
	}
	thread_stack& operator=(const thread_stack&) = delete;

	void push(T new_value)
	{
		lock_guard<mutex> lock(m);
		data.push(new_value);
	}
	shared_ptr<T> pop()
	{
		lock_guard<mutex> lock(m);
		if (data.empty()) throw empty_stack();
		shared_ptr<T> const res(make_shared<T>(data.top()));
		data.pop;
		return  res;
	}
	void pop(T& value)
	{
		lock_guard<mutex> lock(m);
		if (data.empty()==0) cout<<data.top();//throw /*empty_stack()*/;
		value=data.top();
	cout<<value;
		data.pop();
	}
	
};
 int main()
{
int a=42;
  thread_stack<int> SL;
	SL.push(a++);

SL.push(a++);
SL.push(a++);
SL.pop(a);
SL.pop(a);
	std:: thread t1(&thread_stack<int>::push, SL, 8);
	std:: thread t2(&thread_stack<int>::push, SL, a);
	t1.join();
	t2.join();

return 0;
	
}
