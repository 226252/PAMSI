#ifndef tab_HPP
#define tab_HPP
#include <iostream>
#include <cstdlib>
#include <iomanip>
// #include "../inc/base.hpp"
using namespace std;

 	
class tab 
{
	int length;       
	int * tablica;  
	int amor;          
	//amor wolne miejsce w tablicy
public:
	int & operator[](int element) {return tablica[element];}
	
	tab(){
		length=1;
		amor=1;
		tablica = new int [1];
	}
// 
	tab(int x){
		length=x;
		amor =x;
		tablica = new  int [length];
	}
//
	~tab(){
		delete [] tablica;
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
			tablica[i]=tmp;
		}
		amor=0;
	}
//
	void add(int place, int value){
		if(place<0 && place>=length){
			cout<< "Odwolujesz sie do miejsca przed/za tablica, to nie pyton ;)\n";
		} 
		else{
			tablica[place]=value;
			if(((length-1)-place)<amor){ //sprawdzasz czy dodajac element nie zmniejszy sie odleglosc ostatniego elementu od konca tablicy i ewentualnie zmieniasz wartosc amortyzacji
				amor=(length-1)-place;
			}
		}

	}
// metody
	void fill_rand(int range){
		for (int i=0; i<length; i++){
			tablica[i]=rand() % range;
		}
		amor=0;
	}
// 
	void output()const{
		for(int i=0; i<length; i++){
			cout << fixed << setprecision(2) << tablica[i]<<" ";
		}
		cout << "thats all" << endl;
	}
// 
	void enlarge(unsigned int new_length){
		int * tmp = new int [new_length];
		for (int i=0; i<length; i++){
			tmp[i]=tablica[i];
		}
		delete [] tablica;
		tablica=tmp;
		amor=new_length-(length-amor);
		length=new_length;
	}
// 
	double mean()const{
		double x;
		x=0;
		for(int i=0; i<length; i++){
			x=x+tablica[i];
		}
		return x/length;
	}
// 
	void change_place(int a, int b){
		int first;
		first=tablica[a];
		tablica[a]=tablica[b];
		tablica[b]=first;
	}
//
	void equals(tab t){
	if(t.get_length()==length){
		for(int i=0; i<length; i++){
			tablica[i]=t[i];
		}
	}
	else{
		enlarge(t.get_length());
		for(int i=0; i<length;i++){
		tablica[i]=t[i];	
		}
	}
	
	}
//
		
	void fill(char option){
		
		if(option=='r'){
			for(int i=0; i<length;i++){
				tablica[i]=i+1;
			}
		}

		if(option=='m'){
			for(int i=0; i<length; i++){
				tablica[i]=length-i;
			}
		}
		
		if(option=='l'){
			fill_rand(100);
		}
	
	}
//
};
#endif