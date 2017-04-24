#ifndef iList_HPP
#define iList_HPP
#include <iostream>
#include "Node.hpp"
#include "iRunable.hpp"
class iList : public iRunable
{
public:
	iList(){};
	virtual ~iList(){};
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
};
#endif 
