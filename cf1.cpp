#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
ll a[510];
ll b[1010];
bool arr[510];
vector<ll> v;
int main(){
ll n,m;
cin>>n>>m;


for(int i=1; i<=n; ++i){
cin>>a[i];
}
for(int i=1; i<=m; ++i){
cin>>b[i];
}
for(int i=1; i<=m; ++i){
if(!arr[b[i]]){
v.push_back(b[i]);
arr[b[i]] = true;
}
}
ll ans=0;
for(int i=1; i<=m; ++i){
for(int j=0; j<n; ++j){
if(v[j] == b[i]){
v.erase(v.begin()+j);
v.insert(v.begin(), b[i]);
break;
}else{
ans += a[v[j]];
}
}
}
cout<<ans<<endl;
}
