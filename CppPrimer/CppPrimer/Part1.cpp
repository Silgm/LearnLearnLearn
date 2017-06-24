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
	内存泄露检测
	复杂的东西写多了，如今写点简单的好了。由于功能上的需要，Vczh Library++3.0被我搞得很离谱。
	为了开发维护的遍历、减少粗心犯下的错误以及增强单元测试、回归测试和测试工具，因此记录下一些开发上的小技巧，以便抛砖引玉，造福他人。欢迎高手来喷，菜鸟膜拜。

	C++实谓各种语言中的软肋，功能强大，陷阱更强大。当然我认为一门语言用得不好完全是程序员的责任，不过因为C++涉及到的概念实在是太多，
	想用好实在也不是一件容易的事情。C++开发的时候总是会遇到各种各样的问题，其中最严重的无非是内存相关的。C语言由于结构简单，内存处理起来虽然不得力，
	但总的来说惯用法已经深入人心，因此也不会造成什么很难发现的错误。C++就不一样了。有了虚函数、构造函数、析构函数、复制构造函数和operator=重载之后，
	还是有很多人喜欢把一个类直接写进文件流，或者拿来memset，代码一团乱麻，不知悔改也。但是不能因此因噎废食，就像某人因为C++带来的心智问题太多，自己搞不定，
	自己团队也搞不定，就说C++不好一样。

	因此第一篇文章主要针对内存来讲。我们处理内存，第一件事就是不要有内存泄露。
	内存泄露不能等到测试的时候，通过长时间运行程序并观察任务管理器的方法来做，这显然已经晚了。
	幸好Visual C++给了我们一个十分好用的工具：_CrtDumpMemoryLeaks函数。
	这个函数会在Debug模式下往Visual Studio的output窗口打印出那个时候你new（malloc）了但是还没delete（free）的所有内存块的地址、长度、前N个字节的内容和其他信息。
	怎么做呢？

	其实很简单：
	1 #define _CRTDBG_MAP_ALLOC
	2 #include <stdlib.h>
	3 #include <crtdbg.h>
	4 #include <windows.h>
	5
	6 int wmain(vint argc , wchar_t* args[])
	7 {
	8     // 这里运行程序，并在下面的函数调用之前delete掉所有new的东西
	9     _CrtDumpMemoryLeaks();
	10     return 0;
	11 }

	我们只需要在注释的地方完成我们程序的功能，然后确信自己已经delete掉所有应该delete的东西，
	最后_CrtDumpMemoryLeaks()函数调用的时候就可以打印出没被delete的东西了。这个方法十分神奇，
	因为你只需要在main函数所在的cpp文件这么#include一下，所有的cpp文件里面的new都会受到监视，
	跟平常所用的用宏把new给换掉的这种破方法截然不同。如果你使用了全局变量的话也要小心，因为全局变量的析构函数是在main函数结束之后才执行的，
	因此如果在全局变量的析构函数里面delete的东西仍然会被_CrtDumpMemoryLeaks函数当成泄露掉的资源对待。
	当然本人认为全局变量可以用，但是全局变量的赋值必须在main里面做，释放也是，除非那个全局变量的构造函数没有申请任何内存，所以这也是一个很好的检查方法。

	不过上面也仅仅是一个告诉你有没有内存泄漏的方法罢了。那么如何避免内存泄露呢？当然在设计一些性能要求没有比操作系统更加严格的程序的时候，可以使用以下方法：
	1、如果构造函数new了一个对象并使用成员指针变量保存的话，那么必须在析构函数delete它，并且不能有为了某些便利而将这个对象的所有权转让出去的事情发生。
	2、在能使用shared_ptr的时候，尽量使用shared_ptr。shared_ptr只要你不发生循环引用，那么这个东西可以安全地互相传递、随便你放在什么容器里面添加删除、
		你想放哪里就放在哪里，再也不用考虑这个对象的生命周期问题了。
	3、不要在有构造函数和析构函数的对象上使用memset（或者memcpy）。如果一个对象需要memset，那么在该对象的构造函数里面memset自己。
		如果你需要memset一个对象数组，那也在该对象的构造函数里面memset自己。如果你需要memset一个没有构造函数的复杂对象，那么请为他添加一个构造函数，
		除非那是别人的API提供的东西。
	4、如果一个对象是继承了其他东西，或者某些成员被标记了virtual的话，绝对不要memset。
		对象是独立的，也就是说父类内部结构的演变不需要对子类负责。
		哪天父类里面加了一个string成员，被子类一memset，就欲哭无泪了。
	5、如果需要为一个对象定义构造函数，那么连复制构造函数、operator=重载和析构函数都全部写全。
		如果不想写复制构造函数和operator=的话，那么用一个空的实现写在private里面，
		确保任何试图调用这些函数的代码都出现编译错误。
	6、如果你实在很喜欢C语言的话，那麻烦换一个只支持C不支持C++的编译器，全面杜绝因为误用了C++而导致你的C坏掉的情况出现。

	什么是循环引用呢？如果两个对象互相使用一个shared_ptr成员变量直接或者间接指向对方的话，就是循环引用了。
	在这种情况下引用计数会失效，因为就算外边的shared_ptr全释放光了，引用计数也不会是0的。


	>>注意:	free仅仅只是释放内存, 但不会调用析构, 而delete先调析构再释放内存
	>>		malloc仅仅只是开辟内存, 但不会调用构造, 而new先开辟内存再调用构造

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








