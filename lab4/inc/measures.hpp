#ifndef measures_HPP
#define measures_HPP
#include <iostream>
using namespace std;
#include "Array.hpp"
#include "timer.hpp"
#include "algorithms/Quick_sort.hpp"
#include "interfaces/iRunable.hpp"

//Idea dzialania programu
//	prosze o przeczytanie i ewentualne wskazanie
//	bledow w mysleniu
//funkcja measures zostaje tworzona przy kazdym nowym projekcie
//	w taki sposob by wykonywac swoja funkcje
//	w srodku zostaje przygotowana struktura
//	np. tablica zostaje wypelniona randomowo
//	tablica wchodzi do obiektu iQuick_sort
//	oznacza to ze zostanie poddana algorytmowi Qsort
//	przy wywolaniu run()
//	nastepnie obiekt iQsort wchodzi do obiektu iRunable
//	wykonane zostaje run()


void measures(iRunable & execute, char prepare_option, char run_option){ 
	
	Array pomiary(5);
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
		execute.prepare(prepare_option);
		// execute.output();
		pomiary[i]=execute.run_with_time(run_option);
		// execute.output();					
	}

	cout<< "Pomiar wykonywany dla: "<< what << endl;
	execute.info();
	cout << "czas sortowania: "  << pomiary.mean() << " milisekund" << endl;

}				
#endif