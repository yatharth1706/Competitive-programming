/*

Problem link: https://codeforces.com/contest/988/problem/B
Problem name: Substrings Sort

*/
#include<bits/stdc++.h>
using namespace std;
bool compare(string &s1,string &s2) 
{ 
    return s1.size() < s2.size(); 
}
int main(){
	int n;
	cin>>n;
	string str[n];
	string sp="";
	int maxx=-1;
	for(int i=0;i<n;i++){
		cin>>str[i];
		
	}
	sort(str,str+n,compare);
	bool flag;
	for(int i=0;i<n-1;i++){
		if (str[n-1].find(str[i]) != std::string::npos) {
    		if(str[i+1].find(str[i])<0 || str[i+1].find(str[i])>str[i+1].size()){
    			flag=false;
    			break;
			}
			else{
				flag=true;
			}
		}	
		else{
			flag=false;
			break;
		}
	}
	if(flag){
		cout<<"YES"<<'\n';
		
		for(int i=0;i<n;i++){
			cout<<str[i]<<'\n';
		}
	
	}
	else{
		cout<<"NO"<<'\n';
	}
	
	return 0;
}
