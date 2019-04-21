#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,i,count=1,count1=0;
	cin>>n;
	int a[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	
	for(i=0;i<n-1;i++)
	{
		
		while(a[i]<a[i+1] && (i+1)<n)
		{
			
			count++;
			i++;
		}
		cout<<count<<'\n';
			if(count1<count)
			{
				count1=count;
				count=1;
			}
			//count=0;
		
	}
	cout<<count1;
}
