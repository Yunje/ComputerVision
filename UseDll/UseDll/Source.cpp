#include <iostream>
#pragma comment(lib, "MakeDll.lib")

extern "C" __declspec(dllimport) double Sub(double a, double b);

int main()
{
	double result;
	result = Sub(1.0, 4.0);
	std::cout << result << std::endl;
	return 0;
}