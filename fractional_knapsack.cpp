/**
 * Purpose: Resolves the fractional knapsack problem (greedy algorithm).
 * 
 * Input: 	First line: two integers n (number of items), and W (capacity of knapsack)
 * 			Next n lines: pair values (vi,wi), where vi is the value of the ith item
 * 			and wi its weight.
 * 			
 * Output: 	Maximal value of fractions of items that fit into the knapsack with precision
 * 			of 10^-4.
 */

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

// item to be stored in the knapsack
struct item
{
	int value;
	int weight;
	double vw;	// value/weight
};

vector<item> items;

/**
 * Sorts the items worst case O(n^2).
 * This can be improved with a better sort method like Mergesort.
 * @param n length of the vector
 */
void sortItems(int n)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n - 1; j++)
		{
			if(items[j].vw < items[j+1].vw)
			{
				item backup = items[j];
				items[j] = items[j+1];
				items[j+1] = backup;
			}
		}
	}
}

/**
 * Resolves the fractional knapsack problem in iterative way.
 * It assumes that the items are desc sorted.
 * 
 * @param  totalW knapsack weight
 * @param  n      number of items
 * @return        maximum value of fractions 
 */
double knapsack(double totalW, int n)
{
	double maxValue = 0.0;
	int idx = 0;

	while(totalW > 0)
	{
		if(items[idx].weight <= totalW)
		{
			totalW -= items[idx].weight;
			maxValue += items[idx].value;
		}
		else
		{
			maxValue += items[idx].vw*totalW;
			totalW -= totalW;
		}

		idx++;
		if(idx >= n) break;
	}

	return maxValue;
}

int main(int argc, char const *argv[])
{
	int n;
	double maxValue, totalW;
	cin >> n >> totalW;

	for(int i = 0; i < n; i++)
	{
		item ii;
		cin >> ii.value >> ii.weight;
		ii.vw = (double)ii.value/ii.weight;
		items.push_back(ii);
	}

	// Safe move: desc sort  of the items
	sortItems(n);
	
	maxValue = knapsack(totalW, n);
	cout << fixed << setprecision(4) << maxValue << endl;

	return 0;
}