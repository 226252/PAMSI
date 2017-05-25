#include "../inc/Array.hpp"
#include "../inc/algorithms/Quick_sort.hpp"
#include "../inc/measures.hpp"
#include <cstdlib>
#include <iostream>
#include "../inc/Map.hpp"
using namespace std;
#include <string>
#include "../inc/Tree.hpp"

int main(){	
	srand(time(NULL));
	Tree<int> Tr;
	int quantities[14]={10,500,1000,2000,3000,4000,5000,100000,50000,100000, 200000, 300000, 500000, 1000000};
	for (int i=0; i<14; i++){
		measures(Tr, quantities[i]);
	}
	return 0;
}

