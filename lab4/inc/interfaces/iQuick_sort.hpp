#ifndef iQuicksort_HPP
#define iQuicksort_HPP
#include <iostream>
using namespace std;



class iQuick_sort
{
public:
	//konstruktory
	iQuick_sort(){}
	virtual ~iQuick_sort(){}
	//metody konieczne do wykonania algorytmu 
	virtual int get_length()const=0;
	virtual void change_place(int a, int b)=0;
	virtual int & operator[](int element)=0;
	//
	virtual void info()=0;
	//
	virtual void prepare(char prepare_option)=0;
	virtual void output()=0;
};

#endif
		