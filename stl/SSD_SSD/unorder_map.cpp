#include<bits/stdc++.h>
using namespace std;
int main(){
	unordered_map<string,int>ump;
	int n,t;
	cin>>n>>t;
	for (int i = 0; i <n; ++i)
	{
	    string str;
	    cin>>str;
	    ump[str]++;
	}
	while(t--){
		string ss;
		cin>>ss;
	cout<<ss<<" "<<ump[ss]<<endl;
	}


}