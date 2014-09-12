
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
vector<int> vec;
int main()
{
	int n1,n2;
	cin>>n1;
	while(n1!=0)
	{
	int a[n1];
	for(int i =0;i<n1;i++)
	{
		cin>>a[i];
	}
	cin>>n2;
	int b[n2];
	for(int i =0;i<n2;i++)
	{
		cin>>b[i];
	}

	int i =0,j=0;
	while(i<n1&&j<n2)
	{	//cout<<i<<" "<<j<<endl;
		if(a[i]<b[j]) i++;
		else if(a[i]>b[j]) j++;
		if(a[i]==b[j]) {vec.push_back(a[i]); i++; j++;}
	}
	//for(int i =0;i<vec.size();i++) cout<<vec[i]<<" ";
	long long sum1=0,sum2 =0;
	int len= vec.size();
	i=0,j=0;
	for(int k =0;k<len;k++)
	{
		//cout<<i<<" "<<j<<" "<<vec[k]<<endl;
		while(a[i]!=vec[k]) {sum1+=a[i]; i++;}
		while(b[j]!=vec[k]) {sum2+=b[j];j++;}
		if(sum1<sum2) sum1 = sum2;
		else sum2 = sum1;
		//cout<<sum1<<" "<<sum2<<endl;
	}
	if(i!=n1) while(i!=n1) { sum1 += a[i]; i++;}
	if(j!=n2) while(j!=n2) { sum2 += b[j];j++;}
	if(sum1<sum2) cout<<sum2<<endl;
	else cout<<sum1<<endl;
	vec.clear();
	cin>>n1;
	}
}
