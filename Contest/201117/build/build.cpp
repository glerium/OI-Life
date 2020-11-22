#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;
const int maxn=1e5+10,maxm=5e5+10;
int n,m,q,cnt,fa[maxn],neg_start;
int pos_cnt=0;
int ans[maxn];
struct Edge{
	int x,y;
	bool suki;
	bool operator<(const Edge& rhs)const{return suki>rhs.suki;}
}a[maxm];
template<typename T>void read(T &x){
	T v=0,w=1; char ch=getchar ();
	while(ch>'9'||ch<'0'){if(ch=='-')w=-1;ch=getchar ();}
	while(ch<='9'&&ch>='0')v=v*10+ch-'0',ch=getchar ();
	x=v*w;return;
}
void add(int x,int y,bool c){
	a[++cnt]=(Edge){x,y,c};
}
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void merge(int x,int y){
	fa[find(x)]=find(y);
//	printf("%d %d\n",x,y);
}
bool check(int x){
	if(ans[x]!=-1) return ans[x];
	for(int j=1;j<=n;j++) fa[j]=j;
	if(x>pos_cnt) return ans[x]=false;
	int ct=0,j=1;
	for(j=1;j<neg_start;j++){
		if(find(a[j].x)!=find(a[j].y)){
			merge(a[j].x,a[j].y);
			ct++;
			if(ct==x) break;
		}
	}
	if(ct!=x) return ans[x]=false;
	for(j=neg_start;j<=cnt;j++){
		if(find(a[j].x)!=find(a[j].y)){
			merge(a[j].x,a[j].y);
			ct++;
			if(ct==n-1) break;
		}
	}
	return ans[x]=(ct==n-1);
}
int myrand(){
	int pos=rand(),group=rand()%4;
	return pos+RAND_MAX*(group);
}
int main(){
	freopen("build.in","r",stdin);
	freopen("build.out","w",stdout);
	read(n),read(m),read(q);
	for(int i=1,x,y,c;i<=m;i++){
		read(x),read(y),read(c);
		if(c) pos_cnt++;
		add(x,y,c),add(y,x,c);
	}
	sort(a+1,a+1+cnt);
	for(int i=1;i<=cnt;i++){
		if(!a[i].suki){
			neg_start=i;
			break;
		}
	}
	if(n<=2000){
		for(int i=1,x;i<=q;i++){
			for(int j=1;j<=n;j++) fa[j]=j;
			read(x);
			if(x>pos_cnt){
				puts("No");
				continue;
			}
			int ct=0,j=1;
			for(j=1;j<neg_start;j++){
				if(find(a[j].x)!=find(a[j].y)){
					merge(a[j].x,a[j].y);
					ct++;
					if(ct==x) break;
				}
			}
			if(ct!=x){
				puts("No");
				continue;
			}
			for(j=neg_start;j<=cnt;j++){
				if(find(a[j].x)!=find(a[j].y)){
					merge(a[j].x,a[j].y);
					ct++;
					if(ct==n-1) break;
				}
			}
			puts(ct==n-1?"Yes":"No");
		}
	}else{
		memset(ans,-1,sizeof(ans));
		srand(time(0));
		int first;
		while(1){
			first=myrand()%pos_cnt+1;
//			printf("%d\n",first);
			if(check(first)) break;
		}
		int l1=1,r1=first,mid1,ans1;
		while(l1<=r1){
			mid1=l1+r1>>1;
			if(check(mid1)){
				ans1=mid1;
				r1=mid1-1;
			}else l1=mid1+1;
		}
		int l2=first,r2=pos_cnt,mid2,ans2;
		while(l2<=r2){
			mid2=l2+r2>>1;
			if(check(mid2)){
				ans2=mid2;
				l2=mid2+1;
			}else r2=mid2-1;
		}
		for(int i=1,x;i<=q;i++){
			read(x);
			if(ans1<=x&&x<=ans2) puts("Yes");
			else puts("No");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
