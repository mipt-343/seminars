#include "lib2.h"

#include <cstdio>

namespace MySpace{

	//печатает чётные числа от x1 до x2 включительно
	void printOddNumber(int x1, int x2)
	{
		for(x1 += (x1+1)%2; x1 <= x2; x1 += 2)
			printf("%d\t", x1);
	}
}
