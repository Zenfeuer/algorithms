#include <iostream>
#include <vector>

using namespace std;

int main() 
{
    long W, n, i, w, val;
    cin >> W >> n;

    vector<long> bars(n);

    for (i = 0; i < n; ++i)
    {
        cin >> bars[i];
    }

    vector<vector<long> > values(W + 1, vector<long>(n + 1));

    for (i = 1; i <= n; ++i)
    {
        for (w = 1; w <= W; ++w)
        {
            values[w][i] = values[w][i - 1];

            if(bars[i - 1] <= w)
            {
                val = values[w - bars[i - 1]][i - 1] + bars[i - 1];
                if(values[w][i] < val) values[w][i] = val;
            }
        }
    }

    cout << values[W][n] << endl;

    return 0;
}