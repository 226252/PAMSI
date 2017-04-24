#ifndef tab_HPP
#define tab_HPP
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;
class tab              //
{
	int length;        //dlugosc tblicy
	double * tablica;  //dynamiczna tablica
	void enlarge(unsigned int); //funkcja powiekszania, przyjmowany argument mowi do ilu ziwekszyc tablice
	int amor;          //wolne miejsce w tablicy
public:
	//konstruktory, metody 
	tab(int);
	void input();      //metoda sluzaca do wpisywania z klawiatury elementow tablicy
	~tab(); 
	void fill_rand(int);//wypelnia tablice randomowymi liczbami, argument mowi jaki jest zakres randomowych liczb
	void output();      //wypisuje wartosci tablicy
	int size();         //zwraca rozmiar tablicy
	void size_out();	//wypisuje rozmiar tablicy
	int get_amor();    //zwraca dlugosc amora
	friend void measures(int, int, int); //zaprzyjazniona funkcja sluzaca do pomiarow
	double mean(); //funkcja zwracajaca srednia wszystkich elementow tablicy 
	//przeciazenia
	double & operator[](int element) {return tablica[element];} //przeciazenie operatora []
};
// 
tab::tab(int x){
	length=x;
	amor =x;
	tablica = new  double [length];

}
//
tab::~tab(){
	delete [] tablica;
} 
// 
void tab::input(){
	int tmp;
	for (int i=0; i<length; i++){
		cout << "podaj element nr " << i+1 << ": ";
		cin >> tmp;
		tablica[i]=tmp;
	}
	amor=0;
}
//
void tab::fill_rand(int range){
	for (int i=0; i<length; i++){
		tablica[i]=rand() % range;
	}
	amor=0;
}
// 
void tab::output(){
	for(int i=0; i<length; i++){
		cout << fixed << setprecision(2) << tablica[i]<<" "<<endl;
	}
	cout << endl << "thats all" << endl;
}
// 
void tab::size_out(){
	cout<< endl << "ilosc elementow " << length << endl;
}
// 
int tab::size(){
	return length;
}
//
int tab::get_amor(){
	return amor;
}
// 
void tab::enlarge(unsigned int new_length){
	double * tmp = new double [new_length];
	for (int i=0; i<length; i++){
		tmp[i]=tablica[i];
	}
	delete [] tablica;
	tablica=tmp;
	amor=new_length-(length-amor);
	length=new_length;
}
// 
double tab::mean(){
	double x;
	x=0;
	for(int i=0; i<length; i++){
		x=x+tablica[i];
	}
	return x/length;
}

#endif