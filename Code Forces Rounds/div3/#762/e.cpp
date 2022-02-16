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
const int MAXN = 4e5 + 10;

ll n, pre[MAXN], frq[MAXN];

void solve(){
	cin>>n;
	fr(i, n + 1)
		frq[i] = pre[i] = 0;

	fr(i, n){
		int x;
		cin>>x;
		frq[x]++;
	}	


	priority_queue<ll> pq;
	fr(i, frq[0])
		pq.push(0);

	for (int i = 1; i <= n; i++){ // custo de ser escada até o i - 1
		if (pq.empty()){ // se não da até aqui, fudeu
			pre[i - 1] = llINF;
			continue;
		}
		else{ 
			ll x = pq.top();
			pq.pop();

			pre[i - 1] = (i - 1) - x; // custo de levar até lá
			if (i > 1)
				pre[i - 1] += pre[i - 2];

			fr(j, frq[i])
				pq.push(i);
		}
	}

	for (int i = 0; i <= n; i++){
		ll cst = frq[i]; // tem que subir esses;
		if (i > 0)
			cst += pre[i - 1];

		if (cst >= llINF){
			cout<<"-1 ";
		}
		else
			cout<<cst<<' ';
	}
	gnl;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}