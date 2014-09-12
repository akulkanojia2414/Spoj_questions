
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

char sym[94];
char a[1000000];
vector<char> d(1000000);
int main()
{
	//cout<<(char)126;
	int t,n;
	char x,y,c;
	cin>>t;
	while(t--)
	{
		for(int i =0;i<=93;i++)
		{sym[i]=(char)(i+33); }
		cin>>n;
		for(int i =0;i<n;i++)
		{
			cin>>x>>y;
			//cout<<x-33<<y;
			sym[x-33] = y;
		}
		//cout<<sym['#'-33];
		cin>>a;

		int len = strlen(a);
		bool yes = false;
		for(int i =0;i<len;i++)
		{
			c = sym[a[i]-33];
			d[i] = c;
			if(d[i]=='.') yes = true;
			a[i] = '\0';
		}
		int h,j;
		h=0;
		while(d[h]=='0') h++;
		j=len-1;
		while(d[j]=='0'&&yes) {j--;}
		if(d[j]=='.') j--;
		//cout<<h<<j<<endl;
		if((h==j+1||h==len-1||j==-1)&&h!=j) cout<<"0";
		else
		for(int i=h;i<=j;i++)	cout<<d[i];
		cout<<endl;
		//maps.clear();
	d.clear();
	}
}
