#ifndef Node_HPP
#define Node_HPP
#include <iostream>

class Node 
{
	Node *prev; //wskaznik na poprzednie ogniwo
	Node *next; //wskaznik na nastepne ogniwo
	int value;  //zawartosc ogniwa
public:
	Node(){        //konstruktor
		prev=NULL;
		next=NULL;
		value=0;
	}
// 
	int get_value(){   //zwraca wartosc ogniwa
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
	friend class List; 
	friend class Queue;
	friend class Stack;
};

#endif
