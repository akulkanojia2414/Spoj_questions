#include<iostream>
using namespace std;
#define FOR(a,b,c) for(int i =a;i<b;i+=c)
#define FORi(a,d,b,e,c,f) for(int i =a,j=d;i<b,j>=e;i+=c,j+=f)
int main(){
	int n;
	cin>>n;
	int a[n];
	int count0=0,count1=0;
	FOR(0,n,1){
		cin>>a[i];
		if(a[i]) count1++;
		else count0++;
	}	
	while(count0) {cout<<"0"; count0--;}
	while(count1) {cout<<"1"; count1--;}
	
	return 0;
}
