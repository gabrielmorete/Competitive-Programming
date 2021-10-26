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
const int MAXN = 3e5 + 10;

int n, a[MAXN], b[MAXN], dist[MAXN], from[MAXN], hgt[MAXN];
set<int> q;

vi get_ntx(int v){
	int aux = v - a[v];

	vi ans;
	while (q.lower_bound(aux) != q.end() and *q.lower_bound(aux) <= v){
		ans.pb(*q.lower_bound(aux));
		q.erase(q.lower_bound(aux));
	}

	return ans;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n;

	frr(i, n)
		cin>>a[i];
	frr(i, n)
		cin>>b[i];

	fr(i, n)
		q.insert(i);

	memset(dist, -1, sizeof dist);
	
	queue<int> fila;

	fila.push(n);
	dist[n] = 0;

	int v;
	while (!fila.empty()){
		v = fila.front();
		fila.pop();

		vi a = get_ntx(v);

		for (auto x : a){
			if (dist[x + b[x]] == -1){ // não visitei
				hgt[x + b[x]] = x;
				from[x + b[x]] = v;
				dist[x + b[x]] = dist[v] + 1;
				fila.push(x + b[x]);
			}
		}
	}	

	cout<<dist[0]<<endl;

	if (dist[0] != -1){
		v = 0;
		vi ans;
		while (v != n){
			ans.pb(hgt[v]);
			v = from[v];
		}
		reverse(all(ans));
		for (auto x : ans)
			cout<<x<<' ';
		gnl;
	}
}