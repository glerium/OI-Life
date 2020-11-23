#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int a[5]={1,3,5,7,9};
vector<int> vec;
map<int,int> mp;
pair<int,int> pi;
int main(){
	cout<<binary_search(a,a+5,3)<<endl;
	cout<<binary_search(a,a+5,4)<<endl;
	
}
