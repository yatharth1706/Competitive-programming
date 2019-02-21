/*
	Matrix exponentiation method for calculating nth tribonacci number

*/


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int modd=1e9+7;

void multiply(ll a[3][3],ll b[3][3])
{
    ll mul[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mul[i][j] = 0;
            for (int k = 0; k < 3; k++)
            {
                ll temp=((a[i][k]%modd)*(b[k][j]%modd))%modd;
                mul[i][j] = ((mul[i][j]%modd)+(temp%modd))%modd;
            }
        }
    }
    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
            a[i][j] = mul[i][j]%modd;  
}
ll power(ll F[3][3],ll n)
{
    ll M[3][3] = {{1,1,1}, {1,0,0}, {0,1,0}};
    if (n==1){
        return (F[0][0]%modd + F[0][1]%modd)%modd;
    }
 
    power(F, n/2);
 
    multiply(F, F);
 
    if (n%2 != 0)
        multiply(F, M);
 
    return ((F[0][0]%modd) + (F[0][1]%modd))%modd ;
}
ll findNthTerm(ll n)
{
    ll F[3][3] = {{1,1,1}, {1,0,0}, {0,1,0}} ;
    return power(F, n-2);
}
int main()
{		ll n;
        assert(n>= 1 && n<=1000000000000000000);
        cin>>n;
        cout<<findNthTerm(n+2)<<'\n';
    
}
