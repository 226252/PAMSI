#ifndef Node_HPP
#define Node_HPP
#include <iostream>



template <typename TYP>
struct Node 
{
	Node<TYP> *prev; //wskaznik na poprzednie ogniwo
	Node<TYP> *next; //wskaznik na nastepne ogniwo
	TYP value;  //zawartosc ogniwa
public:
	Node(){        //konstruktor
		prev=NULL;
		next=NULL;
		// value=0;
	}
// 
	TYP get_value(){   //zwraca wartosc ogniwa
		return value;
	}
//
	Node* get_next(){
		return next;
	}
//
	Node* get_prev(){
		return prev;
	}
// przyjaciele wykorzystujacy ogniwa
	template<typename List_TYP>
	friend class List;
	friend class Queue;
	friend class Stack;
	friend class Map;
};

#endif
