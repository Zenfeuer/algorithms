#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

void sort3(vector<long> &numbers, long lo, long hi) 
{ 
    if (hi <= lo) return;
    long lt = lo, gt = hi;
    long v = numbers[lo];
    long i = lo;
    while (i <= gt) 
    {
        if      (numbers[i] < v) swap(numbers[lt++], numbers[i++]);
        else if (numbers[i] > v) swap(numbers[i], numbers[gt--]);
        else              i++;
    }

    sort3(numbers, lo, lt-1);
    sort3(numbers, gt+1, hi);
}

int main(int argc, char const *argv[])
{
    long n, m, i;
    cin >> n;

    vector<long> numbers(n);

    for (i = 0; i < n; ++i)
        cin >> numbers[i];

    sort3(numbers, 0, n - 1);

    for (i = 0; i < n; ++i)
        cout << numbers[i] << (i < n- 1? " " : "\n");

    return 0;
}