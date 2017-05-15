#ifndef Quicksort_HPP
#define Quicksort_HPP
#include <iostream>
using namespace std;
#include "../timer.hpp"
#include "../interfaces/iRunable.hpp"
#include "../interfaces/iQuick_sort.hpp"



//sposob implementacji Qsort jako klasy
//zainspirowane kodem Rafala Borysionka

class Quick_sort :public iRunable
{
	
	iQuick_sort & object;
	bool isObjectLoaded = false;
	bool afterRun = false;
	char chosenOption;
public:
//konstruktory
	Quick_sort(iQuick_sort &x);
//algorytm Qsort
	void quick_sort(int first, int last,char what_pivot);
//to warto wiedziec
	bool is_sorted();
//a to z interfejsow
	void run(char option);
	double run_with_time(char option);
	void info();
	void prepare( int prepare_quantity, char prepare_option);
	void output();
	void reset();
}; 

	Quick_sort::Quick_sort(iQuick_sort &x): 
		object(x),
		isObjectLoaded(true){}
//
	void Quick_sort::quick_sort(int first, int last,char what_pivot){
		int pivot_place;
		int pivot;
		// i,j zmienne sluzace do przechodzenia po tablicy
		int i,j;
		if(what_pivot=='f'){
			pivot_place=first;
		}
		
		if(what_pivot=='m'){
			pivot_place=((first+last)/2);
		}
		
		if(what_pivot=='l'){
			pivot_place=last;
		}
		pivot=object[pivot_place];
		object[pivot_place]=object[last];
		for(i=j=first; i<last; i++){
			if(object[i] < pivot){
				object.change_place(i,j);
				j++;
			}
		}

		object[last]=object[j];
		object[j]=pivot;
		if(first<(j-1)){
			quick_sort(first, (j-1), what_pivot);
		}
		if (j+1 <last){
			quick_sort((j+1), last, what_pivot);
			
		}

	}
//
	bool Quick_sort::is_sorted(){
		for(int i=0; i<(object.get_length()-1);i++){
			if(object[i]>object[i+1]){
				return false;
			}
		}
		return true;
	}
//
	void Quick_sort::run(char option){
		if(isObjectLoaded){
			quick_sort(0, (object.get_length()-1), option);
		} else {
			cout << "There is nothing to run :c" << endl;
		}
		if(!is_sorted()){
			cout << "Something went wrong, it's not sorted" << endl;
		}
		afterRun=true;
		chosenOption=option;
	}
//
	double Quick_sort::run_with_time(char option){
		if(isObjectLoaded){
			timer<microseconds> clock;
			clock.begin();
			run(option);
			clock.stop();
			return clock.duration();
		} else {
			cout << "There is nothing to run :c" << endl;
			return 0;
		}

	}
//	
	void Quick_sort::info(){
		cout << "Algorytm Quick_sort" << endl;
		if(afterRun){
			cout << "\tWykonany z opcja: " << chosenOption << endl;
		}else
		{
			cout << "\tJeszcze nie wykonany" << endl;
		}
		object.info(); 
	}
	void Quick_sort::prepare(int prepare_quantity,char prepare_option){
		object.prepare(prepare_quantity, prepare_option);
	}
//
	void Quick_sort::output(){
		object.output();
	}
//
	void Quick_sort::reset(){
		if(isObjectLoaded){
			object.reset();
		}else{
			cout<<"nothing to reset\n";
		}
	}

#endif