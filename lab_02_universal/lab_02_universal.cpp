// lab_02_universal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int opr(int a[4][4])
{
	int l = 0;
	l += a[1][1] * a[2][2] * a[3][3];
	l += a[1][2] * a[2][3] * a[3][1];
	l += a[1][3] * a[2][1] * a[3][2];
	l -= a[1][3] * a[2][2] * a[3][1];
	l -= a[1][1] * a[2][3] * a[3][2];
	l -= a[1][2] * a[2][1] * a[3][3];
	return l;
}

int main()
{
	int t = 0, n;
	while (!(t >= 1 && t <= 3))
	{
		std::cout << "Choose on of these:\n1.Solve matrix equation\n2.Gauss method\n3.Kramer method\n";
		std::cin >> t;
	}
	if (t == 1)
	{
		//code
	}
	else if (t == 2)
	{

	}
	else
	{
		std::cout << "\t\tKRAMER METHOD\n";
		int a[4][4], b[4];
		std::cout << "Enter the main matrix:\n";
		for (int i = 1; i <= 3; ++i)
			for (int j = 1; j <= 3; ++j)
				std::cin >> a[i][j];

		std::cout << "Enter the answers matrix:\n";
		for (int i = 1; i <= 3; ++i) std::cin >> b[i];

		int x = opr(a);
		int a1[4][4];
		for (int i = 1; i <= 3; ++i)
		{
			a1[i][1] = b[i];
			a1[i][2] = a[i][2];
			a1[i][3] = a[i][3];
		}
		int x1 = opr(a1);
		for (int i = 1; i <= 3; ++i)
		{
			a1[i][1] = a[i][1];
			a1[i][2] = b[i];
			a1[i][3] = a[i][3];
		}
		int x2 = opr(a1);
		for (int i = 1; i <= 3; ++i)
		{
			a1[i][1] = a[i][1];
			a1[i][2] = a[i][2];
			a1[i][3] = b[i];
		}
		int x3 = opr(a1);
		std::cout << "x1=" << x1 / x << "  x2=" << x2 / x << "  x3=" << x3 / x << std::endl;
	}

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
