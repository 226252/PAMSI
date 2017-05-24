#ifndef Map_HPP
#define Map_HPP
#include <iostream>
#include "algorithms/Hash.hpp"
#include "interfaces/iRunable.hpp"
#include "List.hpp"
#include "Node.hpp"


class Map :public iRunable
{
	List<string>* array;
	string what;
	int size;
public:
	Map();
	Map(int howBig);
	~Map();
// metody klasy map 
	void insert(string s, int hash_option);
	void find(string s, int hash_option);
	void remove(string s, int hash_option);
	void show();
	void flush();
	int get_size();
// metody z iRunable
	void run(char option=' '){};
	double run_with_time(char option=' '){return 0;};
	void info();
	void prepare(int prepare_quantity, char prepare_option);
	void output();
	void reset();

};
Map::Map(){
		what = "map";
		array = new List<string> [1];
		size=1;
	}
// 
Map::Map(int howBig){
		what = "map";
		array = new List<string> [howBig];
		size=howBig;
}
//
Map::~Map(){
		delete [] array;
		size=0;
}
//
void Map::insert(string s, int hash_option=1){
		int hashed_value;
		if(hash_option==1){
			hashed_value=Hash_2_first_letters(s);
		}
		array[hashed_value].add(s);
	}
// 
void Map::find(string s, int hash_option=1){
		int hashed_value;
		if(hash_option==1){
			hashed_value=Hash_2_first_letters(s);
		}
		if(array[hashed_value].is_empty()){
			cout<<"No such element\n";
		}else{
			cout<<array[hashed_value].get(array[hashed_value].find_value(s));
		}	
	}
//
void Map::remove(string s, int hash_option=1){
		int hashed_value;
		if(hash_option==1){
			hashed_value=Hash_2_first_letters(s);
		}
		array[hashed_value].remove(array[hashed_value].find_value(s));
	}
//
void Map::show(){
		for(int i=0; i<size;i++){
			cout<<"Map["<<i<<"] - " <<array[i].get_size()<<" elements"<<endl;
		}
	} 
//
void Map::flush(){
		for (int i=0; i<size; i++){
			array[i].flush();
		}
	}
//
void Map::info(){
		cout<<"struktura danych: mapa\n";
	}
//
void Map::reset(){
		Map::flush();
}
//
void Map::output(){
		Map::show();
}
//

//
void Map::prepare(int prepare_quantity, char prepare_option){
	cout<<"cokolwiek\n";
}
//
int Map::get_size(){
	return size;
}
#endif