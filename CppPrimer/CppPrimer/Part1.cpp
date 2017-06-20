#include <iostream>
#include <cstdlib>

#include "choose.h"
 
#ifndef PART1

#define PART1_T1
#define PART1_T2
#define PART1_T3
/*
	Choose from here
*/

#undef PART1_T3


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


#ifndef PART1_T3

/************************************************************************/
/* 
1.23 编写程序, 读取多条销售记录, 并记录每个ISBN(每本书)有几条销售记录
*/
/************************************************************************/

#include "Sales_item.h"

#include <vector>

#define SALES_ITEM_SIZE		32

typedef enum _TableState
{
	TABLE_STATE_NEW_ELEMENT = 0,
	TABLE_STATE_OLD_ELEMENT = 1,

}tableState;

/************************************************************************/
/* 
	ElementType Have "==" function 
*/
/************************************************************************/
template<typename ElementType> class CounterTable {
public:
	tableState add(ElementType element) {
		int counter = 0;
		int ElementListSize = (int)ElementList.size();
		for (; counter < ElementListSize && (!(ElementList[counter] == element)); counter++);
		if (counter >= ElementListSize) {
			ElementList.push_back(element);
			ElementNumsList.push_back(1);
			return TABLE_STATE_NEW_ELEMENT;
		}
		ElementNumsList[counter]++;
		return TABLE_STATE_OLD_ELEMENT;
	}
	
	int tableLength() {
		return (int)ElementList.size();
	}

	ElementType getElement(int indexOfElement) {
		return ElementList.at(indexOfElement);
	}

	int getElementNums(int indexOfElement) {
		return ElementNumsList.at(indexOfElement);
	}

private:
	std::vector<ElementType> ElementList;
	std::vector<int> ElementNumsList;
};


/************************************************************************/
/* 
输入"- -"结束
不包括双引号
*/
/************************************************************************/
int main() {
	Sales_item item;
	CounterTable<std::string> tab;

	while (std::cin >> item) {
		tab.add(item.isbn());
	}

	for (int index = 0; index < tab.tableLength(); index++) {
		std::cout << tab.getElement(index) << " nums: " << tab.getElementNums(index) << std::endl;
	}


	return EXIT_SUCCESS;
}

#endif // !1


#endif
