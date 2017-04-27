#include "../inc/Array.hpp"
// #include "../inc/timer.hpp"
#include "../inc/algorithms/Quick_sort.hpp"
#include "../inc/measures.hpp"
#include <cstdlib>
#include <iostream>
using namespace std;


int main(int argc, char* argv[]){
	srand(time(NULL));
	Array array(atoi(argv[1]));
	Quick_sort Qsort_algorithm(array);
	measures(Qsort_algorithm, *argv[2], *argv[3]);
	return 0;
}
