/**
 * Purpose: Calculates Fib(n) mod 10 in iterative way
 *
 * Fib(0) = 0; Fib(1) = 1; Fib(n) mod 10 = [Fib(n-2) mod 10 + Fib(n-1) mod 10] mod 10
 *
 * Input: 	integer n; 0 <= n <= 10^7
 * Output: 	Fib(n) mod 10
 */

#include <iostream>
using namespace std;
typedef unsigned long long ull;

ull fibonacciMod10(int n)
{
	ull prevElem1   = 0;	// Base case Fib(0)
	ull prevElem2   = 1;	// Base case Fib(1)
	ull currentElem = 0;

	currentElem = n;

	while(n-- >= 2)
	{
		currentElem = (prevElem1%10 + prevElem2%10)%10;
		prevElem1 = prevElem2;
		prevElem2 = currentElem;
	}

	return currentElem;
}

int main(int argc, char **argv) 
{
	int n;
	cin >> n;
	cout << fibonacciMod10(n) << endl;

	return 0;
}