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
int a[200001];
int b[200001];
int tree[200001];
int n,x,y,m,i,j,temp;
ll inv_count,t;
void update(int idx ,int val){
	while (idx <= n){
		tree[idx] += val;
		idx += (idx & -idx);
	}
}
int read(int idx){
	int sum = 0;
	while (idx > 0){
		sum += tree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}

int main()

{

	cin>>n>>m;
	for( i =1;i<=n;i++)
	{cin>>a[i]; b[i] = a[i];}
	sort(b+1,b+n+1);
for( i = 1; i <=n; i++) {
         int rank = int(lower_bound(b, b + n, a[i]) - b);
         a[i] = rank ;
      }

	while(m--)
	{
	cin>>x>>y;

	 temp = a[x];
	a[x] = a[y];
	a[y]= temp;
	inv_count=0;
	for(int i = n - 1; i >= 0; --i) {
          t = read(a[i] - 1);
         inv_count += t;
         update(a[i], 1);
      }
	CLR(tree);
	cout<<inv_count<<endl;

 temp = a[x];
	a[x] = a[y];
	a[y]= temp;
	}
}
