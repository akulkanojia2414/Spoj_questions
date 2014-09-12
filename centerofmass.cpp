
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
	int t,temp;
	double n;
	cin>>t;
	temp = t;
	while(t--)
	{
		cin>>n;
		double a[6];
		double x=0.0,y=0.0,z=0.0,vx=0.0,vy=0.0,vz=0.0;
		for(int i =0;i<n;i++)
		{
			cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]>>a[5];
			x+=a[0];
			y+=a[1];
			z+=a[2];
			vx+=a[3];
			vy+=a[4];
			vz+=a[5];
		}
		x/=n;y/=n;z/=n;vx/=n;vy/=n;vz/=n;
		double prodx,prody;
		prodx = -1*(x*vx+y*vy+z*vz);
		prody = vx*vx + vy*vy + vz*vz;
		double time;
		if(prody==0) time = 0;
		else time =  (prodx/prody);
		if(time<0) {time=0;}
		double dist;

		dist = (x + vx*time)*(x + vx*time)+(y + vy*time)*(y + vy*time) + (z + vz*time)*(z + vz*time);
		printf("Case #%d: %.8f %.8f\n",temp-t,sqrt(dist),time);
	}
}
