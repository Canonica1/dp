#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>
#include <fstream>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <functional>
#include <numeric> 
#include <cmath> 
#include <time.h>
#include <bitset> 
#include <stack> 
#include <cassert> 
#include <cstring>
#include <chrono> 
using namespace std;
#define ifthen(x,y,z) (x ? y : z)
#define all(a) (a).begin(), (a).end()
#define sz(a) ((long long)(a).size());
#define endl '\n'
#define pb push_back
#define ve vector
#define cont continue
#define vf(a,n)for (ll i = 0; i < (n); i++)cin >> (a)[i];

typedef long long ll;
typedef long double ld;
int n;
int ans = 1e9;
vector<int> w;
int W;
void go(int mask, int k, int x) {
	// k - это кол-во рюкзаков
	// x - сколько места занято в посл. рюкзаке
	// mask - маска
	if (mask == (1 << n) - 1)
	{
		ans = min(ans, k + (x > 0));
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if ((mask & (1 << i)) == 0)
			//не брали ранее
		{
			if (x + w[i] <= W)
			{
				go(mask | (1 << i), k , x + w[i]);
			}
			go(mask | (1 << i), k + 1, w[i]);
		}
	}
}

struct Pair {
	int x, y;

};

int main(){
	cin >> n >> W;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		w.push_back(x);
	}

	vector<pair<int, int>> dp((1 << n), {1e9,1e9});
	dp[0] = { 1,0 };
 	for (int i = 0; i < (1 << n); i++)
	{
		auto k = dp[i].first; auto x = dp[i].second;
		for (int j = 0; j < n; j++)
		{
			if ((i & (1 << j)) == 0)	//не брали ранее
			{
				if (x + w[j] <= W)
				{
					dp[i | (1 << j)] = min(dp[i | (1 << j)], pair<int,int>{k,x + w[j] });
				}
				dp[i | (1 << j)] = min(dp[i | (1 << j)], pair<int, int>{ k + 1, w[j] });
			}
		}
	}
	cout << dp[(1 << n) - 1].first << endl;
}
  
