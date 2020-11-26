#include <bits/stdc++.h>
using namespace std;
int n;
multiset<int> st;
multiset<int,greater<int> > st2;
int main(){
	scanf("%d",&n);
	long long ans=0;
	st.insert(1e9);
	st2.insert(-1e9);
	for(int i=1,x;i<=n;i++){
		scanf("%d",&x);
		if(i==1) ans+=x;
		else ans+=min(abs(*st.lower_bound(x)-x),abs(*st2.lower_bound(x)-x));
		st.insert(x); st2.insert(x);
	}
	printf("%lld\n",ans);
	return 0;
}
