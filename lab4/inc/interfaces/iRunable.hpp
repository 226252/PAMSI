#ifndef iRunable_HPP
#define iRunable_HPP
#include <iostream>
using namespace std;

class iRunable
{
public:
	iRunable(){}
	virtual ~iRunable(){}
	//
	virtual void run(char option)=0;
	virtual double run_with_time(char option)=0;
	//
	virtual void info()=0;
	//
	virtual void prepare(char prepare_option)=0;
	virtual void output()=0;
};
#endif
