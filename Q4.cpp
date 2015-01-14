#include<iostream>
using namespace std;
#define FOR(a,b,c) for(int i =a;i<b;i+=c)
#define FORi(a,d,b,e,c,f) for(int i =a,j=d;i<b,j>=e;i+=c,j+=f)
int main(){
	int n;
	cin>>n;
	int a[n];
	FOR(0,n,1){
		cin>>a[i];
	}
	FOR(0,n/2,1){
		a[i] += a[n-i-1];
		a[n-i-1] = a[i] - a[n-1-i];
		a[i] -= a[n-i-1];
	}
	FOR(0,n,1) cout<<a[i]<<" ";
	return 0;
}
