#ifndef HashHPP
#define HashHPP
#include <iostream>
using namespace std;
#include <string>



int hash1(string s,int modulo){
	int h=0;
	if(s.length()>1){
		for(unsigned int i=0; i<s.length(); i++){
			h=h+((int)s[i]);
		}
	}else{
		h=(int)s[0];
	}
	// cout<<"tyle daje hasz: "<<h%modulo<<endl;
	return h % modulo;
}

unsigned int hash2(string s,int modulo){
	const char *tmp = s.c_str();
	const char* p;
	unsigned int g, h=0;
	for (p=tmp;(*p)!='\0'; p++){
		h= (h<<4) + (*p);
		if (g=h&0xF0000000){
			h=h^(g>>24); h=h^g;
		}
	}
	return h%modulo;
}

#endif