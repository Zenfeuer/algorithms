/**
 * Purpose: Calculates Fib(n) mod m where n may be really huge,
 * calculate it in iterative way will be take much time.
 * Fib(n) mod m is periodic for any integer m >= 2. This period
 * is known as Pisano period (https://oeis.org/A001175).
 *
 * Pisano period begins always with 01
 * 
 * Input: 	integer n; 1 <= n <= 10^18
 * 			integer m; 2 <= m <= 10^5
 * Output: 	Fib(n) mod m
 */

#include <iostream>
using namespace std;
typedef unsigned long ul;

/**
 * Determines the pisano index where the period begins again.
 *
 * @return Pisano index (length of the period) for the given m
 */
ul pisanoIndex(ul m)
{
	ul pisano = 0;
	ul fi     = 0;	// Fib(n)%m
	ul fi_0   = 0;	// Base case Fib(0)%m
	ul fi_1   = 1;	// Base case Fib(1)%m

	while(true)
	{
		if(pisano && fi_0%m == 0 && fi_1%m == 1) break;

		fi = (fi_0 + fi_1)%m;
		fi_0 = fi_1;
		fi_1 = fi;
		pisano++;
	}

	return pisano;
}

/**
 * Calculates the Fib(n) mod m through Pisano period.
 * @return   Fib(n) mod m
 */
ul fibonacciModM(ul n, ul m)
{
	ul fi     = 0;	// Fib(n)%m
	ul fi_0   = 0;	// Base case Fib(0)%m
	ul fi_1   = 1;	// Base case Fib(1)%m

	unsigned int lim = n % pisanoIndex(m);

	// With the limit determinated, it is enough to
	// calculate the Fib(n) mod m with Fib(lim) mod m
	for(unsigned int i = 2; i <= lim; i++)
	{
		fi = (fi_0%m + fi_1%m)%m;
		fi_0 = fi_1%m;
		fi_1 = fi;
	}

	return fi;
}

int main() 
{
	ul n, m;
	cin >> n >> m;
	cout << fibonacciModM(n, m) << endl;

	return 0;

}