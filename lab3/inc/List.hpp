#ifndef List_HPP
#define List_HPP
#include <iostream>
using namespace std;
#include "iList.hpp"
#include "Node.hpp"


class List : public iList
{
public:
	Node *head; //wskaznik na poczatek listy
	Node *tail; //wskaznik na ostatni element tablicy
	int size; //rozmiar listy, 0 oznacza ze lista jest pusta
	string what;
public:
//
	List(){         //konstruktor
		head=nullptr;
		tail=nullptr;
		size=0;
		what = "List";
	}

	void add(int a){ //dodanie nowego ogniwa zaraz po tailu, wartosc ogniwa to a 
		Node * new_ = new Node; //stworzenie nowego ogniwa
		if (head==nullptr){        //sprawdzenie czy lista jest pusta
			head=new_;          //przypisanie wskaznikow na glowe i ogon do pierwszego dodanego elementu
			tail=new_;
			new_->prev=nullptr;     //przypisanie wlasciwych wskznikow do ogniwa
			new_->next=nullptr;
		} else{
			tail->next=new_;
			new_->prev=tail;
			tail=new_;
			new_->next=nullptr;
		}
		new_->value=a;
		size++;
	}
//
	void remove(Node *a){
		if(a->prev==nullptr && a->next!=nullptr){  //jesli a to head
			a->next->prev=nullptr;
			head=a->next;
		}
		if(a->prev!=nullptr && a->next!=nullptr){ //jesli a znajduje sie w srodku listy
			a->prev->next=a->next;
			a->next->prev=a->prev;
		}
		if(a->next==nullptr && a->prev!=nullptr){  //jesli a to tail
			a->prev->next=nullptr;
			tail=a->prev;
		}
		size--; //rozmiar sie zmniejsza
		delete a; //zwolnienie pamieci
	}	
//
	Node* find_value(int a){ //funkcja wyszukuje ogniwo ktore posiada wartosc a i zwraca do niego wskaznik
		Node* tmp;
		tmp=head;
		while(tmp!=nullptr){ //jesli tymczasowy wskaznik bedzie wskazywal na zero oznacza to ze przeszlismy przez cala liste
			if(tmp->value==a){
				// cout<< "jestem tutaj(adres) ";
				return tmp;
			}
			tmp=tmp->next;
		}
		cout <<"nie ma mnie tu wiec moj adres to ";
		return nullptr;
	}
//

	void print(){  //wypisuje po kolei elemety listy
		Node* tmp;
		tmp=head;
		for(int i=0; i<size; i++){
			cout<< tmp->value << "\n";
			tmp=tmp->next;
		}
	}
//
	int get_size(){   //zwraca rozmiar
		return size;
	}
//
	int get(){ //zwraca wartosc ostatniego elementu
		return tail->value;
	}
//
	int get(Node *a){ //zwraca wartosc podanego elementu
		return a->value;
	}
//
	bool is_empty(){	//sprawdza czy jest pusty
		if(!size){
			return true;
		} else{
			return false;
		}
	}
//
	string type(){
		return what;
	}
//
	void flush(){
		while(size){
			remove(tail);
		}
	}
};
#endif


