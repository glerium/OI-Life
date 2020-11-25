#include <iostream>
#include <string>
#include <algorithm>
#include <set>
using namespace std;
const int maxn=1e5+10;
int n,m;
string s;
set<string> st;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n>>m>>s;
	if(n<=20&&m<=20){
		char z;
		for(int i=1,op,x,y;i<=m;i++){
			cin>>op;
			if(op==1){
				cin>>x>>z;
				s[x-1]=z;
			}else{
				cin>>x>>y;
				st.clear();
				for(int j=0;j<(1<<(y-x+2));j++){
					string t;
					for(int k=0;k<y-x+1;k++){
						if(j&(1<<k))t+=s[x+k-1];
					}
					if(t=="") continue;
					if(!st.count(t)) cout<<t<<endl;
					st.insert(t);
				}
				cout<<st.size()<<endl;
			}
		}
	}else{
		int op,x,y;
		char z;
		for(int i=1,x;i<=m;i++){
			cin>>op;
			if(op==1){
				cin>>x>>z;
			}else{
				cin>>x>>y;
				cout<<y-x+1<<endl;
			}
		}
	}
	return 0;
}
