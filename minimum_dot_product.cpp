#include <iostream>
#include <vector>
using namespace std;

vector<long> a;
vector<long> b;

void sortVectors(long n)
{
	for(long i = 0; i < n; i++)
	{
		for(long j = 0; j < n - 1; j++)
		{
			if(a[j] < a[j+1])
			{
				long backup = a[j];
				a[j] = a[j+1];
				a[j+1] = backup;
			}

			if(b[j] > b[j+1])
			{
				long backup = b[j];
				b[j] = b[j+1];
				b[j+1] = backup;
			}
		}
	}
}

long minimumDotProduct(long n)
{
	long sum = 0;

	for(long i = 0; i < n; i++)
	{
		sum += a[i]*b[i];
	}

	return sum;
}

int main(int argc, char const *argv[])
{
	int n, value;
	cin >> n;

	if(n == 1)
	{
		long value2;
		cin >> value >> value2;
		cout << value*value2 << endl;
	}
	else
	{
		for (long i = 0; i < n*2; ++i)
		{
			cin >> value;
			if(i < n) a.push_back(value);
			else b.push_back(value);
		}

		sortVectors(n);
		
		cout << minimumDotProduct(n) << endl;
	}

	return 0;
}