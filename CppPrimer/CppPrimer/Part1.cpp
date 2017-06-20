#include <iostream>
#include <cstdlib>

#include "choose.h"
 
#ifndef PART1

#define PART1_T1
#define PART1_T2
/*
	Choose from here
*/

#undef PART1_T2


#ifndef PART1_T1

int main() {
	int temp = 0;
	int sum = 0;
	std::cout << "Please Input Int:" << std::endl;
	
	while (std::cin >> temp) {
		sum += temp;
	}

	std::cout << "Sum is " << sum << std::endl;

	return EXIT_SUCCESS;
}

#endif

#ifndef PART1_T2
//
//int main() {
//	int currVal = 0, val = 0;
//	if (std::cin >> currVal) {
//		int cnt = 1;
//		while (std::cin >> val) {
//			if (val == currVal) {
//				++cnt;
//			}
//			else {
//				std::cout << currVal << " occurs " << cnt << " times " << std::endl;
//				currVal = val;
//				cnt = 1;
//			}
//		}
//		std::cout << currVal << " occurs " << cnt << " time " << std::endl;
//	}
//	return EXIT_SUCCESS;
//}

int main() {
	int currVal = 0, val = 0;
	while (std::cin >> val) {
		int cnt = 0;
		currVal = val;
		if (currVal == val) {
			cnt++;
		}
	}
}

#endif

#endif
