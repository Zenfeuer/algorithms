#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() 
{
    string A, B;
    cin >> A >> B;

    int n = A.length(), m = B.length(), insertion, deletion, match, mismatch;

    vector<vector<int> > D(n + 1, vector<int>(m + 1));

    for (int i = 0; i <= n; ++i)
    {
        D[i][0] = i;
    }

    for (int i = 0; i <= m; ++i)
    {
        D[0][i] = i;
    }

    for (int j = 1; j <= m; ++j)
    {
        for (int i = 1; i <= n; ++i)
        {
            insertion = D[i][j-1] + 1;
            deletion  = D[i-1][j] + 1;
            match     = D[i-1][j-1];
            mismatch  = D[i-1][j-1] + 1;

            if(A[i-1] == B[j-1])
            {
                D[i][j] = min(insertion, min(deletion, match));
            }
            else
            {
                D[i][j] = min(insertion, min(deletion, mismatch));
            }
        }
    }

    cout << D[n][m] << endl;

    return 0;
}