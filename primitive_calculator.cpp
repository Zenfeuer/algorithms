#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int main() 
{
    long n, i, j, operations, pointer_push = -1;
    cin >> n;

    vector<long> minimunSteps(n + 1);
    vector<long> pointers;
    vector<long> pointers_to_print;

    pointers.push_back(1);

    minimunSteps[0] = 0;
    minimunSteps[1] = 0;

    for (i = 2; i < n + 1; ++i)
    {
        minimunSteps[i] = LONG_MAX;

        if(i >= 1)
        {
            operations = minimunSteps[i - 1] + 1;

            if(operations < minimunSteps[i])
            { 
                minimunSteps[i] = operations;
                pointer_push = i - 1;
            }
        }

        if(i%2 == 0)
        {
            operations = minimunSteps[i/2] + 1;

            if(operations < minimunSteps[i])
            {
                minimunSteps[i] = operations;
                pointer_push = i/2;
            }
        }

        if(i%3 == 0)
        {
            operations = minimunSteps[i/3] + 1;

            if(operations < minimunSteps[i])
            {
                minimunSteps[i] = operations;
                pointer_push = i/3;
            }
        }

        if(pointer_push > 0)
        {
            pointers.push_back(pointer_push);
        }

        pointer_push = -1;
    }

    pointers_to_print.push_back(n);

    j = minimunSteps[n];

    long k = pointers[n-1];

    while (j > 0)
    {
        pointers_to_print.push_back(k);
        k = pointers[k-1];
        j--;
    }

    cout << minimunSteps[n] << endl;

    for (j = pointers_to_print.size() - 1; j >= 0; j--)
    {
        cout << pointers_to_print[j] << " ";
    }

    cout << endl;

    return 0;
}