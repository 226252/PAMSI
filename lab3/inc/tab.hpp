#ifndef tab_HPP
#define tab_HPP
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

template <typename T>
class tab       //
{
	int length;        //dlugosc tblicy
	T * tablica;  //dynamiczna tablica
	int amor;          //wolne miejsce w tablicy
public:
	friend void measures(int, int);
	T & operator[](int element) {return tablica[element];} //przeciazenie operatora []
// konstruktory i destruktory
	tab(){
		length=1;
		amor=1;
		tablica = new T [1];
	}
// 
	tab(int x){
		length=x;
		amor =x;
		tablica = new  T [length];
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
			cout << fixed << setprecision(2) << tablica[i]<<" "<<endl;
		}
		cout << endl << "thats all" << endl;
	}
// 
	void enlarge(unsigned int new_length){
		T * tmp = new T [new_length];
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
};
#endif