#include <iostream>
#include <vector>
#include <iterator>
#include <ctime>
#include <numeric>
#include <thread>
#include<algorithm>
#include <functional>

using namespace std;

void push_vect(vector<unsigned long> &vect,  unsigned long n)

{
	for (unsigned long i= 0; i < n; ++i) 

    {
	vect.push_back( rand()%1000+1 );
	cout<< vect[i] << " ";

    }
cout<< endl;
	
}

/*template<class InputIt, class T>
T accumulate(InputIt first, InputIt last, T init)
{
    for (; first != last; ++first) {
        init = std::move(init) + *first; // std :: move начиная с C ++ 20
    }
    return init;
}
*/

/*template<typename Iterator,typename T>
struct accumulate_block
{
      void operator()(Iterator first,Iterator last,T& result)  
{            
	result=std::accumulate(first,last,result);  
}
};*/

/*template<typename Iterator,typename T>
T parallel_accumulate(Iterator first,Iterator last,T init)
{      
unsigned long const length=std::distance(first,last);
      if(!length)
          return   init;
      unsigned long const min_per_thread=25;
      unsigned long const max_threads=
            (length+min_per_thread-1)/min_per_thread; 
      unsigned long const hardware_threads=
	std::thread::hardware_concurrency();
      unsigned long const num_threads=
            std::min(hardware_threads!=0?hardware_threads:2,max_threads);
      unsigned long const block_size=length/num_threads;
      std::vector<T> results(num_threads);
      std::vector<std::thread>   threads(num_threads-1);
      Iterator   block_start=first;
      for(unsigned long i=0;i<(num_threads-1);++i)
  {
            Iterator   block_end=block_start;            
std::advance(block_end,block_size);
            threads[i]=std::thread(         
                  accumulate_block<Iterator,T>(),   
               block_start,block_end,std::ref(results[i]));
            block_start=block_end;
  }
      accumulate_block<Iterator,T>(block_start,last,results[num_threads-1]);
      std::for_each(threads.begin(),threads.end(),
            std::mem_fn(&std::thread::join));
      return   
std::accumulate(results.begin(),results.end(),init);
}*/

struct accumulate_block
{
      void operator()(vector<unsigned long>::iterator first,vector<unsigned long>::iterator last, unsigned long& result)  
{            
	result=std::accumulate(first,last,result);  
}
};


unsigned long parallel_accumulate(vector<unsigned long>::iterator first,vector<unsigned long>::iterator last,unsigned long init)
{      
unsigned long const length=std::distance(first,last);
      if(!length)
          return   init;
      unsigned long const min_per_thread=25;
      unsigned long const max_threads=
            (length+min_per_thread-1)/min_per_thread; 
      unsigned long const hardware_threads=
	std::thread::hardware_concurrency();
      unsigned long const num_threads=
            std::min(hardware_threads!=0?hardware_threads:2,max_threads);
      unsigned long const block_size=length/num_threads;
      std::vector<unsigned long> results(num_threads);
      std::vector<std::thread>   threads(num_threads-1);
      vector<unsigned long>::iterator   block_start=first;
      for(unsigned long i=0; i<(num_threads-1); ++i)
  {
            vector<unsigned long>::iterator block_end = block_start;            
	std::advance(block_end,block_size);
            threads[i]=std::thread(accumulate_block(), block_start, block_end, std::ref(results[i]));
            block_start=block_end;
  }
      accumulate_block()(block_start,last,results[num_threads-1]);
      std::for_each(threads.begin(),threads.end(),
            std::mem_fn(&std::thread::join));
      return   
std::accumulate(results.begin(),results.end(),init);
}

int main()
{
	srand(time(0));

	 vector<unsigned long > v;
	
	//accumulate_block<int, int>;
    unsigned long  n=1000;

  push_vect(v, n);

	vector<unsigned long >::iterator first;

    vector<unsigned long >::iterator last;

	first = v.begin();
	last = v.begin() + 1000;
	int sum = parallel_accumulate(first, last, 0);

    cout << sum;

	return 0;

} 
