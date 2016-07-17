#include <iostream>
using namespace std;

int optimalSolution(int m)
{
	int total = 0;
	if(m/10 > 0){ total += m/10;  m = m - (m/10)*10; }
	if(m - 5 >= 0){ total += 1;  m = m - 5; }
	if(m > 0){ total += m; }

	return total;
}

int slowSolution(int m)
{
	int total = 0;
	int idx = 0;

	while(total < m)
	{
		if(total + 10 <= m) total += 10;
		else if(total + 5 <= m) total += 5;
		else if(total + 1 <= m) total++;
		idx++;
	}

	return idx;
}


int main(int argc, char const *argv[])
{
	int m;
	cin >> m;

	cout << optimalSolution(m) << endl;

	return 0;
}