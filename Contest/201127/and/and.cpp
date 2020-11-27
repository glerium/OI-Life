#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,q,f[maxn][22];
template<typename T>void read(T &x){
	T v=0,w=1; char ch=getchar ();
	while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar ();}
	while(isdigit(ch)){v=v*10+ch-'0';ch=getchar ();}
	x=v*w; return;
}
template<typename T>void write(T x){
	if(x<0) putchar ('-'),x=-x;
	if(x>9) write(x/10);
	putchar (x%10+'0');
}
int main(){
	freopen("and.in","r",stdin); freopen("and.out","w",stdout);
	read(n),read(q); for(int i=1;i<=n;i++) read(f[i][0]);
	int sz=log2(n);
	for(int i=1;i<=sz;i++){
		for(int j=1;j+(1<<i)-1<=n;j++)
			f[j][i]=min(f[j][i-1],f[j+(1<<(i-1))][i-1]);
	}
	for(int i=1,l,r;i<=q;i++){
		read(l),read(r); int qsz=log2(r-l+1);
		write(min(f[l][qsz],f[r-(1<<qsz)+1][qsz])); putchar ('\n');
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
