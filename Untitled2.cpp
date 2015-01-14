#include<bits/stdc++.h>
#define sd(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define For(n) for(int i=0;i<n;i++)
#define ll long long
#define pii pair<int,int>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define gc() getchar()
#define CLR(x) memset(x,0,sizeof(x));
using namespace std;
pii a[100000],b[100000];
pair<pii,bool> c[200000];
int ans[100];
bool comp(pii x,pii y){
    if(x.F==y.F)
        return x.S<y.S;
    return x.F<y.F;
}
bool comp2(pair<pii,bool> x,pair<pii,bool> y){
    if(x.F.F==y.F.F){
        if(x.S==y.S)
            return x.F.S<y.F.S;
        return x.S;
    }
    return x.F.F<y.F.F;
}
int get()
{
  register char c;
  while(c=gc(),(c<'0'||c>'9')&&(c!='-'));
  bool flag=(c=='-');
  if(flag)
    c=gc();
  int x=0;
  while(c>='0'&&c<='9')
    {
      x=x*10+c-48;
      c=gc();
    }
  return flag?-x:x;
}
void output(int x)
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
void merg(int n){
    int i=0,j=0,cnt=0;
    while(i<n||j<n){
        if(i==n){
            while(j<n){
                c[cnt].F.F=b[j].F;c[cnt].F.S=b[j].S;c[cnt].S=0;
                cnt++;j++;
            }
        }
        if(a[i].F<=b[j].F){
            c[cnt].F.F=a[i].F;c[cnt].F.S=a[i].S;c[cnt].S=1;
            cnt++;i++;
        }
        else{
            c[cnt].F.F=b[j].F;c[cnt].F.S=b[j].S;c[cnt].S=0;
            cnt++;j++;
        }
    }
}
int main(){
    int t,n,tmp,cnt=0;
    ios::sync_with_stdio(false);
    t=get();//cin>>t;
    tmp=t;
    while(t--){
        n=get();//cin>>n;
        For(n){
            a[i].F=get();a[i].S=get();//cin>>a[i].F>>a[i].S;
        }
        sort(a,a+n,comp);
        For(n){
            b[i].F=a[i].S;
            a[i].S=i;b[i].S=i;
        }
        sort(b,b+n,comp);
        merg(n);
        /*For(n){
            c[i].F.F=a[i].F;c[i].F.S=a[i].S;c[i].S=1;
        }
        For(n){
            c[i+n].F.F=b[i].F;c[i+n].F.S=b[i].S;c[i+n].S=0;
        }
        sort(c,c+2*n,comp2);*/
        int bomb=0,last_bomb=-1,lasti=-1;
        for(int i=0;i<2*n;i++){
            //cout<<c[i].val<<" "<<c[i].ind<<" "<<c[i].st<<endl;
            if(c[i].S==false){
                if(c[i].F.S>last_bomb){
                    bomb++;last_bomb=lasti;//cout<<lasti<<" ";
                }
            }
            else{
                lasti=c[i].F.S;
            }
        }output(bomb);
        //ans[cnt]=bomb;cnt++;
    }
    //copy(ans,ans+tmp,ostream_iterator<int>(cout,"\n"));
}
