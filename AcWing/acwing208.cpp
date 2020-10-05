#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=35;
int t,n,from,to,a[maxn];
int main(){
	scanf("%d",&t);
	while(t--){
		memset(a,0,sizeof(a));
		scanf("%d",&n);
		{
			int x,y;
			for(int i=1;i<=n;i++) scanf("%d",&x),a[i]=x;
			for(int i=1;i<=n;i++) scanf("%d",&x),a[i]^=x;
			while(~scanf("%d%d",&x,&y)&&x&&y) a[y]|=1<<x;
			for(int i=1;i<=n;i++) a[i]|=1<<i;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++)
				if(a[j]>a[i]) swap(a[i],a[j]);
			if(a[i]==1){
				printf("Oh,it's impossible~!!\n");
				goto end;
			}
			if(!a[i]){
				printf("%d\n",1<<n-i+1);
				goto end;
			}
			for(int j=n;j;j--){
				if(a[i]>>j){
					for(int k=1;k<=n;k++)
						if(i!=k&&(a[k]>>j)) a[k]^=a[i];
					break;
				}
			}
		}
		puts("1");
end:;
	}
	return 0;
}
