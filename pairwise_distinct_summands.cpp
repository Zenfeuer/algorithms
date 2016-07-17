#include <iostream>
#include <vector>
using namespace std;

vector<unsigned long> numbers;

int main(int argc, char const *argv[])
{
	unsigned long n, value;
	cin >> n;

	if(n < 3) cout << "1" << "\n" << n << endl;
	else
	{
		numbers.push_back(1);
		int i = 0;
		unsigned long sum = 1;
		unsigned long tmp = 1;
		unsigned long tmp2;

		while(true)
		{
			if(sum == n) break;

			tmp += numbers[i] + 1;
			tmp2 = n - tmp;

			if(numbers[i] + 2 > tmp2)
			{
				numbers.push_back(n - sum);
				break;
			}
			else
			{
				sum += numbers[i] + 1;
				tmp = sum;
				numbers.push_back(numbers[i] + 1);
				i++;
			}
		}

		cout << numbers.size() << endl;

		for (i = 0; i < numbers.size(); ++i)
		{
			cout << numbers[i];
			cout << (i + 1 < numbers.size()? " " : "\n");
		}
	}

	return 0;
}