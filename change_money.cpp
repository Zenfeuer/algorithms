/**
 * Purpose: Determines the minimum number of coins needed to change
 * the input value with coins denomination 1, 5, and 10.
 *
 * This must be resolved with a greeding algorithm.
 * 
 * Input:   a single integer; 1 <= m <= 10^3
 * Output:  minimum number of coins needed to change m with
 *          denomination 1, 5, and 10
 */

#include <iostream>
using namespace std;

/**
 * Optimal solution of changing money with the denomination given.
 * The idea is to take a safe move, that is, always take the major
 * denomination while you can. The diference here is that never
 * iterates, just arithmetic operations with the m given.
 * 
 * @return   minimum number of coins
 */
int optimalSolution(int m)
{
    int total = 0;

    if(m/10 > 0)
    { 
        total += m/10;
        m = m - (m/10)*10; 
    }

    if(m - 5 >= 0)
    {
        total += 1;
        m = m - 5;
    }

    if(m > 0)
        total += m;

    return total;
}

/**
 * Slow and naive solution. Iterates until gets to the amount, counting
 * the coins used.
 * 
 * @return   minimum number of coins
 */
int slowSolution(int m)
{
    int total = 0;
    int idx = 0;

    while(total < m)
    {
        if(total + 10 <= m) total += 10;
        else if(total + 5 <= m) total += 5;
        else if(total + 1 <= m) total++;
        idx++;
    }
    return idx;
}

int main(int argc, char const *argv[])
{
    int m;
    cin >> m;
    cout << optimalSolution(m) << endl;

    return 0;
}