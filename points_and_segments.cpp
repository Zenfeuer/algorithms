// Hacer Binay Search y map para evitar repetidos

#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct point
{
	double value;
	long long count;
	unsigned int index;
	char type;
};

void sortSegments(vector<point> &points, int lo, int hi) 
{ 
    if (hi <= lo) return;

    int lt = lo, gt = hi;
    int i = lo;

    point seg = points[lo];

    while (i <= gt) 
    {
        if (points[i].value < seg.value)      swap(points[lt++], points[i++]);
        else if (points[i].value > seg.value) swap(points[i], points[gt--]);
        else i++; 
    }

    sortSegments(points, lo, lt-1);
    sortSegments(points, gt+1, hi);
}

int main(int argc, char const *argv[])
{
	unsigned int s, p, i = 0, j = 0, k = 0;
	long value;
	cin >> s >> p;

	vector<point> points;
	vector<int> counter(p);
	map<long, int> L;
	map<long, int> R;
	map<long, int>::iterator it;


	while(i < s)
	{
		cin >> value;

		it = L.find(value);
		if(it == L.end())
		{
			point po;
			po.value = value - 0.1f;
			po.count = 1;
			po.type = 'l';
			L[value] = k++;
			//k++;
			points.push_back(po);
		}
		else
		{
			points[L[value]].count++;
		}

		//cout << "ah" << endl;

		cin >> value;

		it = R.find(value);
		if(it == R.end())
		{
			point po;
			po.value = value + 0.1f;
			po.count = 1;
			po.type = 'r';
			R[value] = k++;
			//k++;

			points.push_back(po);
		}
		else
		{
			points[R[value]].count++;
		}

		i++;
	}

	/*for (i = 0; i < s*2; i=i+2)
	{
		cin >> points[i].value;
		points[i].value -= 0.1f;
		points[i].count = 0;
		points[i].type = 'l';

		cin >> points[i+1].value;
		points[i+1].value += 0.1f;
		points[i+1].count = 0;
		points[i+1].type = 'r';
	}*/

	for (i = k; i < k + p; ++i)
	{
		point po;
		cin >> po.value;
		po.count = 0;
		po.type = 'p';
		po.index = i - k;
		points.push_back(po);
	}


	/*for (int i = 0; i < points.size(); ++i)
	{
		cout << points[i].value << " ";
	}*/

	
	sortSegments(points, 0, points.size()-1);

	long long left = 0, right = 0;

	for (i = 0; i < points.size(); ++i)
	{
		if(points[i].type == 'l') left += points[i].count;
		else if(points[i].type == 'r') left -= points[i].count;
		else counter[points[i].index] = left;
	}

	for (i = 0; i < p; ++i)
	{
		cout << counter[i] << (i<p-1?" ":"\n");
	}

	return 0;
}