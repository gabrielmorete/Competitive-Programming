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
const int MAXN = 1e6 + 10;

int n, m, nxt[MAXN], maxr[MAXN], atv[MAXN], memo[MAXN];
vector<ll> add[MAXN], rem[MAXN];

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n;
	m = 4 * n;

	fill(nxt, nxt + MAXN, m - 1);

	int minr = m, l, r;
	fr(i, n){
		cin>>l>>r;
		minr =  min(minr, r);
		maxr[l] = max(maxr[l], r); // maior r de segmento ativo
		nxt[l] = min(nxt[l], r); // menor r se segmento não processado
		atv[l]++; // quantos estão ativos no momento
		atv[r + 1]--;
	}

	frr(i, m - 1)
		maxr[i] = max(maxr[i - 1], maxr[i]);

	for (int i = m - 1; i >= 0; i--){
		// cout<<nxt[i + 1]<<' '<<nxt[i]<<endl;
		nxt[i] = min(nxt[i + 1], nxt[i]);
	}

	frr(i, m)
		atv[i] += atv[i - 1];	

	// fr(i, m)
	// 	cout<<maxr[i]<<' ';
	// gnl;		
	// fr(i, m)
	// 	cout<<nxt[i]<<' ';
	// gnl;

	multiset<ll> q;
	
	memset(memo, -1, sizeof memo);

	for (int p = 0; p < m; p++){
		q.insert(all(add[p])); // coloca todos os intervalos que guardam essa posição

		for (auto x : rem[p]) 
			q.erase(q.find(x));

		if (!q.empty())
			memo[p] = *q.begin();
		else if (p <= minr)
			memo[p] = p;

		if (memo[p] != -1){
			l = max(p + 1, maxr[p]);
			r = nxt[p + 1];
			if (l < r){
				add[l + 1].pb(p);
				rem[r + 1].pb(p);
			}
		}
	}

	// fr(i, m)
	// 	dbg(memo[i]);

	if (memo[m - 1] == -1){
		cout<<-1<<endl;
		return 0;
	}

	vi ans;
	int p = m - 1;
	while (memo[p] != p){
		if (atv[p])
			ans.pb(p);
		p = memo[p];
	}
	if (atv[p])
		ans.pb(p);		

	cout<<ans.size()<<endl;
	for (auto x : ans)
		cout<<x<<' ';
	gnl;

}