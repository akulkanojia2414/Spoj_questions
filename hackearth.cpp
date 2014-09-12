	#include <iostream>
	#include <cstdio>
	#include <cstring>
	#include <algorithm>
	#include <utility>
	#include<stack>
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

	struct e
	{
		int a;
		int b;
	};
	int n,m,temp1,temp2;
	bool visit[500501]={0};
	typedef struct e Edge;
	Edge edges[500501];
	stack<int> s;
	int j =1,ctr=0;



	bool comp(Edge x,Edge y){if(x.a<y.a) return true; return false;}
	int main()
	{
		cin>>n>>m;
		for(int i =1;i<=m;i++)
		{
			cin>>temp1>>temp2;
			if(temp1>temp2) {edges[i].a=temp2; edges[i].b = temp1;}
			else {edges[i].b = temp2; edges[i].a= temp1;}
		}
		sort(edges+1,edges+m+1,comp);
		s.push(1);
		int cur;
		while(j<=m)
		{
			while(!s.empty())
			{
				cur = s.top();
				s.pop();
				visit[cur] = true;
				while(edges[j].a == cur) {s.push(edges[j].b); j++;}
			}
			if(visit[edges[j].a]==false&&j<=m){
			s.push(edges[j].a);}
			ctr++;
		}
		for(int i =1;i<=n;i++) if(visit[i]==false) ctr++;
		cout<<ctr<<endl;
	}

