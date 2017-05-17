#include "../inc/Array.hpp"
#include "../inc/algorithms/Quick_sort.hpp"
#include "../inc/measures.hpp"
#include <cstdlib>
#include <iostream>
using namespace std;


int main(){	
	Array array;
	Quick_sort Qsort_algorithm(array);
	int elements[8]={100, 500, 1000, 5000, 10000, 20000, 50000, 100000};
	ofstream datafile;
	datafile.open("measures");
	datafile<<"Czas w mikrosekundach\n";
	datafile<<"Rosnaca\n N:\t f:\t m:\t l:\n";
	for(int i=0; i<2; i++){
		datafile<<elements[i]<<"\t";
		datafile<<measures(Qsort_algorithm,elements[i],'r','f')<<"\t";
		datafile<<measures(Qsort_algorithm,elements[i],'r','m')<<"\t";
		datafile<<measures(Qsort_algorithm,elements[i],'r','l')<<"\n";
	}
	datafile<<"Malejaca\n N:\t f:\t m:\t l:\n";
	for(int i=0; i<2; i++){
		datafile<<elements[i]<<"\t";
		datafile<<measures(Qsort_algorithm,elements[i],'m','f')<<"\t";
		datafile<<measures(Qsort_algorithm,elements[i],'m','m')<<"\t";
		datafile<<measures(Qsort_algorithm,elements[i],'m','l')<<"\n";
	}

	datafile<<"Random\n N:\t f:\t m:\t l:\n";
	for(int i=0; i<2; i++){
		datafile<<elements[i]<<"\t";
		datafile<<measures(Qsort_algorithm,elements[i],'l','f')<<"\t";
		datafile<<measures(Qsort_algorithm,elements[i],'l','m')<<"\t";
		datafile<<measures(Qsort_algorithm,elements[i],'l','l')<<"\n";
	}
	return 0;
	

}

//Idea dzialania programu
//	prosze o przeczytanie i ewentualne wskazanie
//	bledow w mysleniu
//W mainie tworzymy obiekt ktory bedzie badany,
//	wrzucamy go nastepnie do algorytmu, ktory chcemy wykonac
//	z wykorzystaniem danej struktury
//Struktury danych (array, list itd) dziedzicza po interfejsie
//	glownym irunable i po interfejsach algorytmow(np iQuicksort).
//	Struktury dzidzicza tylko te interfejsy pod ktore pasuja.
//	Array dziedziczy po iQuicksortable bo da sie go posortowac
//	uzywajac QSorta, a klasa kwadrat (przyklad) juz nie dziedziczy
//	bo nie da sie sortowac kwadratu (no_sh**_sherlock.png).
//Funkcja measures zostaje tworzona przy kazdym nowym projekcie
//	w taki sposob by wykonywac swoja funkcje.
//	Przyjmuje tylko referencje do obiektow iRunable,
//	w srodku zostaje przygotowana struktura,
//	np. tablica zostaje wypelniona randomowo,
//	nastepnie zegar startuje, wykonana zostaje
//	metoda virtualna run(), zegar stopuje
//	edit. Po dluzszym namysle funkcja measures
//	moze pozostawac zawsze taka sama
//	przyjmowac: &iRunable obiekt
//	{ 
// 	obiekt.prepare(opcja1, opcja2)
//	clock.start(), obiekt.run(), clock.stop()
//	}	
// koniec funkcji measures zwraca oczywiscie czas

