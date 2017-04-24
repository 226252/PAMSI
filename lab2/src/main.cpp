#include "../inc/tab.hpp"
#include "../inc/clock_.hpp"
#include "../inc/algorytm_tab.hpp"
#include<iostream>
using namespace std;
void measures(int x, int y){ //funckja wykonujaca pomiary czasu, x rozmiar badanej tablicy, y ilosc powtorzen mierzenia czasu
	clock_ t1, t2;
	tab<double> wyniki_add1(y); //inicjalizacja tablicy do ktorej zapisane zostana pomiar dla powiekszania o 1
	tab<double> wyniki_x2(y);   //inicjalizacja tablicy do ktorej zapisane zostana pomiar dla powiekszania razy dwa
	
		for(int i=0; i<y; i++){
		// tab<int> pomiar_add1(1); //inicjalizacja tablicy na ktorej wykonane zostana pomiary dla zwiekszania o 1
		t1.begin();       //rozpoczecie mierzenia czasu
		algorytm_tab_add1(x);
		t1.stop();        //koniec pomiaru czasu
		wyniki_add1[i]=t1.duration(); //wpisanie wyniku do tablicy
		}

	
	
		for(int i=0; i<y; i++){
		// tab<int> pomiar_x2(1);	//inicjalizacja tablicy na ktorej wykonane zostana pomiary dla zwiekszania dwukrotnie
		t2.begin();
		algorytm_tab_x2(x);
		t2.stop();
		wyniki_x2[i]=t2.duration();
		// delete [] pomiar_x2.tablica;
		}
	
	cout<< "wyniki dla " << x << " elementow." << endl;
	cout<< "+1" << endl; 
	wyniki_add1.output();
	cout<< "srednia: " << fixed << setprecision(3) << wyniki_add1.mean();
	cout << endl;
	cout<< "x2" << endl; 
	wyniki_x2.output();
	cout<< "srednia: " <<fixed<<setprecision(3)<< wyniki_x2.mean();
	cout << endl;
}
// 
int main(){
	double x=10;
	int y=20;
	// cout << " 0 - 2krotne powiekszanie\n !0 - powiekszanie o 1\n podaj liczbe: ";
	// int z;
	// cin >> z; //zmienna sluzaca do wyboru czy program ma wykonywac obliczania dla z=0 metoda dwukrotnego powiekszania z=/=0 metoda zwiekszania o 1
	for (int i=0; i<3; i++){
		cout << "*************" << endl;
		measures(x, y);
		cout << "-*************" << endl;
		x=x*10;
	}	
	return 0;
}
