#include <iostream>
#include <string>
#include <map>
using namespace std;
int n,cnt;
map<string,int> mp;
string q[1000001];
int f,r;
struct Rule{
	string from,to;
}a[101];
int main(){
	string ori;
	cin>>ori>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].from>>a[i].to;
	q[r++]=ori;
	cnt++;
	mp.insert(pair<string,int>(ori,1));
	while(f<r){
		for(int i=1;i<=n;i++){
			size_t ind=-1;
			while((ind=q[f].find(a[i].from,ind+1))!=string::npos){
				string ins=q[f];
				ins.erase(ind,a[i].from.length());
				ins.insert(ind,a[i].to);
				if(mp.count(ins))continue;
				cnt++;
				q[r++]=ins;
				mp.insert(pair<string,int>(ins,1));
			}
		}
		f++;
	}
	cout<<cnt<<endl;
	return 0;
}
