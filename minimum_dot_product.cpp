/**
 * Purpose: Dot product of two sequences A = a1,a2,...,an and B = b1,b2,...,bn of the 
 * 			same length, using a greedy algorithm.
 * 			
 * 					a1*b1 + a2*b2 + ... + an*bn
 * 			
 * Input: 	First line: single integer n (number of items in each sequence)
 * 			Next 2 lines: Sequences A and B with n items each one.
 *
 * Constraints: 1 <= n <= 10^3; -10^5 <= ai,bi <= 10^5
 * 			
 * Output: 	Maximal value of fractions of items that fit into the knapsack with precision
 * 			of 10^-4.
 */

#include <iostream>
#include <vector>
using namespace std;

vector<long> a;
vector<long> b;

/**
 * Sorts the items worst case O(n^2) of two sequences.
 * This can be improved with a better sort method like Mergesort.
 * 
 * @param n length of the sequences
 */
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

/**
 * Calculates the dot product of the two sequences.
 * 
 * @param  n length of the sequences
 * @return   the minimum dot product
 */
long minimumDotProduct(long n)
{
	long sum = 0;

	for(long i = 0; i < n; i++)
		sum += a[i]*b[i];

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

		// Safe move: sort the sequences where one sequence
		// is sorted desc and the other asc. This ensures
		// when dot product is applied, it obtains the minimum
		// possible value.
		sortVectors(n);
		cout << minimumDotProduct(n) << endl;
	}

	return 0;
}