#ifndef algorytm_tab_HPP
#define algorytm_tab_HPP
#include <iostream>
#include "base.hpp"
// #include "tab.hpp"
using namespace std;

void algorytm_tab_add1(int x){
		tab<double> pomiar_add1(1);
		for(int j=0; j<x; j++){
			
			if(!pomiar_add1.amor){ 							 //jesli nie ma miejsca tablica zostanie powiekszona o 1
				pomiar_add1.enlarge((pomiar_add1.length)+1); //powiekszenie tablicy o 1 
				j--; 					 //zmniejszenie licznika petli w celu nie wyjscia poza zaalokowana pamiec dla tablicy
			}
			else{
				pomiar_add1[j]=2; // w przypadku wolnego miejsca, dopisana zostaje randomowa wartosc
				pomiar_add1.amor--;     // ilosc miejsc wolnych zmniejszaz sie o 1
			}
		}
}

void algorytm_tab_x2(int x){
		tab<double> pomiar_x2(1);	//inicjalizacja tablicy na ktorej wykonane zostana pomiary dla zwiekszania dwukrotnie
		for(int j=0; j<x; j++){
			if(!pomiar_x2.amor){
				pomiar_x2.enlarge(2*(pomiar_x2.length)); //powiekszenie tablicy dwukrotnie 
				j--;
				// cout << "powiekszyle sie" << endl;
			}
			else{
				pomiar_x2[j]=rand ();
				pomiar_x2.amor--;
				// cout << "dodale sie" << endl;
			}
		}
}
#endif