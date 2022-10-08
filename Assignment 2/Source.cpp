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


int doubleInt(int i) {
	return (doubleInt(i += i));
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


int main() {
	//cout << sumDigits(1234);
	std::cout << egyptDivision(1960, 56) << std::endl;
	return 0;
}