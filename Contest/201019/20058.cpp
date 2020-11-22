#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=2e5+10;
int n,m,k,q,s[15][maxn];
char a[15][maxn];
char getin(){
	char ch=getchar ();
	while(ch!='.'&&ch!='X') ch=getchar ();
	return ch;
}
int main(){
	freopen("blueshit.in","r",stdin);
	freopen("blueshit.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&k,&q);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) a[i][j]=getin();
	for(int i=1;i<=n;i++){
		int acur=0,from=-1e5-10;
		for(int j=1;j<=m;j++){
			if(j-from>=k&&a[i][j]=='X') acur++,from=j;
			s[i][j]=acur;
		}
	}
	while(q--){
		int x,l,r; scanf("%d%d%d",&x,&l,&r);
		int ans=0;
		for(int i=1;i<=x;i++){
			int from=-1e5-10;
			for(int j=l;j<=r;j++)
				if(j-from>=k&&a[i][j]=='X') ans++,from=j;
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
