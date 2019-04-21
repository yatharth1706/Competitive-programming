/*
	problem name: serval and paranthesis
	problem link: https://codeforces.com/problemset/problem/1153/C
	created by: yatharth

*/
#include<bits/stdc++.h>
using namespace std;
#define boost ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("O3")

int main(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	if(n%2==0){
		int occ,ecc;
		occ=ecc=0;
		for(int i=0;i<n;i++){
			if(s[i]=='('){
				occ++;
			}
			else if(s[i]==')'){
				ecc++;
			}
		}
		// calculate how many we can use this more "(" as well as ")".
		occ=n/2-occ;
		ecc=n/2-ecc;
		if(occ<0 || ecc<0){cout<<":("<<'\n'; return 0;}
		for(int i=0;i<n;i++){
			if(s[i]=='?'){
				if(occ!=0){
					s[i]='(';
					occ--;
				}
				else{
					s[i]=')';
				}
			}
		}
	
		
	stack<int> st;
	int res=0;
	for(int i=0;i<n;i++){
		st.push(s[i]);
		if(s[i]==')'){
			st.pop();
			if(!st.empty()){
				st.pop();
			}
		}
		if(st.size()==0){
			res++;
		}
	}
	if(st.size()==0 && res==1){
		cout<<s<<'\n';
	}
	else{
		cout<<":("<<'\n';
	}		
	}
	else{
		cout<<":("<<'\n';
	}
	
	return 0;
}