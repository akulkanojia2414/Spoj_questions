
#include<iostream>
#include<cstring>
using namespace std;
#define FOR(a,b,c) for(int i =a;i<b;i+=c)
#define FORi(a,d,b,e,c,f) for(int i =a,j=d;i<b,j>=e;i+=c,j+=f)
int main(){
	char* a,*b;
	a = "DTA STRCURES IT ROKE";
	b = "DATA STRUCTURES IIT ROORKEE";
	int i = 0;
	while(i<strlen(a)){
		//if(strcmp(*a,*b)==0){
			memmove(a+1,b,1);
		//}
		a++,b++;i++;
	}	
	cout<<a;
	return 0;
}
