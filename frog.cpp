
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
#include <limits.h>
#include <cstdlib>
#include <stack>


#define abs(x) ((x)>=0? (x):(-x))
#define gc getchar_unlocked
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
int tree[100001];

int read(int idx){
	int sum = 0;
	while (idx > 0){
		sum += tree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}

void update(int idx ,int val,int MaxVal){
	while (idx <= MaxVal){
		tree[idx] += val;
		idx += (idx & -idx);
	}
}
int get()
{
  register char c;
  while(c=gc(),(c<'0'||c>'9')&&(c!='-'));
  bool flag=(c=='-');
  if(flag)
    c=gc();
  int x=0;
  while(c>='0'&&c<='9')
    {
      x=x*10+c-48;
      c=gc();
    }
  return flag?-x:x;
}

pair<int,int> a[100001];
int c[100001];
int main()
{
	int n,k,p;
	n = get();
	k = get();
	p = get();
	for(int i=1;i<=n;i++)
	{
		a[i].first = get();
		a[i].second = i ;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		c[a[i].second] = i;
	}

	for(int i =2;i<=n;i++)
	{
		if(a[i].first - a[i-1].first <= k) update(i-1,1,n);
	}
	//for(int i =1;i<=n;i++) cout<<tree[i]<<endl;
	int x,y;
	for(int i=0;i<p;i++)
	{
		x = get();
		y = get();
		int temp = read(c[y]-1) - read(c[x]-1);
		int temp1 = c[y] - c[x] ;
		//cout<<temp<<" "<<temp1;
		if(temp==temp1) printf("%s\n","Yes");
		else printf("%s\n","No");
	}

}


