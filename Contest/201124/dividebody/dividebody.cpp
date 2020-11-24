#include <cstdio>
#include <cctype>
#include <cstring>
using namespace std;
const int maxn=1e6+10;
int n,nxt[maxn];
char s[maxn];
template<typename T>void read(T &x){
	T v=0,w=1; char ch=getchar ();
	while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar ();}
	while(isdigit(ch))v=v*10+ch-'0',ch=getchar ();
	x=v*w;return;
}
int main(){
	freopen("dividebody.in","r",stdin);
	freopen("dividebody.out","w",stdout);
	scanf("%s",s);
	n=strlen(s);
	nxt[1]=0;
	for(int i=1;i<n;i++){
		int j=nxt[i];
		while(s[j]!=s[i]&&j) j=nxt[j];
		if(s[j]==s[i]) nxt[i+1]=j+1;
		else nxt[i+1]=0;
	}
	int ans=0;
	for(int i=n-1;i>=1;i--){
		bool flag=true;
		for(int j=n-1;j>=i;j--){
			if(nxt[j+1]==i+1){
				flag=false;
				break;
			}
		}
		if(flag) ans++;
	}
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
