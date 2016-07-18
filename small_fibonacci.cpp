/**
 * Purpose: Calculates Fib(n) in iterative way
 *
 * Fib(0) = 0; Fib(1) = 1; Fib(n) = Fib(n-2) + Fib(n-1)
 *
 * Input:   integer n; 0 <= n <= 93 (integer overflow with n > 93)
 * Output:  Fib(n)
 */

#include <iostream>
using namespace std;
typedef unsigned long long ull;

ull fibonacci(int n)
{
    ull prevElem1   = 0;    // Base case Fib(0)
    ull prevElem2   = 1;    // Base case Fib(1)
    ull currentElem = 0;

    currentElem = n;

    while(n-- >= 2)
    {
        currentElem = prevElem1 + prevElem2;
        prevElem1 = prevElem2;
        prevElem2 = currentElem;
    }

    return currentElem;
}

int main(int argc, char **argv) 
{
    int n;
    cin >> n;
    cout << fibonacci(n) << endl;

    return 0;
}