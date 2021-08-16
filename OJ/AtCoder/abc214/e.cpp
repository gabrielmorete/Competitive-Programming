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

void solve(){
	int n;
	cin>>n;

	vii v;
	int l, r;
	fr(i, n){
		cin>>l>>r;
		v.pb({l, r});
	}

	sort(all(v));

	priority_queue<int, vi, greater<int>> pq;
	int p = 0, at = v[0].fst;

	while (p < n){
		int q = p;
		while (q < n and v[p].fst == v[q].fst){ // coloca todos os iguais
			pq.push(v[q].snd);
			q++;
		}
		p = q;

		int nxt = INF;
		if (p < n)
			nxt = v[p].fst;

		while (at < nxt and pq.size() > 0){ // ta com espaço e tem alguem
			if (at > pq.top()){
				cout<<"No"<<endl;
				return;
			}
			pq.pop();
			at++;
		}

		at = max(at, nxt);
	}

	cout<<"Yes"<<endl;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}