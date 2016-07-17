#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

struct data
{
    long long min;
    long long max;
};

vector<int> operators;  // 1:+, 2:-, 3:*
vector<long long> numbers;

long long applyOperation(long long A, long long B, int k)
{
    long long result;

    switch(operators[k])
    {
        case 1: result = A + B; break;
        case 2: result = A - B; break;
        case 3: result = A * B; break;
    }

    return result;
}

data MinAndMax(int i, int j, vector<vector<long long> > m, vector<vector<long long> > M)
{
    long long minValue = LONG_MAX;
    long long maxValue = LONG_MIN;
    long long A, B, C, D;

    for (int k = i; k <= j - 1; ++k)
    {
        A = applyOperation(M[i][k], M[k+1][j], k);
        B = applyOperation(M[i][k], m[k+1][j], k);
        C = applyOperation(m[i][k], M[k+1][j], k);
        D = applyOperation(m[i][k], m[k+1][j], k);

        minValue = min(minValue, min(A, min(B, min(C, D))));
        maxValue = max(maxValue, max(A, max(B, max(C, D))));
    }

    data mm;
    mm.min = minValue;
    mm.max = maxValue;

    return mm;
}

void printMatrix(vector<vector<long long> > M, int n)
{
    cout << "------------------" << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << M[i][j] << " ";
        }

        cout << endl;
    }
    cout << "------------------" << endl;
}

int main() 
{
    string expresion;
    cin >> expresion;

    for (int i = 0; i < expresion.length(); ++i)
    {
        if(expresion[i] != '+' && expresion[i] != '-' && expresion[i] != '*') numbers.push_back(expresion[i] - 48);
        else
        {
            if(expresion[i] == '+') operators.push_back(1);
            if(expresion[i] == '-') operators.push_back(2);
            if(expresion[i] == '*') operators.push_back(3);
        }
    }

    int n = numbers.size(), j;

    vector<vector<long long> > m(n, vector<long long>(n));
    vector<vector<long long> > M(n, vector<long long>(n));

    for (int i = 0; i < n; ++i)
    {
        M[i][i] = m[i][i] = numbers[i];
    }

    data mm;

    for (int s = 1; s < n; ++s)
    {
        for (int i = 0; i < n - s; ++i)
        {
            j = i + s;
            mm = MinAndMax(i, j, m, M);
            m[i][j] = mm.min;
            M[i][j] = mm.max;
        }
    }

    cout << M[0][n-1] << endl;

    return 0;
}