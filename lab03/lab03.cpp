// lab03.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct otrez
{
	int left;
	int right;
};

double func(double x)
{
	double ans = 2 * cos(x / 2) - (2 / x);
	return ans;
}

vector<otrez> otr(double a, double b, double h)
{
	vector<otrez>v;
	for (double i = a + h; i <= b; i += h)
	{
		double left = i - h;
		double right = i;
		if (func(left) * func(right) < 0)
		{
			otrez k;
			k.left = left;
			k.right = right;
			v.push_back(k);
		}
	}
	return v;
}

int main()
{
	double a, b, m;
	cout << "Enter the value of a: ";
	cin >> a;
	cout << "Enter the value of b: ";
	cin >> b;
	cout << "Enter the value of m: ";
	cin >> m;

	vector<otrez>v;
	v = otr(a, b, (b - a) / m);

	for (int i = 0; i < v.size(); ++i)
	{
		cout << i << ".\t(" << v[i].left << " , " << v[i].right << ")" << endl;
	}
	int s = -1;
	while (s < 0 || s >= v.size())
	{
		cout << "Select one of the segments and enter its number: ";
		cin >> s;
	}
	cout << "Selected segment is (" << v[s].left << " , " << v[s].right << ")\n";
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
