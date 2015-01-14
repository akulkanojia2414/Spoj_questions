#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
#define FOR(a,b,c) for(int i =a;i<b;i+=c)
#define FORi(a,d,b,e,c,f) for(int i =a,j=d;i<b,j>=e;i+=c,j+=f)
int count5(int n){
	int sum = 0;
	int nod = log10(n);
	int b = (int)(n/pow(10,nod))%10;
	while(nod>=0){
		if(b<=5){
			sum += b*pow(9,nod);
			if(b==5) sum--;
		}
		else{
			sum += (b-1)*pow(9,nod);
		}
		nod--;
		b = (int)(n/pow(10,nod))%10;
	
	}
	return sum;
}
bool check(int a){
	int temp = a%10;
	bool flag = true;
	while(a){
		if(temp!=5){
			a /= 10;
			temp = a%10;
		}
		else {
			flag = false;
			break;
		}
	}
	return flag;
}

int main(){
	int n;
	cin>>n;
	int* arr = new int[count5(n)];
	FOR(1,n+1,1){
		if(check(i)) cout<<i<<endl;
	}
	
	
	
	return 0;
}
