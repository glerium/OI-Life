#include <cstdio>
#include <cstring>
using namespace std;
int t,n,m;
char s[107];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%s",&n,&m,s+1);
		for(int i=1,l,r;i<=m;i++){
			scanf("%d%d",&l,&r);
			if(l==r){
				puts("NO");
				continue;
			}else{
				bool f1=false,f2=false;
				for(int i=1;i<l;i++) f1|=(s[i]==s[l]);
				for(int i=r+1;i<=n;i++) f2|=(s[i]==s[r]);
				puts((f1||f2)?"YES":"NO");
			}
//			else if(r-l==1){
//				int c1=s[l],c2=s[r],f1=0,f2=0;
//				for(int i=1;i<=n;i++){
//					if(s[i]==c1){
//						f1=i;break;
//					}
//				}
//				if(!f1){
//					puts("NO");
//					continue;
//				}
//				for(int i=f1+2;i<=n;i++){
//					if(s[i]==c1){
//						f2=i;break;
//					}
//				}
//				if(!f2){
//					puts("NO");
//					continue;
//				}
//				puts("YES");
//				continue;
//			}
//			bool flag=false;
//			for(int j=l+1;j<=r;j++){
//				printf("%d\n",flag);
//				int ct=l;
//				bool flag2=false,found=false,mk=false;
//				for(int k=1;k<=n&&ct<=r;k++){
//					if(ct==j&&!flag2&&!mk){
//						mk=true;
//						continue;
//					}
//					printf(":%d %d %d %d %d\n",j,k,ct,s[k],s[ct]);
//					if(s[ct]==s[k]) ct++,found=true;
//					else if(found) flag2=true;
//				}
//				if(ct==r+1){
//					flag=true;
//					puts("YES");
//					break;
//				}
//			}
//			if(!flag) puts("NO");
		}
	}
	return 0;
}
