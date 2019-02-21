#include<bits/stdc++.h> 
using namespace std; 
  
// A utility function to multiply two matrices 
// a[][] and b[][].  Multiplication result is 
// stored back in b[][] 
void multiply(int a[3][3], int b[3][3]) 
{ 
    int mul[3][3]; 
    for (int i = 0; i < 3; i++) 
    { 
        for (int j = 0; j < 3; j++) 
        { 
            mul[i][j] = 0; 
            for (int k = 0; k < 3; k++) 
                mul[i][j] += a[i][k]*b[k][j]; 
        } 
    } 
  
    for (int i=0; i<3; i++) 
        for (int j=0; j<3; j++) 
            a[i][j] = mul[i][j];   
} 
  
// Function to compute F raise to power n-2. 
int power(int F[3][3], int n) 
{ 
    int M[3][3] = {{1,1,1}, {1,0,0}, {0,1,0}}; 
  
    if (n==1) 
        return F[0][0] + F[0][1]; 
  
    power(F, n/2); 
  
    multiply(F, F); 
  
    if (n%2 != 0) 
        multiply(F, M); 
  
    return F[0][0] + F[0][1] ; 
} 
  
int findNthTerm(int n) 
{ 
    int F[3][3] = {{1,1,1}, {1,0,0}, {0,1,0}} ; 
  
    return power(F, n-2); 
} 
  
int main() 
{ 
   int n = 5; 
  
   cout << "F(5) is " << findNthTerm(n); 
  
   return 0; 
}
