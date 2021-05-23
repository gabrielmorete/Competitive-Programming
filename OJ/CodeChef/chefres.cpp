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

int n, m, ans[MAXN];
void solve(){
	cin>>n>>m;

	vii event;

	int l, r;
	fr(i, n){
		cin>>l>>r;
		event.pb({l, 1});
		event.pb({r, 0});
	}

	fr(i, m){
		cin>>l;
		event.pb({l, i + 2});
	}

	sort(all(event));

	bool open = 0;
	stack<pii> stk;
	for (auto x : event){
		if (x.snd == 0)
			open = 0;
		else if (x.snd >= 2){
			int id = x.snd - 2;
			if (open)
				ans[id] = 0;
			else
				stk.push({id, x.fst});
		}
		else{
			open = 1;
			while (!stk.empty()){
				int u, t;
				tie(u, t) = stk.top();
				stk.pop();
				ans[u] = x.fst - t;
			}
		}
	}	
	
	while (!stk.empty()){
			int u;
			tie(u, ignore) = stk.top();
			stk.pop();
			ans[u] = -1;
		}

	fr(i, m)
		cout<<ans[i]<<endl;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}