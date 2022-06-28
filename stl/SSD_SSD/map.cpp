#include <bits/stdc++.h>
using namespace std;

void print(map<string,int> &mp){
	cout<<mp.size()<<endl;
	for (auto &p:mp)
	{
		cout<<p.first<<" "<<p.second<<endl;
	}
	cout<<endl;
}
int main()
{
	map<string,int>m;
	int n;
	cin>>n;
	for (int i=0;i<n; ++i)
	{
		string s;
		cin>>s;
		m[s]++;
	}
	print(m);
/*
 map<int ,string >mp;
 mp[1]="BUET_CSE";
 mp[3]="CSE_DU";
 mp[2]="SUST_CSE";
 mp.insert({4,"IUT_CSE"});
 mp[5]="KUET_CSE";
 mp.insert({7,"JU_CSE"});
 mp[8]="CUET_CSE";
 mp.insert({6,"BRAC_CSE"});
  mp[10]="RUET_CSE";
  mp[9]="NSU_CSE";
mp[8]="CUET_CSE";

auto it=mp.find(2);
if (it==mp.end()){cout<<"NULL"<<endl;}else{cout<<(*it).first<<" "<<it->second<<endl;}

/*
mp.erase(it);

print(mp);*/

}	
