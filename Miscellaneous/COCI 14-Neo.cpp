#pragma GCC optimize ("Ofast")
#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace __gnu_pbds;
using namespace std;
typedef long long int ll;
#define int long long int
#define pb push_back
#define fi first
#define se second
#define deb cerr << "Line no." << __LINE__
#define fr(i, a, b) for(int i = a; i <= b; i++)
#define all(x) x.begin(), x.end()
#define IO ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define sz(x) (int)x.size()
const int mod = 1e9 + 7;
const int mod1 = 998244353;
typedef double f80;
#ifndef LOCAL
#define endl '\n'
#endif

template<typename T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int l, int r){
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}
int pwr(int a,int b){
	int ans = 1;
	while(b){
		if(b & 1) ans = (ans * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	return ans;
}
const int N = 1005;
int a[N][N], b[N][N];
stack<pii> st;
int l[N], r[N];
void solve(){
	int n, m;
	cin >> n >> m;
	fr(i, 1, n){
		fr(j, 1, m)
			cin >> a[i][j];
	}
	fr(i, 1, n - 1){
		fr(j, 1, m - 1){
			if(a[i][j] + a[i + 1][j + 1] <= a[i + 1][j] + a[i][j + 1])
				b[i][j] = 1;
		}
	}
	int ans = 0;
	fr(i, 1, n - 1){
		fr(j, 1, m - 1){
			if(b[i][j]) b[i][j] += b[i - 1][j];
			// cout << b[i][j] << " ";
		}
		// cout << endl;
		while(!st.empty()) st.pop();
		st.push({-1, 0});
		fr(j, 1, m - 1){
			while(st.top().fi >= b[i][j]) st.pop();
			l[j] = st.top().se + 1;
			st.push({b[i][j], j});
		}
		while(!st.empty()) st.pop();
		st.push({-1, m});
		for(int j = m - 1; j >= 1; j--){
			while(st.top().fi >= b[i][j]) st.pop();
			r[j] = st.top().se - 1;
			st.push({b[i][j], j});
			if(b[i][j])
				ans = max(ans, (b[i][j] + 1) * (r[j] - l[j] + 2));
		}
	}
	cout << ans;
}
signed main(){
  	IO;
  	#ifdef LOCAL
		freopen("inp.txt","r", stdin);
		// freopen("out.txt", "w", stdout);
	#endif
	clock_t clk = clock();
  	int t = 1;
  	// cin >> t;
  	fr(tt, 1, t){
    	solve();
  	}
  	cerr << endl << (double)(clock() - clk) / CLOCKS_PER_SEC;
  	return 0;
}
