#include <iostream>
#include <vector>
using namespace std;

struct point
{
	int xmin;
	int xmax;
};

vector<point> points;
vector<int> refs;

void sortVector(int n)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n - 1; j++)
		{
			if(points[j].xmax > points[j+1].xmax)
			{
				point backup = points[j];
				points[j] = points[j+1];
				points[j+1] = backup;
			}
		}
	}
}

void covering(int n)
{
	point ref = points[0];
	refs.push_back(ref.xmax);

	for(int i = 1; i < n; i++)
	{
		if(points[i].xmin > ref.xmax)
		{
			ref = points[i];
			refs.push_back(ref.xmax);
		}
	}

	cout << refs.size() << endl;

	for (int i = 0; i < refs.size(); ++i)
	{
		cout << refs[i];
		cout << (i + 1 < refs.size()? " " : "\n");
	}
}

int main(int argc, char const *argv[])
{
	int n, value;
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		point p;
		cin >> p.xmin >> p.xmax;
		points.push_back(p);
	}

	sortVector(n);
	covering(n);

	return 0;
}