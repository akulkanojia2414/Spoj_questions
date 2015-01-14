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
char a[110][110];
bool visited[110][110];

int counti[110][110];
int main()
{
	int t,x,z,i,j,starti,startj,endi,endj;
	bool r,g,b,y;
	cin>>t;
	while(t--)
	{	queue<pair<int,int> > q;r = false;
		b = false;
		g = false;
		y = false;
		cin>>x>>z;
		for( i =0;i<x;i++)
		{
			for( j=0;j<z;j++)
			{
				cin>>a[i][j];
				if(a[i][j]=='*') {starti = i; startj= j;}
				if(a[i][j] == 'X' ) {endi = i ; endj = j;}
			}
		}
		q.push(make_pair(starti,startj));
		visited[0][0] = true;
		pair<int,int> p;
		while(!q.empty())
		{
			p = q.front();
			q.pop();
			i = p.first;
			j = p.second;
			//cout<<i<<" "<<j<<endl;
			if(a[i][j] == '*')
			{
				if(i>0&&visited[i-1][j] == false){q.push(make_pair(i-1,j)); visited[i-1][j] = true; counti[i-1][j] = counti[i][j]+1;}
				if(j>0&& visited[i][j-1] == false){q.push(make_pair(i,j-1)); visited[i][j-1] = true;counti[i][j-1] = counti[i][j]+1;}
				if(i<x-1&&visited[i+1][j] == false){q.push(make_pair(i+1,j)); visited[i+1][j] = true;counti[i+1][j] = counti[i][j]+1;}
				if(j<z-1&&visited[i][j+1] == false){q.push(make_pair(i,j+1)); visited[i][j+1] = true;counti[i][j+1] = counti[i][j]+1;}
			}
			if(a[i][j] == 'X') { break;}
			if(a[i][j] == 'r') {r = true;if(i>0&&visited[i-1][j] == false){q.push(make_pair(i-1,j)); visited[i-1][j] = true; counti[i-1][j] = counti[i][j]+1;}
				if(j>0&& visited[i][j-1] == false){q.push(make_pair(i,j-1)); visited[i][j-1] = true;counti[i][j-1] = counti[i][j]+1;}
				if(i<x-1&&visited[i+1][j] == false){q.push(make_pair(i+1,j)); visited[i+1][j] = true;counti[i+1][j] = counti[i][j]+1;}
				if(j<z-1&&visited[i][j+1] == false){q.push(make_pair(i,j+1)); visited[i][j+1] = true;counti[i][j+1] = counti[i][j]+1;}}
			if(a[i][j] == 'g')
			{g = true;
				if(i>0&&visited[i-1][j] == false){q.push(make_pair(i-1,j)); visited[i-1][j] = true; counti[i-1][j] = counti[i][j]+1;}
				if(j>0&& visited[i][j-1] == false){q.push(make_pair(i,j-1)); visited[i][j-1] = true;counti[i][j-1] = counti[i][j]+1;}
				if(i<x-1&&visited[i+1][j] == false){q.push(make_pair(i+1,j)); visited[i+1][j] = true;counti[i+1][j] = counti[i][j]+1;}
				if(j<z-1&&visited[i][j+1] == false){q.push(make_pair(i,j+1)); visited[i][j+1] = true;counti[i][j+1] = counti[i][j]+1;}
			}
			if(a[i][j] == 'b')
			{b = true;
			if(i>0&&visited[i-1][j] == false){q.push(make_pair(i-1,j)); visited[i-1][j] = true; counti[i-1][j] = counti[i][j]+1;}
				if(j>0&& visited[i][j-1] == false){q.push(make_pair(i,j-1)); visited[i][j-1] = true;counti[i][j-1] = counti[i][j]+1;}
				if(i<x-1&&visited[i+1][j] == false){q.push(make_pair(i+1,j)); visited[i+1][j] = true;counti[i+1][j] = counti[i][j]+1;}
				if(j<z-1&&visited[i][j+1] == false){q.push(make_pair(i,j+1)); visited[i][j+1] = true;counti[i][j+1] = counti[i][j]+1;}
			}
			if(a[i][j] == 'y')
			{y = true;
				if(i>0&&visited[i-1][j] == false){q.push(make_pair(i-1,j)); visited[i-1][j] = true; counti[i-1][j] = counti[i][j]+1;}
				if(j>0&& visited[i][j-1] == false){q.push(make_pair(i,j-1)); visited[i][j-1] = true;counti[i][j-1] = counti[i][j]+1;}
				if(i<x-1&&visited[i+1][j] == false){q.push(make_pair(i+1,j)); visited[i+1][j] = true;counti[i+1][j] = counti[i][j]+1;}
				if(j<z-1&&visited[i][j+1] == false){q.push(make_pair(i,j+1)); visited[i][j+1] = true;counti[i][j+1] = counti[i][j]+1;}
			}
			if(a[i][j] == '#') continue;
			if(a[i][j] =='.')
			{
				if(i>0&&visited[i-1][j] == false){q.push(make_pair(i-1,j)); visited[i-1][j] = true; counti[i-1][j] = counti[i][j]+1;}
				if(j>0&& visited[i][j-1] == false){q.push(make_pair(i,j-1)); visited[i][j-1] = true;counti[i][j-1] = counti[i][j]+1;}
				if(i<x-1&&visited[i+1][j] == false){q.push(make_pair(i+1,j)); visited[i+1][j] = true;counti[i+1][j] = counti[i][j]+1;}
				if(j<z-1&&visited[i][j+1] == false){q.push(make_pair(i,j+1)); visited[i][j+1] = true;counti[i][j+1] = counti[i][j]+1;}
			}
			if(a[i][j] == 'R')
			{
				if(r== false)
				{
					visited[i][j] = false;counti[i][j]--;
					continue;
				}
				else
				{
					if(i>0&&visited[i-1][j] == false){q.push(make_pair(i-1,j)); visited[i-1][j] = true; counti[i-1][j] = counti[i][j]+1;}
				if(j>0&& visited[i][j-1] == false){q.push(make_pair(i,j-1)); visited[i][j-1] = true;counti[i][j-1] = counti[i][j]+1;}
				if(i<x-1&&visited[i+1][j] == false){q.push(make_pair(i+1,j)); visited[i+1][j] = true;counti[i+1][j] = counti[i][j]+1;}
				if(j<z-1&&visited[i][j+1] == false){q.push(make_pair(i,j+1)); visited[i][j+1] = true;counti[i][j+1] = counti[i][j]+1;}
				}
			}
			if(a[i][j] == 'G')
			{
				if(g== false)
				{visited[i][j] = false;counti[i][j]--;
					continue;
				}
				else
				{
					if(i>0&&visited[i-1][j] == false){q.push(make_pair(i-1,j)); visited[i-1][j] = true; counti[i-1][j] = counti[i][j]+1;}
				if(j>0&& visited[i][j-1] == false){q.push(make_pair(i,j-1)); visited[i][j-1] = true;counti[i][j-1] = counti[i][j]+1;}
				if(i<x-1&&visited[i+1][j] == false){q.push(make_pair(i+1,j)); visited[i+1][j] = true;counti[i+1][j] = counti[i][j]+1;}
				if(j<z-1&&visited[i][j+1] == false){q.push(make_pair(i,j+1)); visited[i][j+1] = true;counti[i][j+1] = counti[i][j]+1;}
				}
			}
			if(a[i][j] == 'B')
			{
				if(b== false)
				{visited[i][j] = false;counti[i][j]--;
					continue;
				}
				else
				{
					if(i>0&&visited[i-1][j] == false){q.push(make_pair(i-1,j)); visited[i-1][j] = true; counti[i-1][j] = counti[i][j]+1;}
				if(j>0&& visited[i][j-1] == false){q.push(make_pair(i,j-1)); visited[i][j-1] = true;counti[i][j-1] = counti[i][j]+1;}
				if(i<x-1&&visited[i+1][j] == false){q.push(make_pair(i+1,j)); visited[i+1][j] = true;counti[i+1][j] = counti[i][j]+1;}
				if(j<z-1&&visited[i][j+1] == false){q.push(make_pair(i,j+1)); visited[i][j+1] = true;counti[i][j+1] = counti[i][j]+1;}
				}
			}
			if(a[i][j] == 'Y')
			{
				if(y== false)
				{visited[i][j] = false; counti[i][j]--;
					continue;
				}
				else
				{
					if(i>0&&visited[i-1][j] == false){q.push(make_pair(i-1,j)); visited[i-1][j] = true; counti[i-1][j] = counti[i][j]+1;}
				if(j>0&& visited[i][j-1] == false){q.push(make_pair(i,j-1)); visited[i][j-1] = true;counti[i][j-1] = counti[i][j]+1;}
				if(i<x-1&&visited[i+1][j] == false){q.push(make_pair(i+1,j)); visited[i+1][j] = true;counti[i+1][j] = counti[i][j]+1;}
				if(j<z-1&&visited[i][j+1] == false){q.push(make_pair(i,j+1)); visited[i][j+1] = true;counti[i][j+1] = counti[i][j]+1;}
				}
			}

		}
		if(visited[endi][endj]== false) cout<<"Trapped!"<<endl;
			else cout<<counti[endi][endj]<<endl;
			CLR(a);CLR(visited);CLR(counti);
	}
}


