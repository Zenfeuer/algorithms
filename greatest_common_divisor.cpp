#include <iostream>
using namespace std;

unsigned long gdc(unsigned long a, unsigned long b)
{
	if(b == 0) return a;
	return gdc(b, a%b);
}

int main() 
{
	unsigned long a, b;
	cin >> a >> b;
	
	if(a < b) swap(a,b);
	
	cout << gdc(a, b) << endl;
	
	return 0;
}