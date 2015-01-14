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



#define N 1000000007


ll s1(ll n){
    if(n==1)
        return 1;
    if(n==2)
        return 2;
    if(n==3)
        return 3;
    if(n%3==0){
        return (3*(s1(n/3)))%N;
    }
    if(n%3==1){
        return s1(n/3+1)%N;
    }
    if(n%3==2){
        return (2*(s1(n/3+1)))%N;
    }
}
ll s2(ll n){
    if(n==0)
        return 0;
    if(n%3==0){
        return s2(n/3);
    }
    if(n%3==1){
        return s2(n/3)+1;
    }
    if(n%3==2){
        return s2(n/3);
    }
}
ll pw(ll a,ll b){
    if(b==0)
        return 1;
    if(b==1)
        return a%N;
    ll tmp=pw(a,b/2);
    if(b%2)
        return (((a*tmp)%N)*tmp)%N;
    else
        return (tmp*tmp)%N;

}
pair<ll, pair<ll, ll> > EE(ll a, ll b) {
    if(a == 0) return make_pair(b, make_pair(0, 1));
    pair<ll, pair<ll, ll> > p;
    p = EE(b % a, a);
    return make_pair(p.first, make_pair(p.second.second - p.second.first*(b/a), p.second.first));
}

ll modInverse(ll a, ll m) {
    return (EE(a,m).second.first + m) % m;
}

int main(){
    int t;
    ll n;
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>n;
        ll ans;
        ans=(3*s1(n+1))%N;
        ans=(ans-pw(2,s2(n))+N)%N;
        ans=(ans*modInverse(2,N))%N;
        cout<<ans<<endl;
    }
}
