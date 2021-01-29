#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e6+10;
const int base=233;
const int p=998244353;
int T,n,exi[maxn][28],cnt[maxn],nxt[maxn],pri[maxn],pmcnt;
bool isprime[maxn];
ll t[maxn],f[maxn],hs[maxn],pw[maxn];
char s[maxn],tmp[maxn];
template<typename T>void read(T &x){
	T v=0,w=1; char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}
	while(isdigit(ch)){v=v*10+ch-'0';ch=getchar();}
	x=v*w; return;
}
template<typename T>void write(T x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
void add(int x,int y){
	while(x<=n){
		t[x]+=y;
		x+=x&-x;
	}
}
ll query(int x){
	ll ans=0;
	while(x){
		ans+=t[x];
		x-=x&-x;
	}
	return ans;
}
void getnxt(){
	for(int i=1;i<n;i++){
		int j=nxt[i];
		while(tmp[j]!=tmp[i]&&j) j=nxt[j];
		if(tmp[i]==tmp[j]) nxt[i+1]=j+1;
	}
}
void getprime(){
	memset(isprime,1,sizeof(isprime));
	isprime[1]=false;
	for(int i=1;i<=n;i++){
		if(isprime[i]){
			for(int j=i+i;j<=n;j+=i)
				isprime[j]=false;
			pri[++pmcnt]=i;
		}
	}
}
ll geths(int x,int y){
	return (hs[y]-hs[x-1]*pw[y-x+1]%p+p)%p;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	getprime();
	read(T);
	while(T--){
		memset(f,0,sizeof(f));
		memset(t,0,sizeof(t));
		memset(exi,0,sizeof(exi));
		memset(cnt,0,sizeof(cnt));
		memset(nxt,0,sizeof(nxt));
		scanf("%s",s+1);
		n=strlen(s+1);
		strcpy(tmp,s+1);
		pw[0]=1;
		for(int i=1;i<=n;i++) hs[i]=(hs[i-1]*base+s[i])%p,pw[i]=pw[i-1]*base%p;
		for(int i=1;i<=n;i++){
			for(int j=0;j<26;j++) exi[i][j]=exi[i-1][j];
			exi[i][s[i]-'a']++;
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j<26;j++)
				if(exi[i][j]&1) cnt[i]++;
		}
		getnxt();
		for(int i=3;i<=n;i++){
			add(cnt[i-2]+1,1);
			int imacnt=0;
			for(int j=0;j<26;j++) if((exi[n][j]-exi[i-1][j])&1) imacnt++;
			f[i]=query(imacnt+1);
			for(int j=2;j<=(i-1)/2;j++){
				if((i-1)%j) continue;
				if(cnt[j]>imacnt) continue;
				bool flag=true;
				ll rrr=geths(1,j);
				for(int k=2;k<=(i-1)/j;k++){
					if(rrr!=geths((k-1)*j+1,k*j)){
						flag=false;
						break;
					}
				}
				if(flag) f[i]+=f[j+1];
			}
		}
		ll ans=0;
		for(int i=1;i<=n;i++) ans+=f[i];
		write(ans),putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
};
