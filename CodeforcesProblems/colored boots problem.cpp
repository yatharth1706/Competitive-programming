#include<bits/stdc++.h>
using namespace std;
queue<int> freq1[27],freq2[27];

int main(){
	int n;
	cin>>n;
	string s,t;
	cin>>s;
	cin>>t;
	
	for(int i=0;i<n;i++){
		if(s[i]=='?'){
			freq1[26].push(i+1);
		}
		else{
			freq1[s[i]-'a'].push(i+1);
		}
		
		if(t[i]=='?'){
			freq2[26].push(i+1);
		}
		else{
			freq2[t[i]-'a'].push(i+1);
		}
	}	
	
	vector<pair<int,int>> v;
	for(int i=0;i<26;i++){
		while(freq1[i].size() && freq2[i].size()){
			v.push_back({freq1[i].front(),freq2[i].front()});
			freq1[i].pop();
			freq2[i].pop();
		}
	}
	for(int i=0;i<26;i++){
		while(freq1[i].size() && freq2[26].size()){
			v.push_back({freq1[i].front(),freq2[26].front()});
			freq1[i].pop();
			freq2[26].pop();
		}
		while(freq1[26].size() && freq2[i].size()){
			v.push_back({freq1[26].front(),freq2[i].front()});
			freq1[26].pop();
			freq2[i].pop();
		}
	}
	
	while(freq1[26].size() && freq2[26].size()){
		v.push_back({freq1[26].front(),freq2[26].front()});
		freq1[26].pop();
		freq2[26].pop();
	}
	
	cout<<v.size()<<'\n';
	for(auto x:v){
		cout<<x.first<<" "<<x.second<<'\n';
	}
}
