#ifndef List_HPP
#define List_HPP
#include <iostream>
using namespace std;
#include "interfaces/iRunable.hpp"
#include "Node.hpp"
#include <string>

template <typename TYP>
class List 
{
public:
	Node<TYP> *head; //wskaznik na poczatek listy
	Node<TYP> *tail; //wskaznik na ostatni element tablicy
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

	void add(TYP a){ //dodanie nowego ogniwa zaraz po tailu, wartosc ogniwa to a 
		Node<TYP> *new_ = new Node<TYP>; //stworzenie nowego ogniwa
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
	void remove(Node<TYP> *a){
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
	Node<TYP>* find_value(TYP a){ //funkcja wyszukuje ogniwo ktore posiada wartosc a i zwraca do niego wskaznik
		Node<TYP>* tmp;
		tmp=head;
		while(tmp!=nullptr){ //jesli tymczasowy wskaznik bedzie wskazywal na zero oznacza to ze przeszlismy przez cala liste
			if(tmp->value==a){
				// cout<< "jestem tutaj(adres) ";
				return tmp;
			}
			tmp=tmp->next;
		}
		cout <<"nie ma mnie tu wiec moj adres to nullptr\n";
		return nullptr;
	}
//

	void print(){  //wypisuje po kolei elemety listy
		Node<TYP>* tmp;
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
	TYP get(){ //zwraca wartosc ostatniego elementu
		if(size){
			return tail->value;
		}else{
			cout<<"Trying to get from empty list, aborted\n";
			return;
		}
	}
//
	TYP get(Node<TYP> *a){ //zwraca wartosc podanego elementu
		if(a==nullptr){
			cout<<"Trying to get nullptr, aborted\n";
			return NULL;
		}else{
			return a->value;
		}
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


