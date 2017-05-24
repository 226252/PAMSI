#ifndef Map_HPP
#define Map_HPP
#include <iostream>
#include "algorithms/Hash.hpp"
#include "interfaces/iRunable.hpp"
#include "List.hpp"
#include "Node.hpp"
#include <fstream>
#include "timer.hpp"

class Map :public iRunable
{
	List<string>* array;
	string what;
	int size;
	bool redFromFile;
	string redFileName;
	int whichHash;
	int redObjects;
	string lastAdded;
public:
	Map();
	Map(int howBig, int whatHash);
	~Map();
// metody klasy map 
	void insert(string s);
	void find(string s);
	void remove(string s);
	void show();
	void flush();
	int get_size();
	int hash(string s);
// metody z iRunable
	void run(char option);
	double run_with_time(char option);
	void info();
	void prepare(int prepare_quantity, char prepare_option);
	void output();
	void reset();

};

Map::Map(){
		what = "map";
		array = new List<string> [1];
		size=1;
		redFromFile=false;
		whichHash=1;
		redObjects=0;
	}
// 
Map::Map(int howBig, int whatHash){
		what = "map";
		array = new List<string> [howBig];
		size=howBig;
		redFromFile=false;
		whichHash=whatHash;
		redObjects=0;
}
//
Map::~Map(){
		delete [] array;
		size=0;
}
//
int Map::hash(string s){
	int hashed_value;
	if(whichHash==1){
		hashed_value=hash1(s, size);
		return hashed_value;
	}
	if(whichHash==2){
		hashed_value=hash2(s, size);
		return hashed_value;
	}else{
		cout<<"No such hash option, returning 0\n";
		return -1;
	}
}

//
void Map::insert(string s){
		int hashed_value;
		hashed_value=hash(s);
		if(hashed_value<0){return;}
		array[hashed_value].add(s);
		redObjects++;
		lastAdded=s;
	}
// 
void Map::find(string s){
		int hashed_value;
		hashed_value=hash(s);
		if(!hashed_value){return;}
		if(array[hashed_value].is_empty()){
			cout<<"No such element\n";
		}else{
			cout<<array[hashed_value].get(array[hashed_value].find_value(s));
		}	
	}
//
void Map::remove(string s){
		int hashed_value;
		hashed_value=hash(s);
		if(!hashed_value){return;}
		array[hashed_value].remove(array[hashed_value].find_value(s));
	}
//
void Map::show(){
		int filled=0;
		for(int i=0; i<size;i++){
			if(array[i].get_size()){filled++;}
		}	// cout<<"Map["<<i<<"] - " <<array[i].get_size()<<" elements"<<endl;
		
		cout<<" filled: "<<filled<<" empty:"<<size-filled<<endl;
		cout<<" ratio: "<<(double)filled/(double)size<<endl;
		
	} 
//
void Map::flush(){
		for (int i=0; i<size; i++){
			array[i].flush();
		}
	}
//
void Map::info(){
		cout<<"struktura danych: mapa\n rozmiar: "<<size<<endl;
		cout<<" wczytanych danych: "<<redObjects<<endl;
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
void Map::prepare(int prepare_quantity, char prepare_option=' '){
	fstream data;
	string fileName, tmp;
	// cout<<"Podaj nazwe pliku: ";
	// cin>>fileName;
	fileName="data";
	redFileName=fileName;
	data.open(fileName, ios::in);
	if(data.good()){
		for (int i=0; i<prepare_quantity; i++){
			if(data.eof()){cout<<"end of file\n";
							break;}
			getline(data, tmp);
			insert(tmp);
		}
	redFromFile=true;
	data.close();
	}else{
		cout<<"Didn't read file, function terminated\n";
	redFromFile=false;
	}
}
//
void Map::run(char option=' '){
	if(!redFromFile){cout<<"Object not prepared\n";
						return;}
	string searchValue;
	// cout<<"Szukana wartosc: ";
	// cin>>searchValue;
	// find("drgqi\r");


}
//
double Map::run_with_time(char option=' '){
	if(!redFromFile){cout<<"Object not prepared\n";
						return 0;}
	string searchValue; 
	timer<nanoseconds> t;
	// cout<<"Szukana wartosc: ";
	// cin>>searchValue;
	t.begin();
	find(lastAdded);
	t.stop();	
	return t.duration();
}
// 
int Map::get_size(){
	return size;
}
//

#endif