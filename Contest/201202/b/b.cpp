#include <bits/stdc++.h>
using namespace std;
const int maxn=2e6+10;
int t,n,k,f,a[maxn],low;
template<typename T>void read(T &x){
	T v=0,w=1; char ch=getchar ();
	while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar ();}
	while(isdigit(ch))v=v*10+ch-'0',ch=getchar ();
	x=v*w; return;
}
template<typename T>void write(T x){
	if(x<0) putchar ('-'),x=-x;
	if(x>9) write(x/10);
	putchar (x%10+'0');
}
int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	read(t);
	while(t--){
		low=1e8;
		read(n),read(k),read(f);
		for(int i=1;i<=n;i++) read(a[i]),low=min(low,a[i]);
		for(int i=1;i<=low;i++){
			int cnt=0;
			for(int j=1;j<=n;j++)
				if(a[j]/i*i>=max(a[j]-k,1)) cnt++;
			if(cnt>=n-f) write(i),putchar (' ');
		}
		putchar ('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
