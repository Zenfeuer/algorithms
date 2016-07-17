/**
 * Purpose: Calculates the greatest common divisor between two integers.
 * 
 * Input: 	two integers a,b; 1 <= a,b <= 2.10^9
 * Output: 	GCD(a,b)
 */

#include <iostream>
using namespace std;

unsigned long gcd(unsigned long a, unsigned long b)
{
	if(b == 0) return a;
	return gcd(b, a%b);
}

int main() 
{
	unsigned long a, b;
	cin >> a >> b;

	if(a < b) swap(a,b);

	cout << gcd(a, b) << endl;

	return 0;
}