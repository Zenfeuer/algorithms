#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef unsigned long long ull;

ull inversions = 0;

void merge(vector<ull> &numbers, ull size_left, ull size_right, ull idx)
{
    ull i = 0, j = 0;
    ull ii = idx, jj = idx;
    vector<ull> merging(size_left+size_right);

    while(i + j < size_left + size_right)
    {
        if((i < size_left && numbers[ii] <= numbers[jj + size_left]) || (i < size_left && j >= size_right))
        {
            merging[i + j] = numbers[ii++];
            i++;
        }

        if((j < size_right && numbers[ii] > numbers[jj + size_left]) || (j < size_right && i >= size_left))
        {
            merging[i + j] = numbers[size_left + jj++];
            j++;
            inversions += size_left - i;
        }
    }

    for (ull i = 0; i < merging.size(); ++i)
        numbers[idx + i] = merging[i];
}

void mergeSort(vector<ull> &numbers, ull size, ull idx)
{
    if(size == 1) return;

    ull size_left = size/2; 
    ull size_right = size - size_left;

    mergeSort(numbers, size_left, idx);
    mergeSort(numbers, size_right, size_left + idx);
    merge(numbers, size_left, size_right, idx);
}

int main(int argc, char const *argv[])
{
    ull n;
    cin >> n;

    vector<ull> numbers(n);

    for (ull i = 0; i < n; ++i)
        cin >> numbers[i];

    mergeSort(numbers, n, 0);
    cout << inversions << endl;

    return 0;
}