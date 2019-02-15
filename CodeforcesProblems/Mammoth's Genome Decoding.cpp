/*

Problem link: https://codeforces.com/contest/747/problem/B

Problem Name:Mammoth's Genome Decoding

*/
#include<bits/stdc++.h>
using namespace std;
vector<int> v;
const int maxn=256;
char arr[maxn];
map<char,int> m;
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		m[arr[i]]++;
	}
	
	for(auto x: m){
		if(x.first!='?' && x.second>n/4 || n%4!=0){
			cout<<"==="<<'\n';
			return 0;
		}
	}
	
	for(int i=0;i<n;i++){
		if(arr[i]!='?'){
			cout<<arr[i];
		}
		else{
			if(m['A']<n/4){
				m['A']++;
				cout<<'A';
			}
			else if(m['G']<n/4){
				m['G']++;
				cout<<'G';
			}
			else if(m['C']<n/4){
				m['C']++;
				cout<<'C';
			}
			else if(m['T']<n/4){
				m['T']++;
				cout<<'T';
			}
		}
	}
}
