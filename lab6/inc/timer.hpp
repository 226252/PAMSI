#ifndef timer_HPP
#define timer_HPP
#include <chrono>
#include <ctime>
#include <ratio>
#include <iomanip>
using namespace std::chrono;
using namespace std;
#include <iostream>
template <typename T>
struct timer
{
	high_resolution_clock::time_point start, end;
	// std::chrono::duration<double> time_span; 
	T ms;
	 
    void begin(){
    	start = high_resolution_clock::now();
    }
    // 
    void stop(){
    	end = high_resolution_clock::now();
    }
    // 
	void duration_out(){
		ms = duration_cast<T>(end-start); 
    	cout<<std::fixed<< "czas trwania: " << ms.count() << endl;
	}
	float duration(){
		ms = duration_cast<T>(end-start);
		return double(ms.count());
	}
};
//
#endif