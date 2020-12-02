#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,m,a[maxn],to[maxn];
struct sjjAKIOI{
	int x,y,z;
}t[maxn];
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
bool check(){
	for(int i=1;i<=n;i++) to[a[i]]=i;
	int ct=0;
	for(int i=1;i<=m;i++){
		if(to[t[i].x]<to[t[i].y]&&to[t[i].y]<to[t[i].z]||to[t[i].z]<to[t[i].y]&&to[t[i].y]<to[t[i].x]) ct++;
	}
	return ct>=(m+1)/2;
}
int main(){
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	read(n),read(m);
	for(int i=1;i<=m;i++) read(t[i].x),read(t[i].y),read(t[i].z);
	for(int i=1;i<=n;i++) a[i]=i;
	do{
		if(check()){
			for(int i=1;i<=n;i++) write(a[i]),putchar (' ');
			putchar ('\n');
			return 0;
		}
	}while(next_permutation(a+1,a+n+1));
	fclose(stdin);
	fclose(stdout);
	return 0;
}
