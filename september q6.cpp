#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<list>
#include<vector>
#include<cstdlib>
#include<cmath>
#define MP make_pair
#define PB push_back
#define LL long long int
#define LD long double
#define D double
#define pii pair<int,int>
#define V vector
#define sd(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define N 100000
using namespace std;
LL powr(int a,int n, int mod){
    if(n==0)return 1;
    else return a*powr(a,n-1,mod)%mod;
}
LL i4(LL n,LL m){
    LL ans=1,w=n,x=n+1,y=2*n+1,z;
    if(n%5==1){
        z=((n-1)/5+(((3*n+2)/5)%m)*n)%m;
    }
    if(n%5==3){
        z=((2*n-1)/5+(((3*n+1)/5)%m)*n)%m;
    }
    if(n%5==0){
        w/=5;
        z=(3*((n%m)*(n%m))+3*n-1)%m;
    }
    if(n%5==2){
        z=(3*((n%m)*(n%m))+3*n-1)%m;
        y/=5;
    }
    if(n%5==4){
        x/=5;
        z=(3*((n%m)*(n%m))+3*n-1)%m;
    }
    if(n%3==0){
       w/=3;
    }
    if(n%3==1){
        y/=3;
    }
    if(n%3==2){
        x/=3;
    }
    if(n%2){
        x/=2;
    }
    else{
        w/=2;
    }
    return ((((w%m)*(x%m))%m)*((y%m)*(z%m))%m)%m;
}
LL i3(LL n,LL m){
    LL ans=1;
    if(n%2){
        ans=((((n+1)/2)%m)*(n%m))%m;
        ans=((ans)*(ans))%m;
    }
    else{
        ans=(((n/2)%m)*((n+1)%m))%m;
        ans=(ans*ans)%m;
    }
    return ans;
}
int main(){
    LL t,n,m,k,ans;
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        k=1;
        ans=0;
        cin>>n>>m;
        if(n<4){
                LL tmp=0;
        for(int i=1;i<=n;i++){
            tmp=(tmp+i*i*i*i*(n/i));
        }
        tmp%=m;
        cout<<tmp<<endl;
        }
        else{
        while(n/k>n/(k+1)+1){
            LL a,b,diff;
            a=n/(k+1);
            b=n/k;
            diff=n%(n/k);
            ans=(ans+((((i3(b,m)-i3(a,m))%m)*((diff+((k*b)%m)+m)%m))%m)%m);
            ans=(ans-((k%m)*(i4(b,m)-i4(a,m)+m))%m+m)%m;
            k++;
        }
        for(LL i=n/k;i>0;i--){
            ans=(ans+((n%i)*(powr(i,3,m)))%m)%m;
        }
        LL an=((n%m)*(i3(n,m)))%m;
        an=(an-ans+m)%m;
            cout<<an<<endl;
        }
    }
}
