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
	double * array;  
	int amor;          
	//amor wolne miejsce w tablicy
	void enlarge(int new_length);

public:

// Konstruktory i operatory
	Array();
	Array(int x);
	~Array();
	double & operator[](int element);
// Gety
	int get_length()const;
	int get_amor()const;
// metody
	void input();
	void add(int place, int value);
	void fill_rand(int range);
	void output();
	double mean()const;
	void change_place(int a, int b);
	void equals(Array &t);
	void prepare(int prepare_quantity, char prepare_option);
	void info();
	void reset();
// potrzebne by dzialalo dzidziczenie z iRun
	void run(char option){ cout<<"good luck with running a data structure :-D\n";};
	
	double run_with_time(char option){
		cout<<"Structure runs so fast that It will return you 0 :-D\n";
		return 0;
	};



};

	Array::Array(){
		length=1;
		amor=1;
		array = new double [1];
	}
// 
	Array::Array(int x){
		length=x;
		amor =x;
		array = new  double [length];
	}
//
	Array::~Array(){
		delete [] array;
	} 
//
	double& Array::operator [](int element){
		if(element<length){
			return array[element];
		}else{
			cout<<"Próba wyjścia poza zakres, zwracam 1 element\n";
			return array[0];
		}
	}
// Gety
	int Array::get_length()const{
		return length;
	}
//
	int Array::get_amor()const{
		return amor;
	}
	void Array::input(){
		int tmp;
		for (int i=0; i<length; i++){
			cout << "podaj element nr " << i+1 << ": ";
			cin >> tmp;
			array[i]=tmp;
		}
		amor=0;
	}
//
	void Array::add(int place, int value){
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
	void Array::fill_rand(int range){
		for (int i=0; i<length; i++){
			array[i]=rand() % range;
		}
		amor=0;
	}
// 
	void Array::output(){
		for(int i=0; i<length; i++){
			cout << fixed << setprecision(2) << array[i]<<" ";
		}
		cout << "thats all" << endl;
	}
// 
	void Array::enlarge(int new_length){
		if (new_length==length){
			cout<<"Atempting to enlarge to the same size, operation aborted\n";	
		}

		if (new_length<length){
			cout<<"Atempting to enlarge to smaller size, operation aborted\n";	
		}
		
		if(new_length>length){
			double * tmp = new double [new_length];
			for (int i=0; i<length; i++){
				tmp[i]=array[i];
			}
			delete [] array;
			array=tmp;
			amor=new_length-(length-amor);
			length=new_length;
		}

	}
// 
	double Array::mean()const{
		double x;
		x=0;
		for(int i=0; i<length; i++){
			x=x+array[i];
		}
		return x/length;
	}
// 
	void Array::change_place(int a, int b){
		int first;
		first=array[a];
		array[a]=array[b];
		array[b]=first;
	}
//
	void Array::equals(Array &t){
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
		
	void Array::prepare(int prepare_quantity, char prepare_option){
		reset();
		enlarge(prepare_quantity);

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
	void Array::info(){
		cout << "Struktura danych: tablica\n\tRozmiar: " << length << endl;
	}
//
	void Array::reset(){
		double * tmp = new double [1];
		delete [] array;
		array=tmp;
		amor=1;
		length=1;
	}
#endif