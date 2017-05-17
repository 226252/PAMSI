#ifndef measures_HPP
#define measures_HPP
#include <iostream>
using namespace std;
#include "Array.hpp"
#include "timer.hpp"
#include "algorithms/Quick_sort.hpp"
#include "interfaces/iRunable.hpp"
#include <fstream>

double measures(iRunable & execute, int prepare_quantity, char prepare_option, char run_option){ 
	
	Array pomiary(5);
	double result;
	string what;

	switch(prepare_option){
			case 'r':
				what ="Rosnaca tablica";
			break;

			case 'm':
				what ="Malejaca tablica";
			break;

			case 'l':
				what ="Losowa tablica";

			break;
		}
		
	for(int i=0; i<pomiary.get_length(); i++){
		execute.prepare(prepare_quantity, prepare_option);
		// execute.output();
		pomiary[i]=execute.run_with_time(run_option);
		// execute.output();					
	}

	cout<< "\nPomiar wykonywany dla: "<< what << endl;
	execute.info();
	cout << "czas sortowania: "  << pomiary.mean() << " milisekund\n" << endl;
	result=pomiary.mean();
	return result;
}		
		
#endif