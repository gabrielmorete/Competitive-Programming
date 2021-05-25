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

int n, m, lim, ans[MAXN];

void solve(){
	cin>>n>>m>>lim;

	vii h;
	fr(i, n){
		int x;
		cin>>x;
		h.pb({x, i});
	}

	sort(all(h));

	priority_queue<pii, vii, greater<pii>> pq;
	fr(i, m){
		pq.push({0, i + 1});
	}


	for (auto x : h){
		pii aux = pq.top();
		pq.pop();

		ans[x.snd] = aux.snd;
		aux.fst += x.fst;
		pq.push(aux);
	}

	cout<<"YES"<<endl;
	fr(i, n){
		cout<<ans[i]<<' ';
	}
	gnl;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}