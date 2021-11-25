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

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m, q;

	cin>>n>>m>>q;

	set<pii> plus;
	fr(i, q){
		int x, y;
		cin>>x>>y;
		plus.insert({x, y});
	}

	int ans = 0;
	vii now = {{1, 1}};

	while (true){
		if (now[0] == make_pair(n, m))
			break;

		ans++;

		vii nxt;
		for (auto e : now){
			int x, y;
			tie(x, y) = e;

			int sum = x + y;
			if (plus.count({x, y})) sum++;

			nxt.pb({min(sum, n), y});
			nxt.pb({x, min(sum, m)});
		}

		sort(all(nxt), greater<pii>()); // decrescente

		now.clear();
		int max_y = 0;

		for (auto e : nxt){
			int x, y;
			tie(x, y) = e;

			if (y <= max_y) // redundante
				continue;

			now.pb({x, y});

			max_y = max(max_y, y);
		}
	}

	cout<<ans<<endl;
}