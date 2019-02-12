/*
Problem link: https://codeforces.com/contest/1114/problem/C
for tutorial link: https://www.quora.com/How-do-I-find-the-number-of-trailing-zeroes-of-N-factorial-in-Base-B


*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(0)

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)

typedef long long ll;
typedef double ld;
typedef pair<ll, ll> pii;

const int N = 1e6 + 5;
const ll INF = 5e18;


ll multiply(ll a, ll b) {
	if(a <= INF/b) {
		return a * b;
	}
	else return INF;
}
// calculates prime factors along with their frequencies
vector<pii> pf(ll n) {
	vector<pii> v;
	for(ll i=2; i*i<=n; i++) {
		if(n % i) continue;
		int c = 0;
		while(n % i == 0) {
			c++;
			n /= i;
		}
		v.pb(mp(i, c));
	}
	if(n > 1) {
		v.pb(mp(n, 1));
	}
	return v;
}

int F[N];

int main() {

	boost;
	ll n, b; cin>>n>>b;
	vector<pii> primes = pf(b);

	ll ans = INF;
	// finding the minimum of the maximum value of power of each prime factor
	for(int i=0; i<(int)primes.size(); i++) {
		ll p = primes[i].fi, c = primes[i].se;
		ll cnt = 0;
		ll val = p;
		while(val <= n) {
			cnt += n/val;
			val = multiply(val, p);
		}
		ans = min(ans, cnt/c);
	}

	cout<<ans<<'\n';
	
	return 0;
}
