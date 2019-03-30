#include "MergeSort.h"
#include <cstdio>
#include <ctime>
int main(void) {
	srand((unsigned int)time(NULL));
	vector<int> temp(5000);
	for (int i = 0; i < temp.size(); i++) {
		temp[i] = rand() % 10000;
	}
	std::clock_t start;
	start = std::clock();
	MergeSort<int> temp2(temp);
	temp2.sort();
	std::cout << "Duration of algorithm: " << (std::clock() - start) / (double)CLOCKS_PER_SEC << " seconds for "<<temp2.getSize()<< " size array" << std::endl;
	return 0;
}