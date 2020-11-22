#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
const int maxn=1e6+10;
char s[maxn];
int n,a[maxn],cnt;
stack<int> st;
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++){
		if(st.empty()) st.push(i);
		else if(s[i]=='['||s[i]=='(') st.push(i);
		else if(s[i]==')'&&s[st.top()]=='(')
			a[++cnt]=st.top(),a[++cnt]=i,st.pop();
		else if(s[i]==']'&&s[st.top()]=='[')
			a[++cnt]=st.top(),a[++cnt]=i,st.pop();
	}
//	for(int i=1;i<=cnt;i++) printf("%d ",a[i]);
	int l=-10,r=-10,al=0,ar=0;
	for(int i=1;i<=cnt;i++){
		if(a[i]==l-1) l=a[i];
		else if(a[i]==r+1) r=a[i];
		else{
			if(r-l>ar-al) ar=r,al=l;
			l=a[i],r=a[i];
		}
	}
	if(r-l>ar-al) ar=r,al=l;
	for(int i=al;i<=ar;i++) putchar(s[i]);
	return 0;
}
