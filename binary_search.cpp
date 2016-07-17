#include <iostream>
#include <vector>

using namespace std;

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