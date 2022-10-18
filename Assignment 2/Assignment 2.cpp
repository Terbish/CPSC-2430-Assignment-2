#include <iostream>
#include <cmath>

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
	return (i % 10 + sumDigits(i / 10)); // add up the remainder of the digits
}

double function(double y, int n) {
	return pow(y, 5) - n;
}

double root5(double n, double y) {
	if (abs(function(y,n)) < 0.00001) // determine y is a good guess when |function| < 0.00001
	{
		return y;
	}
	double newY = (((4 * y) + (n / pow(y, 4))) / 5); // apply the formula
	return root5(n, newY);
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
		return (halveInt(half - 1, i)); // recurse int half until it is half of i
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

double base = 0;
double ramanujan(double depth) {
	if (depth == -1)
	{
		return base;
	}
	base = (depth + 1) * sqrt((depth + 6) + base); // apply the formula
	return ramanujan(depth - 1);
}


int main() {
	int input, dividend, divisor;
	double input_2;
	std::cout << "************* TASK 2 *************\n";
	std::cout << "Please enter the number you want to get the digit sum of: \n";
	std::cin >> input;
	std::cout << "The digit sum = " << sumDigits(input) << std::endl;

	std::cout << "************* TASK 3 *************\n";
	std::cout << "Please enter the number you want to get the 5th root of: \n";
	std::cin >> input_2;
	std::cout << "The fifth root of " << input_2 << " is " << root5(input_2, 1) << std::endl;

	std::cout << "************* TASK 4 *************\n";
	std::cout << "Please enter the dividend: \n";
	std::cin >> dividend;
	std::cout << "Please enter the divisor: \n";
	std::cin >> divisor;
	std::cout << "The Egyptian division of " << dividend << " and " << divisor << " is " << egyptDivision(dividend, divisor) << std::endl;
	
	std::cout << "************* TASK 5 *************\n";
	std::cout << "Please enter the depth of the ramanujan number: \n";
	std::cin >> input_2;
	std::cout << "The ramanujan number of depth " << input_2 << " = " << ramanujan(input_2) << std::endl;
	std::cout << "The value of the function carried out to infinity (1000) is: \n";
	std::cout << ramanujan(1000);
	return 0;
}
