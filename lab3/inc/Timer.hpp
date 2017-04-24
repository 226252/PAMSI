#ifndef Timer_HPP
#define Timer_HPP
#include <chrono>
using namespace std::chrono;
#include <iostream>
#include "iTimer.hpp"
template <typename T>
class Timer : public iTimer
{
	high_resolution_clock::time_point start, end; 
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
    	std::cout<<std::fixed<< "czas trwania: " << ms.count() << std::endl;
	}
	float duration(){
		ms = duration_cast<T>(end-start);
		return double(ms.count());
	}
	//
	friend void measures(int, int, iRunable&);
};
//
#endif