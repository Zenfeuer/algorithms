/**
 * Purpose: Binary search algorithm
 *
 * Input:   First line: an integer n and a sequence of n integer 
 *          numbers in increasing order. A = (a1, a2,..., an)
 *          Second line: an integer k and a sequence of k integers
 *          to find in the first sequence. B = (b1, b2,..., bk)
 *
 * Constraints: 1 <= n,k <= 10^5; 1 <= ai,bi <= 10^9
 * 
 * Output:  indexes separated by space of the finding process of the
 *          numbers in sequence B in the sequence A. If a bi it is not
 *          foun in the sequence A, output -1 for that case.
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * Binary search method (iterative)
 * @param  numbers      array of numbers
 * @param  numberToFind number to find
 * @return              index of the number to find, -1 otherwise
 */
long binary_search(const vector<long> &numbers, long numberToFind) 
{
    long left = 0, right = (long)numbers.size(), mid;

    while (left <= right)
    {
        mid = left + (right - left)/2;

        if (numbers[mid] == numberToFind) return mid;
        else if(numbers[mid] < numberToFind) left = mid + 1;
        else if (numbers[mid] > numberToFind) right = mid - 1;
    }

    return -1;
}

int main() 
{
    long n, m, i;
    cin >> n;

    vector<long> numbers(n);

    for (i = 0; i < numbers.size(); i++)
        cin >> numbers[i];

    cin >> m;

    int numberToFind;

    for (i = 0; i < m; ++i)
    {
        cin >> numberToFind;
        cout << binary_search(numbers, numberToFind) << (i < m - 1? " " : "\n");
    }
}