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
#define FOR(a) for( ll i= 0 ; i<(a); ++i) // exclusive for
#define FORR(a) for( ll i=(a-1) ; i>=(0); --i)
#define REP(a) for(ll k=0; k <= (a); ++k) // inclusive for
#define REPR(a) for( ll i=(a) ; i>=(0); --i)
#define ALL(c) (c).begin(), (c).end()
#define PB push_back
#define MP make_pair
#define SZ(x) ((ll)((x).size()))
#define SRT(v) std::sort(ALL(v))
#define CTN(x) std::cout<<x<<'\n' //cout with newline
#define CTS(x) std::cout<<x<<" " //cout with space
#define CT(x) std::cout<<x
#define CLR(x) std::memset(x,0,sizeof(x))
#define FILL(x,n) std::fill_n(x,sizeof(x),n)
#define T(t) ll t=read<ll>();// while(t--)
#define DBGA(x,n) {for(ll i=0;i<n;i++) cout<<x[i]<<" "; cout<<"\n";}
#define REC(x) clock_t x=clock()
#define CPS CLOCKS_PER_SEC
#define TM(x,y) CTN(((double)(y-x)/CPS));

typedef long long ll;
typedef std::vector<ll> VI;
typedef std::vector<long long ll> VL;
typedef std::vector<unsigned long long ll> VULL;
typedef std::vector<std::string> VS;
typedef std::map<ll,ll> MI;
typedef std::pair<ll,ll> PII;
typedef std::string str;
typedef unsigned long long ull;



using namespace std;
ll ar[200001];

struct node
{
	ll zero;
	ll one;
	ll two;
	node()
	{
		zero = 0;
		one = 0;
		two = 0;
	}
};
node tree[1000001];
ll lazy[200001];
void build_tree(ll n, ll a, ll b) {
    if(a > b) return; // Out of range

  	if(a == b) { // Leaf node
    		if(ar[a] == 0)
				tree[n].zero = 1;
    		else if(ar[a] == 1)
				tree[n].one = 1;
			else tree[n].two = 1;
			return;
	}

	build_tree(n*2, a, (a+b)/2); // Init left child
	build_tree(n*2+1, 1+(a+b)/2, b); // Init right child

	tree[n].zero = tree[n*2].zero + tree[n*2+1].zero;
	tree[n].one = tree[n*2].one + tree[n*2+1].one;
	tree[n].two = tree[n*2].two + tree[n*2+1].two;
}


void update_tree(ll n, ll a, ll b, ll i, ll j, ll value) {
ll temp;
//cout<<a<<" "<<b<<" "<<tree[n].zero<<" "<<tree[n].one<<" "<<tree[n].two<<endl;
if(lazy[n] != 0) { // This node needs to be updated
{
   			if(lazy[n] == 1)
			{
				temp = tree[n].one;
				tree[n].one = tree[n].zero;
				tree[n].zero = tree[n].two;
				tree[n].two = temp;

			}
   			else if(lazy[n]==2)
			{
				temp = tree[n].one;
				tree[n].one = tree[n].two;
				tree[n].two = tree[n].zero;
				tree[n].zero = temp;
			}
   		}
		if(a != b) {
			lazy[n*2] += lazy[n];
			lazy[n*2]%=3; // Mark child as lazy
    			lazy[n*2+1] += lazy[n];
    			lazy[n*2+1]%=3; // Mark child as lazy
		}

   		lazy[n] = 0; // Reset it
  	}

	if(a > b || a > j || b < i) // Current segment is not within range [i, j]
		return;

  	if(a >= i && b <= j) { // Segment is fully within range
			lazy[n]+=value;
			lazy[n]%=3;
				if(lazy[n]==1)
			{
				temp = tree[n].one;
				tree[n].one = tree[n].zero;
				tree[n].zero = tree[n].two;
				tree[n].two = temp;

			}
			else if(lazy[n]==2)
			{
				temp = tree[n].one;
				tree[n].one = tree[n].two;
				tree[n].two = tree[n].zero;
				tree[n].zero = temp;
			}



		if(a != b) {
			lazy[n*2] += lazy[n];
			lazy[n*2]%=3; // Mark child as lazy
    			lazy[n*2+1] += lazy[n];
    			lazy[n*2+1]%=3;
		}
		lazy[n]=0;
	//lazy[n]+=value;
	//lazy[n]%=3;
    		return;
  	}
	update_tree(n*2, a, (a+b)/2, i, j, value);
	update_tree(1+n*2, 1+(a+b)/2, b, i, j, value);

	tree[n].one =(tree[n*2].one + tree[n*2+1].one);
	tree[n].two =(tree[n*2].two + tree[n*2+1].two);
	tree[n].zero =(tree[n*2].zero + tree[n*2+1].zero);
}



