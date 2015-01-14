#include<iostream>
#include<cstring>
using namespace std;
void insert(char *a,char c, int p){
	int l=strlen(a);
	for(int i=l-1;i>=p;i--){
		a[i+1]=a[i];
	}
	a[p]=c;
}
int main(){
	char c1[30]="DTA STRCURES IT ROKE";
	char c2[30]="DATA STRUCTURES IIT ROORKEE";
	for(int i=0;i<strlen(c1)-1;i++){
		if(c1[i]!=c2[i]){
			insert(c1,c2[i],i);
			i--;
		}
	}
	insert(c1,'E',strlen(c1)-1);
	cout<<c1;
	return 0;
}
