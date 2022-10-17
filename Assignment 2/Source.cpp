#include <iostream>
#include <functional>

/* Question 1
	T(n) = 11n^3 + logn + 12sqrt(n)
	logn + 12sqrt(n) <= 13n if n >= 1
	11n^3 + logn + 12sqrt(n) <= 24n^3 if n >= 1
	therefore C = 24 f(n) = n^3
	so C = 24 and N = 1
	O(N) = n^3
	*/

int sumDigits(int i) {
	if (i == 0)
	{
		return 0;
	}
	return (i % 10 + sumDigits(i / 10));
}

double function(double y, int n) {
	return std::pow(y, 5) - n;
}

double root5(double y, int n) {
	if (std::abs(function(y, n)) < 0.00001)
	{
		return y;
	}
	double newY = (((4*y) + (n/std::pow(y,4)))/5);
	return root5(newY, n);
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

long long base = 0;
long long ramanujan(long long depth) {
	if (depth == -1)
	{
		return base;
	}
	base = (depth + 1) * std::sqrt((depth + 6) + base);
	return ramanujan(depth - 1);
}


int main() {
	//std::cout << sumDigits(1234);
	std::cout << "The Egyptian division of 1960 and 56 is: " << egyptDivision(89, 4) << std::endl;
	//std::cout << root5(250, 5);
	std::cout << ramanujan(10000);
	return 0;
}
