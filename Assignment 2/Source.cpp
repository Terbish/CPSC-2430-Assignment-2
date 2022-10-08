#include <iostream>
#include <set>
using namespace std;


int sumDigits(int i);
int root5(int i);
void ramanujan();

int sumDigits(int i) {
	if (i == 0)
	{
		return 0;
	}
	return (i % 10 + sumDigits(i / 10));
}

class question_3
{
public:
	int a = 1;
	int d = 0;
	set<int, greater<int>> deviSet, divSet, aSet, bSet;
	int doubleInt(int dividend, int devisor);
	int halfInt(int dividend, int devisor);
	int egyptDivision(int dividend, int devisor);

private:

};


int question_3::doubleInt(int dividend, int devisor) 
{ 
	if (devisor <= dividend)
	{
		cout << a <<"\t" << devisor << "\t" << dividend << "\n";
		a += a;
		deviSet.insert(devisor);
		aSet.insert(a);
		divSet.insert(dividend);
		return (doubleInt(dividend, devisor += devisor));

	}
	cout << a << "\t" << devisor << "\t" << dividend << "\n";
	return (dividend, devisor, a);
}

int question_3::halfInt(int dividend, int devisor) {
	if (devisor >= dividend)
	{
		cout << a << "\t" << devisor << "\t" << dividend << "\t" << d << "\n";
		
		return (halfInt(dividend, devisor -= devisor));
	}
	else if (dividend || devisor || a == 1)
	{
		return (dividend, devisor);
	}
	cout << a << "\t" << devisor << "\t" << dividend << "\t" << d << "\n";
	return (halfInt(dividend -= devisor, devisor -= devisor));
}


int main() {
	//cout << sumDigits(1234);
	question_3 egyptDivision;
	egyptDivision.doubleInt(1960, 56);
	return 0;
}