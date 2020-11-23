#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=1e5+10;
int n,a[maxn];
char str[maxn];
template<typename T>void read(T &x){
	T v=0,w=1; char ch=getchar ();
	while(ch>'9'||ch<'0'){if(ch=='-')w=-1;ch=getchar ();}
	while(ch<='9'&&ch>='0')v=v*10+ch-'0',ch=getchar ();
	x=v*w;return;
}
bool check(){
	for(int i=1;i<=n;i++) if(a[i]>=2) return false;
	return true;
}
int main(){
	freopen("first.in","r",stdin);
	freopen("first.out","w",stdout);
	scanf("%s",str+1);
	n=strlen(str+1);
	for(int i=1;i<=n;i++) a[i]=str[i]-'0';
	while(!check()){
		for(int i=1;i<=n;i++){
			if(a[i]>=2){
				a[i]-=2;
				a[i+1]++;
				a[i-1]++;
			}
		}
	}
	for(int i=1;i<=n;i++) printf("%d",a[i]);
	puts("");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
