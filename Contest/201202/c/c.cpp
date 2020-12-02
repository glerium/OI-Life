#include <bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
int n,m,q,a[maxn][maxn],cnt;
string s[maxn*maxn];
int main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) a[i][j]=++cnt,cin>>s[cnt];
	for(int i=1,x,y,xx,yy,l,c;i<=q;i++){
		cin>>x>>y>>xx>>yy>>l>>c;
		for(int j=0;j<l;j++){
			for(int k=0;k<c;k++)
				swap(a[x+j][y+k],a[xx+j][yy+k]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			cout<<s[a[i][j]]<<' ';
		cout<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
