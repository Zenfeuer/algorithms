#include <iostream>
#include <vector>
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