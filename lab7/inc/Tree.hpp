#ifndef Tree_HPP
#define Tree_HPP
#include <iostream>
#include "interfaces/iRunable.hpp"
#include "TreeNode.hpp"
#include "timer.hpp"
#include <cstdlib>


template <typename TYP>
class Tree :public iRunable
{

    TreeNode<TYP> guard;             
    TreeNode<TYP>* root;        
    string cr,cl,cp;     
    string what;
    int addedElements;
    bool Prepared;  

    void printRBT(string sp, string sn, TreeNode<TYP>* p); 

  public:
    Tree();             
    ~Tree();            
    void flush(TreeNode<TYP>* p); 
    void print();          
    TreeNode<TYP>* find(int k); 
    TreeNode<TYP>* find_minimum(TreeNode<TYP>* p); 
    TreeNode<TYP>* find_succesor(TreeNode<TYP>* p);
    void rot_L(TreeNode<TYP>* A);
    void rot_R(TreeNode<TYP>* A);
    void add(int k);
    void remove(TreeNode<TYP>* X);
    bool isPrepared();
    //irunable
    void run(char option=' ');
    double run_with_time(char option=' ');
    void info();
    void prepare(int prepare_quantity, char prepare_option=' ');
    void output();
    void reset();

};

template <typename TYP>
Tree<TYP>::Tree(){
  cr = cl = cp = "  ";
  cr[0] = 218; cr[1] = 196;
  cl[0] = 192; cl[1] = 196;
  cp[0] = 179;
  guard.color = 'B';          
  guard.up    = &guard;
  guard.left  = &guard;
  guard.right = &guard;
  root    = &guard;
  what="Bred tree";     
  addedElements=0; 
  Prepared=false;     
}

template <typename TYP>
Tree<TYP>::~Tree(){
  flush(root);     
}

template <typename TYP>
void Tree<TYP>::flush(TreeNode<TYP>* p){
  if(p != &guard)
  {
    flush(p->left);   
    flush(p->right);  
    delete p;         
  }
  root=&guard;
  Prepared=false;
  addedElements=0;
}

template <typename TYP>
void Tree<TYP>::printRBT(string sp, string sn, TreeNode<TYP>* p){
  string t;

  if(p != &guard)
  {
    t = sp;
    if(sn == cr) t[t.length() - 2] = ' ';
    printRBT(t+cp,cr,p->right);

    t = t.substr(0,sp.length()-2);
    cout << t << sn << p->color << ":" << p->key << endl;

    t = sp;
    if(sn == cl) t[t.length() - 2] = ' ';
    printRBT(t+cp,cl,p->left);
  }
}

template <typename TYP>
void Tree<TYP>::print(){
  printRBT("","",root);
}

template <typename TYP>
TreeNode<TYP>* Tree<TYP>::find(int k){
  TreeNode<TYP>* p;

  p = root;
  while((p != &guard) && (p->key != k))
    if(k < p->key) p = p->left;
    else           p = p->right;
  if(p == &guard) return NULL;
  return p;
}

template <typename TYP>
TreeNode<TYP>* Tree<TYP>::find_minimum(TreeNode<TYP> * p){
  if(p != &guard)
    while(p->left != &guard) p = p->left;
  return p;
}

template <typename TYP>
TreeNode<TYP>* Tree<TYP>::find_succesor(TreeNode<TYP> * p){
  TreeNode<TYP>* r;

  if(p != &guard)
  {
    if(p->right != &guard) return find_minimum(p->right);
    else
    {
      r = p->up;
      while((r != &guard) && (p == r->right))
      {
        p = r;
        r = r->up;
      }
      return r;
    }
  }
  return &guard;
}

template <typename TYP>
void Tree<TYP>::rot_L(TreeNode<TYP>* A){
  TreeNode<TYP>* B, *p;

  B = A->right;
  if(B != &guard)
  {
    p = A->up;
    A->right = B->left;
    if(A->right != &guard) A->right->up = A;

    B->left = A;
    B->up = p;
    A->up = B;

    if(p != &guard)
    {
      if(p->left == A) p->left = B; else p->right = B;
    }
    else root = B;
  }
}

template <typename TYP>
void Tree<TYP>::rot_R(TreeNode<TYP>* A){
  TreeNode<TYP>* B, *p;

  B = A->left;
  if(B != &guard)
  {
    p = A->up;
    A->left = B->right;
    if(A->left != &guard) A->left->up = A;

    B->right = A;
    B->up = p;
    A->up = B;

    if(p != &guard)
    {
      if(p->left == A) p->left = B; else p->right = B;
    }
    else root = B;
  }
}

