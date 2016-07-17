#include <iostream>
using namespace std;

unsigned long lcm(unsigned long a, unsigned long b)
{
	if(b == 0) return a;
	return lcm(b, a%b);
}

int main() 
{
	unsigned long a, b;
	cin >> a >> b;
	
	if(a < b) swap(a,b);
	
	cout << (a*b)/lcm(a, b) << endl;
	
	return 0;
}