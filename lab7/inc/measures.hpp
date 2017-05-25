#ifndef measures_HPP
#define measures_HPP
#include <iostream>
using namespace std;
#include "Array.hpp"
#include "timer.hpp"
#include "algorithms/Quick_sort.hpp"
#include "interfaces/iRunable.hpp"
#include <fstream>

double measures(iRunable & execute, int prepare_quantity, char prepare_option=' ', char run_option=' '){ 
	
	Array pomiary(5);
	double result;
		execute.prepare(prepare_quantity);
	for(int i=0; i<pomiary.get_length(); i++){
		pomiary[i]=execute.run_with_time();
	}

	execute.info();
	cout << "czas wyszukiwania: "  << pomiary.mean() << " nanosekund\n" << endl;
	result=pomiary.mean();
	return result;
}		
		
#endif