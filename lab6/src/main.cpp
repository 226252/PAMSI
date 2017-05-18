#include "../inc/Array.hpp"
#include "../inc/algorithms/Quick_sort.hpp"
#include "../inc/measures.hpp"
#include <cstdlib>
#include <iostream>
#include "../inc/Map.hpp"
using namespace std;
#include <string>

int main(){	
	Map m(20);
	string s;
	for(int i=0;i<m.get_size();i++){
		cout<<"podej suowo xD: ";
		cin>>s;
		m.insert(s);
	}
	m.show();
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

