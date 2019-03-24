/*
	Problem name: Painting the fence
	Problem link: https://codeforces.com/contest/1132/problem/C
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
struct intt{
	int l,r;
};
int main(){
	int n,q;
	cin>>n>>q;
	vector<intt> v(q);
	for(int i=0;i<q;i++){
		cin>>v[i].l>>v[i].r;
		v[i].l--;
	}
	// this 2d vector will store painters index painting the particular section index upto only max 2 painters per section
	vector<vector<int>> painters_in(n+1,vector<int>());
	
	for(int i=0;i<q;i++){
		for(int j=v[i].l;j<v[i].r;j++){
			if(painters_in[j].size()<=2){
				painters_in[j].push_back(i);
			}
		}
	}
	// this vector will store the count of section painted by the single painter only
	vector<int> count1(q,0);
	// this 2d vector will store the count of section painted by the pair of painter
	vector<vector<int>> pair_count(q,vector<int>(q,0));
	int totalPainted=0;
	
	for(int i=0;i<n;i++){
		if(!painters_in[i].empty()){
			totalPainted++;
		}
		
		if(painters_in[i].size()==1){
			count1[painters_in[i][0]]++;
		}	
		else if(painters_in[i].size()==2){
			int a=painters_in[i][0];
			int b=painters_in[i][1];
			pair_count[a][b]++;
			pair_count[b][a]++;
		}
	}
	int res=0;
	for(int i=0;i<q;i++){
		for(int j=i+1;j<q;j++){
			res=max(res,totalPainted-count1[i]-count1[j]-pair_count[i][j]);
		}
	}
	
	cout<<res<<'\n';
	return 0;
}
