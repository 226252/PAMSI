#ifndef Array_HPP
#define Array_HPP
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;
#include "interfaces/iRunable.hpp"
#include "interfaces/iQuick_sort.hpp"

 	
class Array :public iRunable, public iQuick_sort
{
	int length;       
	int * array;  
	int amor;          
	//amor wolne miejsce w tablicy
public:
	void run(char option){};
	double run_with_time(char option){return 0;};
	int & operator[](int element) {return array[element];}
	
	Array(){
		length=1;
		amor=1;
		array = new int [1];
	}
// 
	Array(int x){
		length=x;
		amor =x;
		array = new  int [length];
	}
//
	~Array(){
		delete [] array;
	} 

// Gety
	int get_length()const{
		return length;
	}
//
	int get_amor()const{
		return amor;
	}
	void input(){
		int tmp;
		for (int i=0; i<length; i++){
			cout << "podaj element nr " << i+1 << ": ";
			cin >> tmp;
			array[i]=tmp;
		}
		amor=0;
	}
//
	void add(int place, int value){
		if(place<0 && place>=length){
			cout<< "Odwolujesz sie do miejsca przed/za array, to nie pyton ;)\n";
		} 
		else{
			array[place]=value;
			if(((length-1)-place)<amor){ //sprawdzasz czy dodajac element nie zmniejszy sie odleglosc ostatniego elementu od konca tablicy i ewentualnie zmieniasz wartosc amortyzacji
				amor=(length-1)-place;
			}
		}

	}
// metody
	void fill_rand(int range){
		for (int i=0; i<length; i++){
			array[i]=rand() % range;
		}
		amor=0;
	}
// 
	void output(){
		for(int i=0; i<length; i++){
			cout << fixed << setprecision(2) << array[i]<<" ";
		}
		cout << "thats all" << endl;
	}
// 
	void enlarge(unsigned int new_length){
		int * tmp = new int [new_length];
		for (int i=0; i<length; i++){
			tmp[i]=array[i];
		}
		delete [] array;
		array=tmp;
		amor=new_length-(length-amor);
		length=new_length;
	}
// 
	double mean()const{
		double x;
		x=0;
		for(int i=0; i<length; i++){
			x=x+array[i];
		}
		return x/length;
	}
// 
	void change_place(int a, int b){
		int first;
		first=array[a];
		array[a]=array[b];
		array[b]=first;
	}
//
	void equals(Array t){
		if(t.get_length()==length){
			for(int i=0; i<length; i++){
				array[i]=t[i];
			}
		}
		else{
			enlarge(t.get_length());
			for(int i=0; i<length;i++){
			array[i]=t[i];	
			}
		}	
	}
//
		
	void prepare(char prepare_option){
		
		if(prepare_option=='r'){
			for(int i=0; i<length;i++){
				array[i]=i+1;
			}
		}

		if(prepare_option=='m'){
			for(int i=0; i<length; i++){
				array[i]=length-i;
			}
		}
		
		if(prepare_option=='l'){
			fill_rand(100);
		}
	
	}
//
	void info(){
		cout << "Struktura danych: tablica\n\tRozmiar: " << length << endl;
	}

};
#endif