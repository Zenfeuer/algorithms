/**
 * Purpose: Check the existence for a majority element in a given sequence.
 *
 * An element of a sequence of length n is called a majority element if it 
 * appears in the sequence strictly more than n=2 times.
 *
 * Input:   First line: an integer n; 1 <= n <= 10^5
 *          Second line: a sequence of n non-negative integers separated by
 *          space. (a1,a2,...,an) 0 <= ai <= 10^9
 * 
 * Output:  1 if the sequence contains a majority element and 0 otherwise
 */

#include <iostream>
#include <map>

using namespace std;

int main() 
{
    long n, m, i;
    cin >> n;

    if (n == 1) cout << 1 << endl;
    else
    {
        long mid = n/2;
        bool thereIsMajority = false;
        
        map<long, long> numbers;
        map<long, long>::iterator it;

        for (i = 0; i < n; i++)
        {
            cin >> m;
            it = numbers.find(m);
            if(it != numbers.end())
            {
                numbers[m] = numbers[m] + 1;

                if(numbers[m] > mid) thereIsMajority = true;
            }
            else numbers[m] = 1;
        }

        cout << (thereIsMajority? 1 : 0) << endl;
    }

    return 0;
}