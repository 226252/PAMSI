#ifndef quicksort_HPP
#define quicksort_HPP
#include <iostream>
using namespace std;
#include "tab.hpp"





void quick_sort(tab &array, int first, int last, char what_pivot){
	int pivot_place;
	int pivot;
	
	if(what_pivot=='f'){
		pivot_place=first;
	}
	
	if(what_pivot=='m'){
		pivot_place=((first+last)/2);
	}
	
	if(what_pivot=='l'){
		pivot_place=last;
	}

	pivot=array[pivot_place];
	array[pivot_place]=array[last];
	int j=0;
	for(int i=0; i<last; i++){
		if(array[i] < pivot){
			array.change_place(i,j);
			j++;
		}
	}

	array[last]=array[j];
	array[j]=pivot;
	if(first<(j-1)){
		quick_sort(array, first, (j-1), what_pivot);
	}
	if (j+1 <last){
		quick_sort(array, (j+1), last, what_pivot);
		
	}

}
#endif