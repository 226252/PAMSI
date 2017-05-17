#ifndef Map_HPP
#define Map_HPP
#include <iostream>
#include "algorithms/Hash.hpp"
#include "interfaces/iRunable.hpp"
#include "List.hpp"
#include "Node.hpp"
class Map :public iRunable
{
	List<string> array[20];
	string what;
public:
	Map();
	void insert(string s);
	void find(string s);
	void remove(string s);
	
	void show();

};
Map::Map(){
		what = "map";
	}
// 
void Map::insert(string s){
		array[Hash_2_first_letters(s)].add(s);
	}
// 
void Map::find(string s){
		cout<<array[Hash_2_first_letters(s)].get(array[Hash_2_first_letters(s)].find_value(s));
	}
//
void Map::remove(string s){
		array[Hash_2_first_letters(s)].remove(array[Hash_2_first_letters(s)].find_value(s));
	}
//
void Map::show(){
		for(int i=0; i<20;i++){
			cout<<"Map["<<i<<"] - " <<array[i].get_size()<<" elements"<<endl;
		}
	} 
#endif