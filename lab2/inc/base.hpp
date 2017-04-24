#ifndef base_HPP
#define base_HPP
#include <iostream>
using namespace std;



// template <typename T>
class base
{
public:
	int length;
	int amor;
	friend void measures(int, int);
	//konstruktory i destruktory
	base(){};
	virtual ~base(){};
	//gety
	virtual int get_length()const=0;
	virtual int get_amor()const=0;
	//metody
	virtual void input()=0;
	virtual void add(int place, int value)=0;
	virtual void fill_rand(int range)=0;
	virtual void output()const=0;//wypisywanie elementow na cout
	virtual void enlarge(unsigned int)=0; //powiekszanie
	virtual double mean()const=0;
};
#endif