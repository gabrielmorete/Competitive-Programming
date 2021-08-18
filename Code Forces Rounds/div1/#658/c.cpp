#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1; i <= n; i++)

#define endl '\n'
#define gnl cout << endl
#define chapa cout << "oi meu chapa" << endl

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(), x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e5 + 10;

int n, x, y, out, a[MAXN], freq[MAXN], ans[MAXN];
vi pos[MAXN];


void solve(){
	cin>>n>>x>>y;

	frr(i, n + 1){
		pos[i].clear();
		freq[i] = ans[i] = 0;
	}

	frr(i, n){
		cin>>a[i];
		pos[a[i]].pb(i);
		freq[a[i]]++;
	}

	frr(i, n + 1) 
		if (freq[i] == 0) 
			out = i;

	priority_queue<pii> pq;

	frr(i, n + 1)
		pq.push({freq[i], i});

	fr(i, x){
		int c, f;
		tie(f, c) = pq.top();
		pq.pop();

		ans[pos[c].back()] = c;
		pos[c].pop_back();
		freq[c]--;

		pq.push({freq[c], c});
	}

	int f = pq.top().fst;

	if (2*f > 2*n - x - y){
		cout<<"NO"<<endl;
		return;
	}

	vii all, all2;
	frr(i, n + 1)
		while (!pos[i].empty()){
			all.pb({i, pos[i].back()});
			all2.pb({i, pos[i].back()});
			pos[i].pop_back();
		}

	int ms = n - y;	
	int p = 0;	


	// we most use spare positions to force mismatches
	for (int i = (n - x)/2; i < all.size(); i++){
		all2[p++].snd = all[i].snd;
		if (a[all2[p - 1].snd] == all2[p - 1].fst){
			assert(ms > 0);
			all2[p - 1].fst = out;
			ms--;
		}
	}
	for (int i = 0; i < (n - x)/2; i++){
		all2[p++].snd = all[i].snd;
		if (a[all2[p - 1].snd] == all2[p - 1].fst){
			assert(ms > 0);
			all2[p - 1].fst = out;
			ms--;
		}
	}

	fr(i, all.size())
		if (ms > 0 and all2[i].fst != out){
			all2[i].fst = out;
			ms--;
		}

	for (auto e : all2)
		ans[e.snd] = e.fst;

	cout<<"YES"<<endl;
	frr(i, n)
		cout<<ans[i]<<' ';
	gnl;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}