#ifndef Tree_HPP
#define Tree_HPP
#include <iostream>
#include "interfaces/iRunable.hpp"
#include "TreeNode.hpp"


template <typename TYP>
class Tree 
{
	TreeNode<TYP> *root;
	int levels;
	string what;
public:
//
	Tree();
	~Tree();
	void add(TYP a);
	TreeNode<TYP>* find_value(TYP a);
	
	void remove(TYP a);
	void walk(TreeNode<TYP> *x);
	void print();
	int get_level();
	bool is_empty(){return false;};
	void flush(){};
};

	template <typename TYP>
	Tree<TYP>::Tree(){
		levels=0;
		what="Binary Tree";
		root=nullptr;
	}
// 
	template <typename TYP>
	Tree<TYP>::~Tree(){
		delete root;
	}
// 
	template <typename TYP>
	void Tree<TYP>::add(TYP a){
		TreeNode<TYP> *new_ = new TreeNode<TYP>;
		TreeNode<TYP> *tmp=root;
		if (root==nullptr && levels==0){        
			root=new_;          
			new_->left=nullptr;     
			new_->right=nullptr;
		} else{
			while(1){
				if(tmp->value==a){
					cout<<a<<" is already added\n";
					break;
				}
				if(tmp->value<a){
					if(tmp->right==nullptr){
						tmp->right=new_;
						break;
					}else{
						tmp=tmp->right;
					}
				}

				if(tmp->value>a){
					if(tmp->left==nullptr){
						tmp->left=new_;
						break;
					}else{
						tmp=tmp->left;
					}
				}
			}
		}
		new_->value=a;
		levels++;
	}
// 
	template <typename TYP>
	TreeNode<TYP>* Tree<TYP>::find_value(TYP a){
		TreeNode<TYP>* tmp=root;
		while(tmp->left!=nullptr && tmp->right!=nullptr){
			if(a==tmp->value){
				return tmp;
			}
			if(a<tmp->value){
				tmp=tmp->left;
			}else{
				tmp=tmp->right;
			}
		}
		cout<<"Such value does not belong to this tree\n";
		return nullptr;
	}
// 
	template <typename TYP>
	void Tree<TYP>::remove(TYP a){
		TreeNode<TYP>* tmp;
		tmp=Tree::find_value(a);
		if(tmp==nullptr){
			cout<<"There is nothing to remove\n";
		}else{
			delete tmp;
		}
	}
// 
	template <typename TYP>
	void Tree<TYP>::walk(TreeNode<TYP> *x){
		if(x!=nullptr){
			Tree::walk(x->left);
			cout<<x->value<<" ";
			Tree::walk(x->right);
		}
	}
// 
	template <typename TYP>
	void Tree<TYP>::print(){
		Tree::walk(root);
	}
//
	template <typename TYP>
	int Tree<TYP>::get_level(){
		return levels;
	} 
#endif
