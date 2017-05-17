#ifndef Stack_HPP
#define Stack_HPP
#include <iostream>
using namespace std;
#include "iStack.hpp"
#include "Node.hpp"

class Stack : public iStack
{
	Node* tail; //wskaznik na ostatni element stosu
	int size;
	string what; //czym jestem
public:
	Stack(){       //konstruktor
		tail=nullptr;
		size=0;
		what="Stack";
	}
//
	void add(int a){ //dodanie nowego ogniwa zaraz po tailu, wartosc ogniwa to a 
		Node * new_ = new Node; //stworzenie nowego ogniwa
		if (tail==nullptr){        //sprawdzenie czy stos jest pusty
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
		if(a->prev==nullptr && a->next!=nullptr){  //jesli a jest na spodzie stosu
			a->next->prev=nullptr;
			// head=a->next;
		}
		if(a->prev!=nullptr && a->next!=nullptr){ //jesli a znajduje sie w srodku stosu
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
	void push(int a){ //dodanie nowego elementu na gore stosu
		add(a);
	}
//
	void pop(){ //wyrzuca ostatni element ze stosu
			if(!size){
			cout << "Nie ma nic do wyrzucenia\n";
		} else{
			remove(tail);
		}
	}
//
	int top(){//zwraca wartosc ostatniego elementu
		return tail->value;
	}
//
	Node* find_value(int a){ //funkcja wyszukuje ogniwo ktore posiada wartosc a i zwraca do niego wskaznik
		while(size){
			if(tail->value==a){
				// cout <<"jestem tutaj(adres) ";
				return tail;
			} 
			pop();
		}
		cout <<"nie ma mnie tu wiec moj adres to ";
		return nullptr;
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
	void print(){
		Node* tmp;
		tmp=tail;
		for(int i=size; i>0; i--){
			cout << tmp->value << "\n";
			tmp=tmp->prev;
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