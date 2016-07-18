/**
 * Purpose: Calculates the least common multiple between two integers.
 * 
 * Input:   two integers a,b; 1 <= a,b <= 2.10^9
 * Output:  LCM(a,b)
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

    // a*b = LCM(a,b)*GCD(a,b)
    cout << (a*b)/gcd(a,b) << endl;

    return 0;
}