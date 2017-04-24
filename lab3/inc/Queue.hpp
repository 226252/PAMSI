#ifndef Queue_HPP
#define Queue_HPP
#include <iostream>
#include "Node.hpp"
#include "iQueue.hpp"
using namespace std;

class Queue : public iQueue
{
	Node *head; //pierwszy element
	Node *tail; //ostatni element
	int size;    
	string what; //czym jestem
public:
	Queue(){
		head=nullptr;
		tail=nullptr;
		size=0;
		what="Queue";
	}
//
	void add(int a){ //dodanie nowego ogniwa zaraz po tailu, wartosc ogniwa to a 
		Node * new_ = new Node; //stworzenie nowego ogniwa
		if (!size){        //sprawdzenie czy kolejka jest pusta
			head=new_;
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
		if(a->prev==nullptr && a->next!=nullptr){  //jesli a jest na poczatku kolejki
			a->next->prev=nullptr;
			head=a->next;
		}
		if(a->prev!=nullptr && a->next!=nullptr){ //jesli a znajduje sie w srodku stosu
			a->prev->next=a->next;
			a->next->prev=a->prev;
		}
		if(a->next==nullptr && a->prev!=nullptr){  //jesli na koncu
			a->prev->next=nullptr;
			tail=a->prev;
		}
		size--; //rozmiar sie zmniejsza
		delete a; //zwolnienie pamieci
	
	}
//
	void push(int a){ //dodanie na koniec kolejki
	 	add(a);
	}
// 

	void pop(){ //wyrzuca ostatni element ze stosu
		if(!size){
			cout << "Kolejka pusta\n";
		} else{
			remove(head);
		}
	}
//
	int end(){//zwraca wartosc pierwszego elementu w kolejce
		return head->value;
	}
//
	Node* find_value(int a){ //funkcja wyszukuje ogniwo ktore posiada wartosc a i zwraca do niego wskaznik
		while(size){
			if(head->value==a){
				return head;
			} 
			pop();
		}
		cout <<"nie ma mnie tu wiec moj adres to";
		return nullptr;
	}
//
	int get_size(){  //zwraca rozmiar
		return size;
	}
//
	int get(){ //zwraca wartosc pierwszego elementu jak to teraz pisze to nie wiem po co mi end w takim wypadku
		return head->value;
	}
//
	int get(Node *a){ //zwraca wartosc podanego elementu
		return a->value;
	}
//
	bool is_empty(){ //sprawdza czy pusty
		if(!size){
			return true;
		} else{
			return false;
		}
	}
//
	void print(){
		Node* tmp;
		tmp=head;
		for(int i=0; i<size; i++){
			cout << tmp->value << "\n";
			tmp=tmp->next;
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