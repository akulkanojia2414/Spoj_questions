#include <iostream>
using namespace std;
int a[109];
int main()
{
	int t;
	unsigned long long n,m,s;
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>s;



            cout<<(s+m%n)%n<<endl;

	}
    return 0;
}
