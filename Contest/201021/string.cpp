#include <iostream>
using namespace std;
const int maxn=107;
int n,m,a[maxn];
string s[maxn];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>s[i];
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
