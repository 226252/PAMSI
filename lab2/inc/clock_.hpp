#ifndef clock__HPP
#define clock__HPP
#include <chrono>
#include <ctime>
#include <ratio>
#include <iomanip>
using namespace std::chrono;
#include <iostream>
class clock_
{
	high_resolution_clock::time_point start, end;
	// std::chrono::duration<double> time_span; 
	std::chrono::nanoseconds ms;
	 
    void begin(){
    	start = high_resolution_clock::now();
    }
    // 
    void stop(){
    	end = high_resolution_clock::now();
    }
    // 
	void duration_out(){
		ms = duration_cast<nanoseconds>(end-start); 
    	cout<<std::fixed<< "czas trwania: " << ms.count() << endl;
	}
	float duration(){
		ms = duration_cast<nanoseconds>(end-start);
		return double(ms.count());
	}
	//
	friend void measures(int, int);
};
//
#endif