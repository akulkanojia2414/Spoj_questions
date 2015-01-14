#include<iostream>
#include<cmath>
using namespace std;
unsigned long long powr(int a,int b)
{
    if(b==0 ) return 1;
    unsigned long long temp = powr(a,b/2)%1000000007;
    if(b%2==0) return ((temp%1000000007)*(temp%1000000007))%1000000007;
    else return ((temp%1000000007)*(temp%1000000007)*a)%1000000007;
}
unsigned long long fac[2001];
int main()
{
    fac[0]=1;
    for(int i =1;i<=2000;i++){
        fac[i] = (fac[i-1]*i)%1000000007;
    }
    int t,n;
    cin>>t;
    //cout<<powr(2,t);
    while(t--)
    {
        cin>>n;
        cout<<(fac[2*n]/powr(2,n))%1000000007<<endl;
    }
}
