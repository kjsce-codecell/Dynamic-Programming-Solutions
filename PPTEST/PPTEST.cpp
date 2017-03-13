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
    /*Main aim of this problem is to score maximum points by solving as many good questions 
      as possible in the given time*/
    scanf("%lld",&t);
    while(t--)
    {
        //Take the no of questions the time limit 
        cin>>n>>w;
        llu c[n],p[n],t[n];
        /*Take the no of test having ith question c[i], no of points for ith qstn p[i] and the time taken 
        ith question t[i]*/
        for(i=0;i<n;i++)
            cin>>c[i]>>p[i]>>t[i];
        /*A 2d array knapsack is declared to keep track of points scored by solving questions in
        w minutes*/
        llu knapsack[n+1][w+1];
        for(i=0;i<=n;i++)
        {
            for(j=0;j<=w;j++)
            {
                /*The 2d array knapsack, keeps track of points scored by solving first i qstns in every 
                  j minutes less than or equal to w.*/
                /*if i=0 or j=0 i.e if there are 0 questions to solve or there is 0 no of minutes, 
                 the points scored is 0. Hence knapsack[i][j]=0*/ 
                if(i==0 || j==0)
                    knapsack[i][j]=0;
                /*There are two possibities of selecting ith qstn. Either you solve it or you dont.
                  You take maximum between, the score obtained by solving the first i questions and the score obtained
                  by not solving the ith qstn. The maximum between theses two is stored in knapsack[i][j].*/
                /*If i>1 you will take the maximum between, the scores you get by solving first i questions 
                  and the scores you get by solving the first (i-1) qstns in j minutes*/
                /*For i>1 if t[i-1] i.e if the time taken for solving ith question is less than or equal to j, means you can solve 
                  this current question under or in j minutes. Hence score obtained by solving this question is
                  c[i]*p[i]. We will subract t[i-1] from j and check how many points can be scored in 
                  (j-t[i-1]) minutes. This is obtained from knapsack[i-1][j-t[i-1]].This way we are checking if the first (i-1)
                  questions can be solved in remaining time (j-t[i-1]) minutes or not.  We add this values to c[i]*p[i].
                  Hence the score obtained by solving the first i questions in j minutes is ((c[i]*p[i])+knapsack[i-1][j-t[i-1]]. 
                  Next we will take maximum between the this score we just calculated and the score obtained by solving first (i-1) questions in j minutes.
                  Which is knapsack[i-1][j]
                  The maximum between these two scores is the maximum scores that can be obtained by solving first i qstns in j minutes.*/
                else if(j>=t[i-1])
                    knapsack[i][j]=M((c[i-1]*p[i-1])+knapsack[i-1][j-t[i-1]],knapsack[i-1][j]);
                /*If the time taken for solving ith question i.e if j<t[i-1] then we will just store points obtained by solving 
                  first (i-1) questions in j minutes.*/
                else 
                    knapsack[i][j]=knapsack[i-1][j];
            }
        }
        //The final answer, i.e the maximum score obtained by solving questions in w minutes is stored in knapsack[n][w].
        cout<<knapsack[n][w]<<endl;
    }
    return 0;
}
