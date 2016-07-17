#include <iostream>
using namespace std;

int main() 
{
	unsigned long n, m;
	cin >> n >> m;
	
	unsigned long pisano = 0;
	unsigned long fi = 0;
	unsigned long fi_0 = 0;
	unsigned long fi_1 = 1;
	
	while(true)
	{
		if(pisano && fi_0%m == 0 && fi_1%m == 1) break;

		fi = (fi_0 + fi_1)%m;
		fi_0 = fi_1;
		fi_1 = fi;
		
		pisano++;
	}
	
	fi = 0;
	fi_0 = 0;
	fi_1 = 1;

	unsigned int lim = n%pisano;
	
	if(lim == 0) fi = 0;
	else if(lim == 1) fi = 1;
	else
	{
		for(unsigned int i = 2; i <= lim; i++)
		{
			fi = (fi_0%m + fi_1%m)%m;
			fi_0 = fi_1%m;
			fi_1 = fi;
		}
	}
	
	cout << fi << endl;

	return 0;
}