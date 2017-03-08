/*
Problem Link: https://www.codechef.com/problems/SUBINC
*/
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
    llu i,j,k,l,t,e,m,n;
    scanf("%lld",&t);
    while(t--)
    {
        cin>>n;
        llu a[n];
        for(i=0;i<n;i++)
            cin>>a[i];
        llu dp[n];
        dp[0]=1;
        for(i=1;i<n;i++)
        {
            if(a[i]>=a[i-1])
                dp[i]=dp[i-1]+1;
            else
                dp[i]=1;
        }
        m=0;
        cout<<accumulate(dp,dp+n,m)<<endl;
    }
    return 0;
}
 
 