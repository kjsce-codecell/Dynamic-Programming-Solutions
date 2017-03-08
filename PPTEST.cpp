#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<utility>
/*
Problem Link: https://www.codechef.com/problems/PPTEST
*/
#include<queue>
#include<numeric>
#include<ctime>
#define llu long long
#define N 100000
#define m(a,b) (a>b? b : a)
#define M(a,b) (a>b? a : b)
#define mod 1000000007
using namespace std;
 
int main()
{
    llu i,j,k,l,t,e,m,n,w;
    scanf("%lld",&t);
    while(t--)
    {
        cin>>n>>w;
        llu c[n],p[n],t[n];
        for(i=0;i<n;i++)
            cin>>c[i]>>p[i]>>t[i];
        llu knapsack[n+1][w+1];
        for(i=0;i<=n;i++)
        {
            for(j=0;j<=w;j++)
            {
                if(i==0 || j==0)
                    knapsack[i][j]=0;
                else if(j>=t[i-1])
                    knapsack[i][j]=M((c[i-1]*p[i-1])+knapsack[i-1][j-t[i-1]],knapsack[i-1][j]);
                else 
                    knapsack[i][j]=knapsack[i-1][j];
            }
        }
        cout<<knapsack[n][w]<<endl;
    }
    return 0;
}