
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
#include <map>
#include <vector>
#include <list>
#include <string>
#include <set>
#include <queue>
#include <ctime>
#include <fstream>
#include <sstream>
#include <cmath>
#include <limits>


#define abs(x) ((x)>=0? (x):(-x))
#define gc getchar()
#define s(x) scanf("%d",&x)
#define sil(x) scanf("%llu",&x)
#define sd(x) scanf("%ld",&x)
#define in(s) cin>>s
#define FOR(i,a,b) for( typeof(a) i=(a); i<(b); ++i) // exclusive for
#define FORR(i,a,b) for( typeof(a) i=(a-1) ; i>=(b); --i)
#define REP(k,a,b) for(typeof(a) k=(a); k <= (b); ++k) // inclusive for
#define REPR(i,a,b) for( typeof(a) i=(a) ; i>=(b); --i)
#define ALL(c) (c).begin(), (c).end()
#define PB push_back
#define MP make_pair
#define SZ(x) ((int)((x).size()))
#define SRT(v) std::sort(ALL(v))
#define CTN(x) std::cout<<x<<'\n' //cout with newline
#define CTS(x) std::cout<<x<<" " //cout with space
#define CT(x) std::cout<<x
#define CLR(x) std::memset(x,0,sizeof(x))
#define FILL(x,n) std::fill_n(x,sizeof(x),n)
#define T(t) int t=read<int>();// while(t--)
#define DBGA(x,n) {for(int i=0;i<n;i++) cout<<x[i]<<" "; cout<<"\n";}
#define REC(x) clock_t x=clock()
#define CPS CLOCKS_PER_SEC
#define TM(x,y) CTN(((double)(y-x)/CPS));


typedef std::vector<int> VI;
typedef std::vector<long long int> VL;
typedef std::vector<unsigned long long int> VULL;
typedef std::vector<std::string> VS;
typedef std::map<int,int> MI;
typedef std::pair<int,int> PII;
typedef std::string str;
typedef unsigned long long ull;
typedef long long ll;
typedef long int li;


using namespace std;


int main()
{
	int t,n,m;
	cin>>t;
	while(t--)
	{
		vector<pair<int,int> > vec;
		cin>>n>>m;
		int a[n][m];
		int b[n][m];
		if(n==1||m==1)
		{
			cout<<1<<endl;
			break;
		}
		for(int i =0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cin>>a[i][j];
				b[i][j] = 1;
			}
		}
		/*for(int i =n-1;i>=0;i--)
		{
			for(int j=m-1;j>=0;j--)
			{
				vec.push_back(make_pair(i+1,j+1));
			}
		}
		pair<int,int> p;
	*/
		int x = 0, y= 0;
		bool flag = true,real = true;
		while(flag||real)
		{

			flag = false;
			real = false;
				if(a[x+1][y]>a[x][y]&&x<n-1)
				{
					vec.push_back(make_pair(x+1,y));
					flag = true;
					b[x+1][y]+=b[x][y];

				}
				if(a[x][y+1]>a[x][y]&&y<m-1)
				{

					vec.push_back(make_pair(x,y+1));
					flag = true;
					b[x][y+1]+=b[x][y];

				}

				 for (std::vector<pair<int,int> >::iterator it = vec.begin() ; it != vec.end(); ++it)
    std::cout << (*it).first<<" " <<(*it).second;
    cout<<endl;
	if(!vec.empty()) real = true;
				x = vec.back().first;
				y =  vec.back().second;
				vec.pop_back();

				 for (std::vector<pair<int,int> >::iterator it =vec.begin() ; it != vec.end(); ++it)
    std::cout <<(*it).first<< " " <<(*it).second;
		cout<<endl;
		}

		int max =0;
		for(int i =0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cout<<b[i][j]<<" ";
				if(b[i][j]>max) max = b[i][j];
			}
		cout<<endl;
		}
		cout<<max<<endl;
}}
