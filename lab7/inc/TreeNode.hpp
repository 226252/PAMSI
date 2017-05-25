#ifndef TreeNode_HPP
#define TreeNode_HPP
#include <iostream>



template <typename TYP>
struct TreeNode 
{
	TreeNode<TYP> *left; 
	TreeNode<TYP> *right;
	TreeNode<TYP> *up;
	TYP key;  
	char color;
public:
	TreeNode(){        
		left=NULL;
		right=NULL;
	}
// 
	TYP get_key(){   
		return key;
	}
//
	TreeNode* get_right(){
		return right;
	}
//
	TreeNode* get_left(){
		return left;
	}
//
	char get_color(){
		return color;
	}
//

};

#endif
