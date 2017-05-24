#ifndef TreeNode_HPP
#define TreeNode_HPP
#include <iostream>



template <typename TYP>
struct TreeNode 
{
	TreeNode<TYP> *left; 
	TreeNode<TYP> *right;
	TYP value;  //zawartosc ogniwa
public:
	TreeNode(){        //konstruktor
		left=NULL;
		right=NULL;
	}
// 
	TYP get_value(){   //zwraca wartosc ogniwa
		return value;
	}
//
	TreeNode* get_right(){
		return right;
	}
//
	TreeNode* get_left(){
		return left;
	}
};

#endif
