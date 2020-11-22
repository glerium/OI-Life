#include <cstdio>
#include <algorithm>
using namespace std;
template<typename T>void read(T& x){
	T v=0,w=1; char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')w=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')v=v*10+ch-'0',ch=getchar();
	x=v*w;return;
}
template<typename T>void write(T x){
	if(x<0) putchar('-'),x=-x;
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}
int n;
class stk{
	static const int maxn=1e6+10;
	int sz,a[maxn];
public:
	void push(int x){
		a[++sz]=x;
		int p=sz;
		while(p>1){
			if(a[p/2]>a[p]) swap(a[p/2],a[p]);
			else break;
			p/=2;
		}
	}
	void pop(){
		swap(a[1],a[sz]);
		sz--;
		int p=1,t;
		while(p*2<=sz){
			t=p;
			if(a[p*2]<a[p]) t=p*2;
			if(p*2+1<=sz&&a[p*2+1]<a[t]) t=p*2+1;
			if(p!=t) swap(a[p],a[t]);
			else break;
			p=t;
		}
	}
	int top(){
		return a[1];
	}
}s;
int main(){
	read(n);
	for(int i=1,op,x;i<=n;i++){
		read(op);
		switch(op){
			case 1:{
				read(x);
				s.push(x);
				break;
			}
			case 2:{
				write(s.top());
				putchar('\n');
				break;
			}
			case 3:{
				s.pop();
				break;
			}
		}
	}
	return 0;
}
