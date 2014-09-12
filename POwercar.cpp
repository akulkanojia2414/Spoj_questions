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
struct node
{
	int idx;
	int cost;
	int bullets;
	bool onroad;
	node(int a,int b,int c,bool f)
	{
		idx = a;
		cost = b;
		bullets = c;
		onroad = f;
	}
};
int a[1001];
int main()
{

	int t,n,b;
	cin>>t;
	while(t--)
	{
		queue<node> q;
		char x;
		cin>>n>>b;
		a[0] =-1;
		a[n-1] = -1;
		cin>>x;
		for(int i=1;i<n-1;i++)
		{
			cin>>x;
			if(x=='0') a[i] = 0;
			if(x=='#') a[i] = 1;
		}cin>>x;
		//for(int i =0;i<n;i++)
		//cout<<a[i]<<endl;
		q.push(node(0,0,b,true));
		while(!q.empty())
		{
			node temp = q.front();
			q.pop(); //cout<<temp.idx<<" "<<temp.cost<<" "<<temp.bullets<<endl;
			if(a[temp.idx+1]==-1)
			{
				if(a[temp.idx]==0||a[temp.idx]==-1) cout<<temp.cost+1<<endl;
				else {if(temp.onroad)cout<<temp.cost+1<<endl;
						else cout<<temp.cost+4<<endl;}
					while(!q.empty()) q.pop();
				break;
			}


			if(a[temp.idx]==0||a[temp.idx]==-1)
			{
				if(a[temp.idx+1]==0) q.push(node(temp.idx+1,temp.cost+1,temp.bullets,temp.onroad));
				else if(a[temp.idx+1]==1)
				{
					if(temp.bullets>0)
						q.push(node(temp.idx+1,temp.cost+1,temp.bullets-1,temp.onroad));
					else	q.push(node(temp.idx+1,temp.cost+4,temp.bullets,!temp.onroad));
				}
			}
			else
			{
				if(a[temp.idx+1]==0)
				{
					if(temp.onroad)
					{
						q.push(node(temp.idx+1,temp.cost+1,temp.bullets,temp.onroad));
					}
					else
					{
						q.push(node(temp.idx+1,temp.cost+4,temp.bullets,!temp.onroad));
					}
				}
				else if(a[temp.idx+1]==1)
				{
					if(temp.onroad)
					{
					if(temp.bullets>0)
					q.push(node(temp.idx+1,temp.cost+1,temp.bullets-1,temp.onroad));
					else q.push(node(temp.idx+1,temp.cost+4,temp.bullets,!temp.onroad));
					}
					else
					{
					q.push(node(temp.idx+1,temp.cost+2,temp.bullets,temp.onroad));
					}
				}
			}

		}
		CLR(a);
	}
}


