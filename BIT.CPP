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
//#define MAXVAL 10001
ll tree[10002]={0};
ll read(int idx){
	ll sum = 0;
	while (idx > 0){
		sum += tree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}void update(int idx ,int val,int MaxVal){
	while (idx <= MaxVal){
		tree[idx] += val;
		idx += (idx & -idx);
	}
}


int get()
{
        int num=0;
       register char ch=gc();
        while(ch<'0' || ch>'9')
                ch=gc();
        while(ch>='0' && ch<='9')
        {
                num=(num<<1)+(num<<3)+(ch-48);
                ch=gc();
        }
        return num;
}
void output(ll x)
{
  if(x<0)
    {
      putchar_unlocked('-');
      x=-x;
    }
  int len=0,data[10];
  while(x)
    {
      data[len++]=x%10;
      x/=10;
    }
  if(!len)
    data[len++]=0;
  while(len--)
    putchar_unlocked(data[len]+48);
  putchar_unlocked('\n');
}
int main()
{
	int t,n,u,q,l,r,val;
	t = get();
	while(t--)
	{
		n = get();
		u = get();
		for(int i =0;i<u;i++)
		{
			l = get();
			r = get();
			val = get();
			update(l+1,val,n); update(r+2,-val,n);
			//for(int i =0;i<=n;i++) //cout<<tree[i]<<" "; cout<<endl;
		}
		q= get();
	while(q--){
	u = get();
	output(read(u+1));}
	CLR(tree);
	}

}


