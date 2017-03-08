
/*
Problem Link: https://www.codechef.com/problems/ROBOWALL 

*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
 
#define ll long long
#define pb push_back
#define mp make_pair
 
using namespace std;
 
int main(int argc, char* argv[]) {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, a, m;
		scanf("%d", &n);
		vector <ll> v;
		vector <ll> dp;
		for(int i=0; i<n; i++) {
			scanf("%d", &a);
			v.pb(a);
			dp.pb(a);
		}
		scanf("%d", &m);
		vector <int> jmps;
		for(int i=0; i<m; i++) {
			scanf("%d", &a);
			jmps.pb(a);
		}
		for(int i=n-1; i>=0; i--) {
			for(int j=0; j<m; j++) {
				if(i+jmps[j]<n) {
					dp[i]=max(dp[i], v[i]+ dp[i+jmps[j]]);
				}
			}
		}
		printf("%lld\n", dp[0]);
	}
	return 0;
}