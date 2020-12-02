#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
const int maxm=105;
int t,n,a[maxn],s[maxm][maxn],sc,head[maxm][maxm],stot[maxn];
vector<int> nxt[maxm][maxm];
template<typename T>void read(T &x){
	T v=0,w=1; char ch=getchar ();
	while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar ();}
	while(isdigit(ch))v=v*10+ch-'0',ch=getchar ();
	x=v*w; return;
}
int main(){
	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	read(t),read(n);
	for(int i=1;i<=n;i++) read(a[i]),stot[i]=stot[i-1]+a[i];
	for(int i=1;i<=100;i++) for(int j=1;j<=n;j++){
		s[i][j]=(s[i][j-1]+a[j])%i;
		nxt[i][s[i][j]].push_back(j);
	}
	for(int i=1,l,r,k,w;i<=t;i++){
		read(l),read(r),read(k),read(w);
		if(l==1){
			if(!nxt[k][0].empty()&&nxt[k][0][0]<=r){
				sc+=w;
				puts("y");
				continue;
			}
		}
		l--;
		bool flag=false;
		for(int j=1;j<k;j++){
			if(nxt[k][j].empty()) continue;
			int sz=nxt[k][j].size()-1;
			int tl=0,tr=sz,mid,ans=-1;
			while(tl<=tr){
				mid=tl+tr>>1;
				if(nxt[k][j][mid]>=l) ans=mid,tr=mid-1;
				else tl=mid+1;
			}
			if(ans==-1) continue;
			if(ans+1<=sz&&nxt[k][j][ans+1]<=r){
				flag=true;
				puts("y");
				break;
			}
		}
		sc+=w*(flag?1:-1);
		puts(flag?"y":"n");
	}
	int kkk; read(kkk);
	printf("%d\n",sc+kkk);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
