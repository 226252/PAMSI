#include "../inc/iRunable.hpp"
#include "../inc/Stack.hpp"
#include "../inc/List.hpp"
#include "../inc/Queue.hpp"
#include "../inc/Timer.hpp"
#include "../inc/tab.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

void measures(int a, int b, iRunable &x){ //a- ile elementow, b-ile testow, x obiekt na ktorym bedziemy pracowac
	Timer<microseconds> t;
	int when; //kiedy wrzucic szukana wartosc
	tab<float> results(b);
	when=(rand() & (a/2)) + (a/4); //kiedy wrzucic szukana wartosc
	for(int j=0; j<b; j++){
		for(int i=0; i<a; i++){
			if(i!=when){
				x.add( ( (rand() & 10000) + 100) ); //wrzuca losowe liczby od 100 do 100+10000
			} else{
				x.add(2); //szukana wartosc
			}
		}
		t.begin();
		x.find_value(2);
		t.stop();
		results[j]=t.duration();
		x.flush();
	}
	cout << "-----------------------------------------------\n";
	cout <<  x.type()<<endl;
	cout <<a << " elementow-";
	cout << results.mean() <<" mikrosekund\n";
	cout << "zrobilem to: " << b << " razy\n";
	cout << "-----------------------------------------------\n";
}
int obsluga_argumentow(int argc, char* argv[]){
	argc--; //przy podaniu 3 argumentow argc wynosi 4 ???
	if(argc!=0 && *argv[1]=='h'){
		cout<< endl;
		cout<<"HELP\n\tDla poprawnego uzycia uzyj 3 flag\n";
		cout<<"\tPierwsza <liczba> liczba elementow na jakich ma pracowac struktura\n";
		cout<<"\tDruga <liczba> ilosc powtorzen pomiaru\n";
		cout<<"\tTrzecia <litera> struktura na jakiej maja byc wykonane pomiary\n";
		cout<<"\tDostepne struktury:\n";
		cout<<"\t-s Stack\n";
		cout<<"\t-l List\n";
		cout<<"\t-q Queue\n";
		cout<<"\tPrzykladowe wywolanie:\t./program 100 100 q\n";
		cout<<"\tTo wszystko :)\n";
		return 0;
	}
	if(argc>3){
		cout<<"BLAD-za duzo argumentow\n By uzyskac pomoc uzyj flagi h\n";
		return 0;
	}
	if(argc<=2){
		cout<<"BLAD-za malo argumentow\n By uzyskac pomoc uzyj flagi h\n";
		return 0;
	}
	if(!atoi(argv[1]) || !atoi(argv[1])){
		cout<<"BLAD-pierwszy lub drugi argument to nie liczba\n By uzyskac pomoc uzyj flagi h\n";
		return 0;
	}	
	return 1;
}

int main(int argc, char* argv[]){
	srand(time(NULL)); //zapewnia losowosc przy kazdym kolejnym odpaleniu programu
	List l;
	Stack s;
	Queue q;
	if(obsluga_argumentow(argc, argv)){
		if(*argv[3]=='l'){
			measures(atoi(argv[1]), atoi(argv[2]), l);
		}
		if(*argv[3]=='s'){
			measures(atoi(argv[1]), atoi(argv[2]), s);
		}
		if(*argv[3]=='q'){
			measures(atoi(argv[1]), atoi(argv[2]), q);
		}else{
			cout<<"BLAD-niepoprawny ostatni argument\n By uzyskac pomoc uzyj flagi h\n";
			return 0;
		}
	}
return 0;
}
