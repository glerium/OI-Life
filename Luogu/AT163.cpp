#include <bits/stdc++.h>
using namespace std;
const int maxn=107;
int n;
struct Data{
	string ori,f;
	bool operator<(const Data& rhs)const{return f<rhs.f;}
}a[maxn];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].ori,a[i].f=a[i].ori,reverse(a[i].f.begin(),a[i].f.end());
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) cout<<a[i].ori<<endl;
	return 0;
}
