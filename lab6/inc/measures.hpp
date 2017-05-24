#ifndef measures_HPP
#define measures_HPP
#include <iostream>
using namespace std;
#include "Array.hpp"
#include "timer.hpp"
// #include "algorithms/Quick_sort.hpp"
#include "interfaces/iRunable.hpp"
#include <fstream>

double measures(iRunable & execute, int prepare_quantity){ 
	
	Array pomiary(5);
	execute.prepare(prepare_quantity);	
	
	for(int i=0; i<pomiary.get_length(); i++){	
		// execute.output();
		pomiary[i]=execute.run_with_time();
		// execute.output();					
	}
	cout<<endl;
	execute.info();
	execute.output();
	cout << "czas wyszukiwania: "  << pomiary.mean() << " nanosekund\n" << endl;
	return pomiary.mean();
}		
		
#endif