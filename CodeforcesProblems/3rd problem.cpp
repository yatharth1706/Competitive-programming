#include<bits/stdc++.h>
using namespace std;

int segments[10]={6,2,5,5,4,5,6,3,7,6};

int main(){
	int t,n;
	cin>>t;
	int minn;
	int maxx;
	while(t--){
		cin>>n;
		int x,y;
		maxx=-1;
		minn=10;
		int countt=0;
		bool flag=true;
		while(n--){
			cin>>x>>y;
			int dead=segments[x]-y;
			if(dead<0){
				flag=false;
			}
			else{
				countt+=dead;
				minn=min(minn,dead);
				maxx=max(maxx,countt);
				
			}
			
		}
		if(flag){
			cout<<minn<<" "<<maxx<<'\n';
		}
		else{
			cout<<"invalid"<<'\n';
		}
	}	
	return 0;
}