node query_tree(ll n, ll a, ll b, ll i, ll j) {
	node tmp;
	//cout<<a<<" "<<b<<tree[n].zero<<" "<<tree[n].one<<" "<<tree[n].two<<endl;
	if(a > b || a > j || b < i) return tmp; // Out of range
	ll temp;
	if(lazy[n]!= 0) { // This node needs to be updated

   			if(lazy[n] == 1)
			{
				temp = tree[n].one;
				tree[n].one = tree[n].zero;
				tree[n].zero = tree[n].two;
				tree[n].two = temp;
			}
   			else if(lazy[n] == 2)
			{
				temp = tree[n].one;
				tree[n].one = tree[n].two;
				tree[n].two = tree[n].zero;
				tree[n].zero = temp;
			}
			if(a != b) {
			lazy[n*2] += lazy[n];
			lazy[n*2]%=3; // Mark child as lazy
    			lazy[n*2+1] += lazy[n];
    			lazy[n*2+1]%=3;
		}

   		lazy[n] = 0; // Reset it

   		}


	if(a >= i && b <= j) // Current segment is totally within range [i, j]
		return tree[n];

	node q1 = query_tree(n*2, a, (a+b)/2, i, j); // Query left child
	node q2 = query_tree(1+n*2, 1+(a+b)/2, b, i, j); // Query right child

	tmp.one = q1.one +q2.one;
	tmp.two = q1.two + q2.two;
	tmp.zero = q1.zero + q2.zero;
	return tmp;
}
void prll(ll n,ll a,ll b){
	cout<<n<<" "<<a<<" "<<b<<" "<<tree[n].zero<<" "<<tree[n].one<<" "<<tree[n].two<<" "<<lazy[n]<<endl;
	if(a!=b){
		ll mid=a+b;mid/=2;
		prll(2*n,a,mid);
		prll(2*n+1,mid+1,b);
	}
	return;
}
char arr[1000001];
int main()
{
	ll n,m;
	cin>>n>>m;
	cin>>arr;
	ar[0] =0;
	for(ll i =1;i<=n;i++)
	{
		ar[i] = ((arr[i-1] -'0')%3 +ar[i-1])%3;
	}
	build_tree(1,1,n);

	ll t,x,y;
	for(ll i =0;i<m;i++)
	{
		cin>>t;
		if(t==1)
		{
			cin>>x>>y;
			//cout<<arr[x]<<endl;
			ll k = y;
			y=(y%3-(arr[x-1] - '0')%3 + 3)%3;
			arr[x-1] = k%3+'0';
			y%=3;
			//cout<<y<<endl;
			update_tree(1,1,n,x,n,y);
			//prll(1,1,n);
		}
		else
		{
			cin>>x>>y;
			node temp;
			if(x!=1)
			    temp = query_tree(1,1,n,x-1,y);
			else
			{
				temp = query_tree(1,1,n,x,y);
				temp.zero++;
			}
			//cout<<temp.zero<<" "<<temp.one<<" "<<temp.two<<endl;
			ll ans ;
			ll zero = temp.zero;
			ll one = temp.one;
			ll two = temp.two;
			//prll(1,1,n);
			ans = (zero*(zero-1)/2 + one*(one-1)/2 + (two)*(two-1)/2);
			//cout<<zero<<" "<<one<<" "<<two<<" ";
			cout<<ans<<endl;
			//cout<<temp.one<<" "<<temp.two<<" "<<temp.zero<<endl;
		}
	}
}

