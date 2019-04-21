#include<bits/stdc++.h>
using namespace std;
vector<int> increasing;
vector<int> decreasing;
const int maxn=10e6;

int main(){
	int n;
	cin>>n;
	vector<pair<int,bool>> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i].first;
		arr[i].second=false;
	}
	sort(arr.begin(),arr.end());
	
	increasing.push_back(arr[0].first);
	int max_so_far=arr[0].first;
	arr[0].second=true;
	for(int i=1;i<n;i++){
		if(!arr[i].second){
			if(arr[i].first>max_so_far){
				max_so_far=arr[i].first;
				increasing.push_back(arr[i].first);
				arr[i].second=true;
			}
		}
	}
	sort(arr.rbegin(),arr.rend());
	int min_so_far;
	for(int i=0;i<n;i++){
		if(arr[i].second==false){
			min_so_far=arr[i].first;
			arr[i].second=true;
			decreasing.push_back(arr[i].first);
			break;
		}
	}
	for(int i=1;i<n;i++){
		if(arr[i].second==false){
			if(arr[i].first<min_so_far){
				min_so_far=arr[i].first;
				decreasing.push_back(arr[i].first);
				arr[i].second=true;
			}
		}
	}
	if(increasing.size()+decreasing.size()==n){
		cout<<"YES"<<'\n';
		cout<<increasing.size()<<'\n';
		for(int i=0;i<increasing.size();i++){
			cout<<increasing[i]<<" ";
		}
		cout<<'\n';
		cout<<decreasing.size()<<'\n';
		for(int i=0;i<decreasing.size();i++){
			cout<<decreasing[i]<<" ";
		}
		cout<<'\n';	
	}
	else{
		cout<<"NO"<<'\n';
	}
	
}
