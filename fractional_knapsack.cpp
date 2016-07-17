#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

struct item
{
	int value;
	int weight;
	double vw;
};

vector<item> items;

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

	sortItems(n);
	maxValue = knapsack(totalW, n);

	cout << fixed << setprecision(4) << maxValue << endl;

	return 0;
}