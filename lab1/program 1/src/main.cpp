#include "../inc/tab.hpp"
#include "../inc/clock_.hpp"
#include<iostream>
using namespace std;
void measures(int x, int y, int z){ //funckja wykonujaca pomiary czasu, x rozmiar badanej tablicy, y ilosc powtorzen mierzenia czasu
	clock_ t1, t2;
	tab wyniki_add1(y); //inicjalizacja tablicy do ktorej zapisane zostana pomiar dla powiekszania o 1
	tab wyniki_x2(y);   //inicjalizacja tablicy do ktorej zapisane zostana pomiar dla powiekszania razy dwa
	if(z){
		for(int i=0; i<y; i++){
		tab pomiar_add1(1); //inicjalizacja tablicy na ktorej wykonane zostana pomiary dla zwiekszania o 1
		t1.begin();       //rozpoczecie mierzenia czasu
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
		t1.stop();        //koniec pomiaru czasu
		wyniki_add1[i]=t1.duration(); //wpisanie wyniku do tablicy
		}

	}
	else{
		for(int i=0; i<y; i++){
		tab pomiar_x2(1);	//inicjalizacja tablicy na ktorej wykonane zostana pomiary dla zwiekszania dwukrotnie
		t2.begin();
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
		t2.stop();
		wyniki_x2[i]=t2.duration();
		// delete [] pomiar_x2.tablica;
		}
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
	int z;
	cin >> z; //zmienna sluzaca do wyboru czy program ma wykonywac obliczania dla z=0 metoda dwukrotnego powiekszania z=/= metoda zwiekszania o 1
	for (int i=0; i<4; i++){
		cout << "*************" << endl;
		measures(x, y, z);
		cout << "-*************" << endl;
		x=x*10;
	}	
	return 0;
}