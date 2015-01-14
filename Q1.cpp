#include<iostream>
using namespace std;
#define FOR(a,b,c) for(int i =a;i<b;i+=c)
void wiggly(int a[],int n){
	int temp;
	FOR(1,2*n,2){//for(int i =1;i<2*N;i+=2)
		if(a[i]<a[i-1]){
			temp = a[i-1];
			a[i-1] = a[i];
			a[i] = temp;
		}
		else if(a[i]<a[i+1]){
			temp = a[i+1];
			a[i+1] = a[i];
			a[i] = temp;
		} 
	}
}
int main(){
	int n;
	cin>>n;
	int a[2*n];
	FOR(0,2*n,1){//for(int i = 0;i<2*n;i++)
		cin>>a[i];
	}	
	wiggly(a,n);
	FOR(0,2*n,1){
		cout<<a[i]<<endl;
	}
	return 0;
}
