#include<bits/stdc++.h>
using namespace std;
void _print(unordered_set<string>&st){
	for (string x : st)
	{
		cout<<x<<endl;
	}
}
int main(int argc, char const *argv[])
{
	//set<string>st;
	//multiset<string>st;
	unordered_set<string>st;
	st.insert("bme");
	st.insert("eee");
	st.insert("me");
	st.insert("ipe");
	st.insert("cse");
    st.insert("ce");

	/*auto it=st.find("ce");
	if(it!=st.end()){cout<<(*it)<<endl;st.erase(it);// erase only the first element}*/
	//st.erase("cse"); //erase all element euqal to cse
	_print(st);
	return 0;
}