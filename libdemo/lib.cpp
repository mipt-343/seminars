#include "lib.h"

#include <cstdio>

namespace MySpace{

	//печатает чётные числа от x1 до x2 включительно
	void printEvenNumber(int x1, int x2)
	{
		for(x1 += x1%2; x1 <= x2; x1 += 2)
			printf("%d\t", x1);
	}
}
