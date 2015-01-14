#include<iostream
using namespace std;
#define FOR(a,b,c) for(int i =a;i<b;i+=c)
#define FORi(a,d,b,e,c,f) for(int i =a,j=d;i<b,j>=e;i+=c,j+=f)
bool check (int a[],int n,int k ){
	int i=0,j=n-1,temp;
	while(i<j){
		temp = a[i]+a[j];
		if(temp==k) return true;
		else if(temp>k){
			j--;
		}
		else{
			i++;
		}
		
	}
	return false;
}
int main(){
	int n,k;
	cin>>n>>k;
	int a[n];
	FOR(0,n,1){
		cin>>a[i];
	}	
	if(check(a,n,k)) cout<<"True";
	else cout<<"False";
	
	return 0;
}