template <typename TYP>
void Tree<TYP>::add(int k){
  TreeNode<TYP>* X, *Y;

  X = new TreeNode<TYP>;       
  X->left  = &guard;          
  X->right = &guard;
  X->up    = root;
  X->key   = k;
  if(X->up == &guard) root = X;
  else
  while(true)             
  {
    if(k < X->up->key)
    {
      if(X->up->left == &guard)
      {
        X->up->left = X;  
        break;
      }
      X->up = X->up->left;
    }
    else
    {
      if(X->up->right == &guard)
      {
        X->up->right = X; 
        break;
      }
      X->up = X->up->right;
    }
  }
  X->color = 'R';         
  while((X != root) && (X->up->color == 'R'))
  {
    if(X->up == X->up->up->left)
    {
      Y = X->up->up->right;

      if(Y->color == 'R')  
      {
        X->up->color = 'B';
        Y->color = 'B';
        X->up->up->color = 'R';
        X = X->up->up;
        continue;
      }

      if(X == X->up->right) 
      {
        X = X->up;
        rot_L(X);
      }

      X->up->color = 'B'; 
      X->up->up->color = 'R';
      rot_R(X->up->up);
      break;
    }
    else
    {                  
      Y = X->up->up->left;

      if(Y->color == 'R')
      {
        X->up->color = 'B';
        Y->color = 'B';
        X->up->up->color = 'R';
        X = X->up->up;
        continue;
      }

      if(X == X->up->left) 
      {
        X = X->up;
        rot_R(X);
      }

      X->up->color = 'B'; 
      X->up->up->color = 'R';
      rot_L(X->up->up);
      break;
    }
  }
  root->color = 'B';
  addedElements++;
}

template <typename TYP>
void Tree<TYP>::remove(TreeNode<TYP> * X){
  TreeNode<TYP>* W, *Y, *Z;

  if((X->left == &guard) || (X->right == &guard)) Y = X;
  else	Y = find_succesor(X);

  if(Y->left != &guard) Z = Y->left;
  else	Z = Y->right;

  Z->up = Y->up;

  if(Y->up == &guard) root = Z;
  else if   (Y == Y->up->left) Y->up->left  = Z;
  else	Y->up->right = Z;

  if(Y != X) X->key = Y->key;

  if(Y->color == 'B')   
    while((Z != root) && (Z->color == 'B'))
      if(Z == Z->up->left)
      {
        W = Z->up->right;

        if(W->color == 'R')
        {              
          W->color = 'B';
          Z->up->color = 'R';
          rot_L(Z->up);
          W = Z->up->right;
        }

        if((W->left->color == 'B') && (W->right->color == 'B'))
        {              
          W->color = 'R';
          Z = Z->up;
          continue;
        }

        if(W->right->color == 'B')
        {              
          W->left->color = 'B';
          W->color = 'R';
          rot_R(W);
          W = Z->up->right;
        }

        W->color = Z->up->color; 
        Z->up->color = 'B';
        W->right->color = 'B';
        rot_L(Z->up);
        Z = root; 
      }
      else
      {           
        W = Z->up->left;

        if(W->color == 'R')
        {          
          W->color = 'B';
          Z->up->color = 'R';
          rot_R(Z->up);
          W = Z->up->left;
        }

        if((W->left->color == 'B') && (W->right->color == 'B'))
        {          
          W->color = 'R';
          Z = Z->up;
          continue;
        }

        if(W->left->color == 'B')
        {          
          W->right->color = 'B';
          W->color = 'R';
          rot_L(W);
          W = Z->up->left;
        }

        W->color = Z->up->color; 
        Z->up->color = 'B';
        W->left->color = 'B';
        rot_R(Z->up);
        Z = root;         
      }

  Z->color = 'B';

  delete Y;
  addedElements--;
}
//
template <typename TYP>
bool Tree<TYP>::isPrepared(){
	return Prepared;
}
//
template <typename TYP>
void Tree<TYP>::run(char option){
	int whatWeLookFor;
	whatWeLookFor=(rand() % (addedElements/2)) + (addedElements/4);
	Tree::find(1);
}
//
template <typename TYP>
double Tree<TYP>::run_with_time(char option){
	timer<nanoseconds> t;
	t.begin();
	Tree::run();
	t.stop();
	return t.duration();
}
//
template <typename TYP>
void Tree<TYP>::info(){
	cout<<"Data structure: "<<what<<endl;
	cout<<"Added Elements: "<<addedElements<<endl;
}
//
template <typename TYP>
void Tree<TYP>::prepare(int prepare_quantity,char prepare_option){
	if(Tree::isPrepared()){Tree::flush(root);}
	for(int i=1; i<=prepare_quantity; i++){
		Tree::add(i);
	}
	Prepared=true;
}
//
template <typename TYP>
void Tree<TYP>::output(){
	Tree::print();
}
//
template <typename TYP>
void Tree<TYP>::reset(){
	Tree::flush(root);
}
#endif
