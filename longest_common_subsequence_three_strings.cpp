#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() 
{
    int n, m, l, i, j, k;
    cin >> n;
    vector<long> A(n);

    for (i = 0; i < n; ++i)
        cin >> A[i];

    cin >> m;
    vector<long> B(m);

    for (i = 0; i < m; ++i)
        cin >> B[i];

    cin >> l;
    vector<long> C(l);

    for (i = 0; i < l; ++i)
        cin >> C[i];

    vector<vector<vector<int> > > D(n + 1, vector<vector<int> >(m + 1, vector<int>(l + 1)));

    for (k = 0; k <= l; ++k)
    {
        for (j = 0; j <= m; ++j)
        {
            for (i = 0; i <= n; ++i)
            {
                if(i == 0 || j == 0 || k == 0)
                {
                    D[i][j][k] = 0;
                }
                else if (A[i-1] == B[j-1] && B[j-1] == C[k-1])
                {
                    D[i][j][k] = D[i-1][j-1][k-1] + 1;
                }
                else
                {
                    D[i][j][k] = max(D[i-1][j][k], max(D[i][j-1][k], max(D[i][j][k-1], D[i-1][j-1][k-1])));
                }
            }
        }
    }

    cout << D[n][m][l] << endl;

    return 0;
}