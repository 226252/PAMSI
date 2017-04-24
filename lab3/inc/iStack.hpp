#ifndef iStack_HPP
#define iStack_HPP
#include <iostream>
#include "Node.hpp"
#include "iRunable.hpp"

class iStack : public iRunable 
{
public:
	iStack(){}
	virtual ~iStack(){}
// 
	virtual void add(int a)=0;
	virtual int get()=0;
	virtual int get(Node *a)=0;
	virtual int get_size()=0;
	virtual Node* find_value(int a)=0;
	virtual void remove(Node *a)=0;
	virtual void print()=0;
	virtual bool is_empty()=0;
	virtual std::string type()=0;
	virtual void flush()=0;
// 
	virtual int top()=0;	
	virtual void push(int a)=0; 
	virtual void pop()=0;	
};
#endif