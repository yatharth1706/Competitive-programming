/*
	problem link: https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/lets-begin/description/
	problem name: Lets begin
*/
#include<bits/stdc++.h>
using namespace std;

#define MAXN 1000000
#define INF 1e9

int dp[MAXN+5];
int primes[] = {2, 3, 5, 7};
int l = 4;

void solve(){
    for(int i=0;i<=MAXN;i++)
        dp[i]=INF;
    // for these numbers minimum is 1 (kind of like base cases for our dp solution)
	dp[2] = 1; 
    dp[3] = 1;
    dp[5] = 1;
    dp[7] = 1;
    
    // calculating values of minimum number required to be summed to a particular number for i=1 to maxn
    for(int i=1;i<=MAXN;i++){
        for(int j=0; j<l;j++){
            if(i-primes[j]>=0)
                dp[i] = min(dp[i], dp[i-primes[j]] + 1);
        }
    }
    for(int i=0;i<=MAXN;i++)
        if(dp[i]>=INF)
            dp[i] = -1;
    return;
}
int main(){
    solve();

    int N, T;
    cin>>T;
    while(T--){
        cin>>N;
        cout<<dp[N]<<'\n';
    }
    return 0;
}
