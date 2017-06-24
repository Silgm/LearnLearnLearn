#include <iostream>
#include <cstdlib>

#include "choose.h"
 
#ifndef PART1

#define PART1_T1
#define PART1_T2
#define PART1_T3
#define PART1_T4
#define PART1_T5
/*
	Choose from here
*/

#undef PART1_T5


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
1.23 ��д����, ��ȡ�������ۼ�¼, ����¼ÿ��ISBN(ÿ����)�м������ۼ�¼
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
����"- -"����
������˫����
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

#ifndef PART1_T4

#include <iostream>
#include "Sales_item.h"



int main() {
	Sales_item total;
	if (std::cin >> total) {
		Sales_item trans;
		while (std::cin >> trans) {
			if (total.isbn() == trans.isbn())
				total;
			else {
				std::cout << total << std::endl;
				total = trans;
			}
		}
		std::cout << total << std::endl;
	}
	else {
		std::cerr << "No data?!" << std::endl;
	}

	return EXIT_SUCCESS;
}


#endif // !PART1_T4

#ifndef PART1_T5


/************************************************************************/
/* 
	�ڴ�й¶���
	���ӵĶ���д���ˣ����д��򵥵ĺ��ˡ����ڹ����ϵ���Ҫ��Vczh Library++3.0���Ҹ�ú����ס�
	Ϊ�˿���ά���ı��������ٴ��ķ��µĴ����Լ���ǿ��Ԫ���ԡ��ع���ԺͲ��Թ��ߣ���˼�¼��һЩ�����ϵ�С���ɣ��Ա���ש�����츣���ˡ���ӭ�������磬����Ĥ�ݡ�

	C++ʵν���������е����ߣ�����ǿ�������ǿ�󡣵�Ȼ����Ϊһ�������õò�����ȫ�ǳ���Ա�����Σ�������ΪC++�漰���ĸ���ʵ����̫�࣬
	���ú�ʵ��Ҳ����һ�����׵����顣C++������ʱ�����ǻ��������ָ��������⣬���������ص��޷����ڴ���صġ�C�������ڽṹ�򵥣��ڴ洦��������Ȼ��������
	���ܵ���˵���÷��Ѿ��������ģ����Ҳ�������ʲô���ѷ��ֵĴ���C++�Ͳ�һ���ˡ������麯�������캯�����������������ƹ��캯����operator=����֮��
	�����кܶ���ϲ����һ����ֱ��д���ļ�������������memset������һ�����飬��֪�ڸ�Ҳ�����ǲ��������ҭ��ʳ������ĳ����ΪC++��������������̫�࣬�Լ��㲻����
	�Լ��Ŷ�Ҳ�㲻������˵C++����һ����

	��˵�һƪ������Ҫ����ڴ����������Ǵ����ڴ棬��һ���¾��ǲ�Ҫ���ڴ�й¶��
	�ڴ�й¶���ܵȵ����Ե�ʱ��ͨ����ʱ�����г��򲢹۲�����������ķ�������������Ȼ�Ѿ����ˡ�
	�Һ�Visual C++��������һ��ʮ�ֺ��õĹ��ߣ�_CrtDumpMemoryLeaks������
	�����������Debugģʽ����Visual Studio��output���ڴ�ӡ���Ǹ�ʱ����new��malloc���˵��ǻ�ûdelete��free���������ڴ��ĵ�ַ�����ȡ�ǰN���ֽڵ����ݺ�������Ϣ��
	��ô���أ�

	��ʵ�ܼ򵥣�
	1 #define _CRTDBG_MAP_ALLOC
	2 #include <stdlib.h>
	3 #include <crtdbg.h>
	4 #include <windows.h>
	5
	6 int wmain(vint argc , wchar_t* args[])
	7 {
	8     // �������г��򣬲�������ĺ�������֮ǰdelete������new�Ķ���
	9     _CrtDumpMemoryLeaks();
	10     return 0;
	11 }

	����ֻ��Ҫ��ע�͵ĵط�������ǳ���Ĺ��ܣ�Ȼ��ȷ���Լ��Ѿ�delete������Ӧ��delete�Ķ�����
	���_CrtDumpMemoryLeaks()�������õ�ʱ��Ϳ��Դ�ӡ��û��delete�Ķ����ˡ��������ʮ�����棬
	��Ϊ��ֻ��Ҫ��main�������ڵ�cpp�ļ���ô#includeһ�£����е�cpp�ļ������new�����ܵ����ӣ�
	��ƽ�����õ��ú��new�������������Ʒ�����Ȼ��ͬ�������ʹ����ȫ�ֱ����Ļ�ҲҪС�ģ���Ϊȫ�ֱ�����������������main��������֮���ִ�еģ�
	��������ȫ�ֱ�����������������delete�Ķ�����Ȼ�ᱻ_CrtDumpMemoryLeaks��������й¶������Դ�Դ���
	��Ȼ������Ϊȫ�ֱ��������ã�����ȫ�ֱ����ĸ�ֵ������main���������ͷ�Ҳ�ǣ������Ǹ�ȫ�ֱ����Ĺ��캯��û�������κ��ڴ棬������Ҳ��һ���ܺõļ�鷽����

	��������Ҳ������һ����������û���ڴ�й©�ķ������ˡ���ô��α����ڴ�й¶�أ���Ȼ�����һЩ����Ҫ��û�бȲ���ϵͳ�����ϸ�ĳ����ʱ�򣬿���ʹ�����·�����
	1��������캯��new��һ������ʹ�ó�Աָ���������Ļ�����ô��������������delete�������Ҳ�����Ϊ��ĳЩ��������������������Ȩת�ó�ȥ�����鷢����
	2������ʹ��shared_ptr��ʱ�򣬾���ʹ��shared_ptr��shared_ptrֻҪ�㲻����ѭ�����ã���ô����������԰�ȫ�ػ��ഫ�ݡ���������ʲô�����������ɾ����
		���������ͷ��������Ҳ���ÿ������������������������ˡ�
	3����Ҫ���й��캯�������������Ķ�����ʹ��memset������memcpy�������һ��������Ҫmemset����ô�ڸö���Ĺ��캯������memset�Լ���
		�������Ҫmemsetһ���������飬��Ҳ�ڸö���Ĺ��캯������memset�Լ����������Ҫmemsetһ��û�й��캯���ĸ��Ӷ�����ô��Ϊ�����һ�����캯����
		�������Ǳ��˵�API�ṩ�Ķ�����
	4�����һ�������Ǽ̳�����������������ĳЩ��Ա�������virtual�Ļ������Բ�Ҫmemset��
		�����Ƕ����ģ�Ҳ����˵�����ڲ��ṹ���ݱ䲻��Ҫ�����ฺ��
		���츸���������һ��string��Ա��������һmemset�������������ˡ�
	5�������ҪΪһ�������幹�캯������ô�����ƹ��캯����operator=���غ�����������ȫ��дȫ��
		�������д���ƹ��캯����operator=�Ļ�����ô��һ���յ�ʵ��д��private���棬
		ȷ���κ���ͼ������Щ�����Ĵ��붼���ֱ������
	6�������ʵ�ں�ϲ��C���ԵĻ������鷳��һ��ֻ֧��C��֧��C++�ı�������ȫ��ž���Ϊ������C++���������C������������֡�

	ʲô��ѭ�������أ��������������ʹ��һ��shared_ptr��Ա����ֱ�ӻ��߼��ָ��Է��Ļ�������ѭ�������ˡ�
	��������������ü�����ʧЧ����Ϊ������ߵ�shared_ptrȫ�ͷŹ��ˣ����ü���Ҳ������0�ġ�


	>>ע��:	free����ֻ���ͷ��ڴ�, �������������, ��delete�ȵ��������ͷ��ڴ�
	>>		malloc����ֻ�ǿ����ڴ�, ��������ù���, ��new�ȿ����ڴ��ٵ��ù���

*/
/************************************************************************/

#ifdef _DEBUG

#define _CRTDBG_MAP_ALLOC 
#include <crtdbg.h>
#include <windows.h>

#endif


int main(int argc, char* args[]) {
#ifdef _DEBUG
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_DEBUG);
	printf("DEBUG> Memory Leaks: %d\n", _CrtDumpMemoryLeaks());
#endif // DEBUG
	return EXIT_SUCCESS;
}

#endif // !PART1_T5


#endif








