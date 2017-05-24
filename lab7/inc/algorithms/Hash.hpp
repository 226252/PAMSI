#ifndef HashHPP
#define HashHPP
#include <iostream>
using namespace std;
#include <string>



int Hash_2_first_letters(string s){
	int h=0;
	if(s.length()>1){
		for(unsigned int i=0; i<2; i++){
			h=h+((int)s[i]);
		}
	}else{
		h=(int)s[0];
	}
	return h % 20;
}


#endif