#include<bits/stdc++.h>
using namespace std;
#define boost ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef long long int ll;
int main(){
	boost;
	int n;
	cin>>n;
	vector<pair<int,int>> Chapters(n);
	
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		Chapters.push_back({x,y});
	}
	int k;
	cin>>k;
	k--;
	int i,index;
	index=0;
	for(int i=0;i<n;i++){
		cout<<Chapters[i].first<<" "<<Chapters[i].second<<"\n";
	}
	
	for(i=0;i<n;i++){
		if(k<=Chapters[i].second){
			index=i;
			break;
		}
		else if(k>Chapters[i].second){
			continue;
		}
	}
	cout<<"--- "<<index<<'\n';
	int RemainingChapters=n-(index);
	cout<<RemainingChapters<<'\n';
	return 0;
}
