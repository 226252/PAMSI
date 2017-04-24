#include "../inc/tab.hpp"
#include "../inc/timer.hpp"
#include "../inc/quicksort.hpp"
#include "../inc/measures.hpp"
#include <cstdlib>
#include<iostream>
using namespace std;


int main(int argc, char* argv[]){
	srand(time(NULL));
	tab a(atoi(argv[1]));
	measures(a, *argv[2]);
	return 0;
}
