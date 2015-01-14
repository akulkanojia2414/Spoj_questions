
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
int tree[100010];
queue<pair<int,int> > q;
bool visited[100010];


vector<pair<int,int> > u[100010];
vector<pair<int,int> > :: iterator it;
int main()
{
	int n,x,d,tmp1,tmp2;
	cin>>n;
	//MaxVal = n;
	for(int i =0;i<n-1;i++)
	{
		cin>>tmp1>>tmp2>>d;
		u[tmp1].PB(MP(tmp2,i));
		u[tmp2].PB(MP(tmp1,i));
		tree[i] = d;
	}
	int que;
	cin>>que;
	for(int i =0;i<que;i++)
	{
		cin>>x;
		if(x==1)
		{
			cin>>tmp1>>tmp2;
			tree[tmp1-1] = tmp2;
		}
		if(x==2)
		{
				cin>>tmp1>>tmp2;
				q.push(MP(tmp1,0));
				visited[tmp1] = true;
				int sum ;
			//	cout<<tree[2];
				while(!q.empty())
				{
					pair<int,int> temp = q.front();
					q.pop();
				//	cout<<temp.first<<" "<<temp.second<<endl;
					if(temp.first == tmp2)
					{
						sum = temp.second;
						while(!q.empty()) q.pop();
						break;
					}

					for(it = u[temp.first].begin();it!=u[temp.first].end();it++)
					{
						if(visited[(*it).first] == false)
						q.push(MP((*it).first, tree[(*it).second]+temp.second));
						visited[(*it).first] = true;
					}
				}
				CLR(visited);
				cout<<sum<<endl;
		}
	}
}


