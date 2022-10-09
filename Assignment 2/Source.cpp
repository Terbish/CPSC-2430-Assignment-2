#include <iostream>
#include <set>
#include <string>
#include <functional>
#include <queue>

int sumDigits(int i) {
	if (i == 0)
	{
		return 0;
	}
	return (i % 10 + sumDigits(i / 10));
}

int root5(int i) {
	if (i == 0 || i == 1)
	{
		return i;
	}
	int fin = 0;

	while (fin * fin * fin * fin * fin <= i) {
		fin++;
	}
	return fin - 1;
}

int doubleInt(int i) {
	return (i+i);
}

int halveInt(int half, int i) {
	if (i <= 1)
	{
		return 0;
	}
	else if ((half + half) <= i)
	{
		return half;
	}
	else
	{
		return (halveInt(half - 1, i));
	}
}

int egyptDivision(int dividend, int devisor)
{
	int a = 1;
	int b = devisor;
	int c = dividend;
	int d = 0;

	while (b < c)
	{
		a = doubleInt(a);
		b = doubleInt(b);
	}

	while (a >= 1 || c >=1)
	{
		if (b <= c)
		{
			d += a;
			c -= b;
		}
		a = halveInt(a, a);
		b = halveInt(b, b);
	}
	return d;
}

//int ramanujan(int depth) {
//	if (depth == 0)
//	{
//		return std::sqrt(6);
//	}
//	// if depth = n, sqrt(6 + n+1 sqrt(6+1+ n
//	return (ramanujan())
//	
//}


int main() {
	//std::cout << sumDigits(1234);
	std::cout << egyptDivision(1960, 56) << std::endl;
	/*std::cout << root5(250);*/
	//std::cout << ramanujan(0);
	return 0;
}