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
        //DP involves reducing time complexity at the cost of memory space
        /*Therefore an array is declared, which stores the length of subarrays 
          including the ith element, i.e dp[i] is the length of the subarray 
          which has a[i] in it*/
        llu dp[n]; //Create an array to store the lengths of increasing subarrays
        dp[0]=1;   //The first element is a singleton set, the length of which is always 1
        //Traverse through the entire array
        for(i=1;i<n;i++)
        {
            /*check if the current element is greater than or equal to the previous element. If it is,
              means there is another subarray formed, which includes this element as well as the elements before the ith element,
              satisfying this condition. So the length of the subarray having ith element is length of subarray having (i-1)th
              element + 1 i.e dp[i]=dp[i-1]+1*/
            /*If a[i] is not greater than or equal to a[i-1] then the length of the subarray which has this element is just 1
              i.e dp[i]=1*/
            if(a[i]>=a[i-1])
                dp[i]=dp[i-1]+1;
            else
                dp[i]=1;
        }
        /* for the first test case the array dp is:
        A:  1 4 2 3
        dp: 1 2 1 2 
        */
        m=0;
        /*By storing the length of the subarrays containing the ith element, you are keeping track of all the singleton sets as well as
        other sets containing ith element*/
        //Take the sum of all elements of array dp, to get the length of all the increasing subarrays in the given array
        cout<<accumulate(dp,dp+n,m)<<endl;
    }
    return 0;
}
 
 
