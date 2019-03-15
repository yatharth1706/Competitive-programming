/*
	problem name: March challenge 2019 "Chef got Recipies"
	problem link: https://www.codechef.com/MARCH19B/problems/JAIN
*/
#include<bits/stdc++.h>
using namespace std;
#define boost ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
typedef long long int ll;


int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		// per array stores the frequency of all the permutations of vowels present in a particular string
		ll per[32]={0};
		for(int i=0;i<n;i++){
			string s;
			cin>>s;
			int mask=0;
			// this block calculates the string containing same permutation of vowels and increase its count in per array
			for(int i=0;i<s.length();i++){
				
				if(s[i]=='a') mask|=1;
				if(s[i]=='e') mask|=2;
				if(s[i]=='i') mask|=4;
				if(s[i]=='o') mask|=8;
				if(s[i]=='u') mask|=16;
			
			}
			per[mask]++;
		}
		// in the last permutation where all vowels are present 
		// total pairs can be per[31]*per[31] but in this (i,i) can also be there so we need to subtract 1
		// like this per[31]*per[31]-1 and then divide by 2 because we need unordered pairs
		
		ll ans=(per[31]*(per[31]-1))/2;
		
		for(int i=0;i<32;i++){
			for(int j=i+1;j<32;j++){
				if((i|j)==31){
					ans+=per[i]*per[j];
				}
			}
		}
		cout<<ans<<'\n';
	}	
	return 0;
}
