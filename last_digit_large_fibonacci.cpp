#include <iostream>
using namespace std;

int main() 
{
	int n;
	unsigned long prevElem1 = 0;
	unsigned long prevElem2 = 1;
	unsigned long currentElem = 0;
	
	cin >> n;
	
	if(n == 0) cout << 0 << endl;
	else if(n == 1) cout << 1 << endl;
	else
	{
		while(n-- >= 2)
		{
			currentElem = (prevElem1%10 + prevElem2%10)%10;
			prevElem1 = prevElem2;
			prevElem2 = currentElem;
		}
		
		cout << currentElem << endl;
	}
	
	return 0;
}