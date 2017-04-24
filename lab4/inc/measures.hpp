#ifndef measures_HPP
#define measures_HPP
#include <iostream>
using namespace std;
#include "tab.hpp"
#include "timer.hpp"
#include "quicksort.hpp"

void measures(tab &t, char option){ 
	tab pomiary(5);
	timer<milliseconds> clock;
	string what;
	switch(option){
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
			cout<< what << endl;
			cout<<"ilosc elementow: " <<t.get_length() << endl;
				for(int i=0; i<pomiary.get_length(); i++){
				t.fill(option);
				clock.begin();
				quick_sort(t, 0, t.get_length()-1,'f');
				clock.stop();
				pomiary[i]=clock.duration();
				if(!is_sorted(t)){
					cout << "not sorted :c"<< endl;	
				}
				}
			cout <<"  pivot: poczatek \n    czas sortowania: " << pomiary.mean() << " milisekund" << endl;
				
				for(int i=0; i<pomiary.get_length()-1; i++){
				t.fill(option);
				clock.begin();
				quick_sort(t, 0, t.get_length(),'m');
				clock.stop();
				pomiary[i]=clock.duration();
				if(!is_sorted(t)){
					cout << "not sorted :c"<< endl;	
				}
				}
			cout <<"  pivot: srodek \n    czas sortowania: " << pomiary.mean() << " milisekund" << endl;
				
				for(int i=0; i<pomiary.get_length()-1; i++){
				t.fill(option);
				clock.begin();
				quick_sort(t, 0, t.get_length(), 'l');
				clock.stop();
				pomiary[i]=clock.duration();
				if(!is_sorted(t)){
					cout << "not sorted :c"<< endl;	
				}
				}
			cout <<"  pivot: koniec \n    czas sortowania: " << pomiary.mean() << " milisekund" << endl;
		
}
#endif