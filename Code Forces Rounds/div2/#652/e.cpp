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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
//cout << setprecision(9)<<fixed;

#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 2e5 + 10;

int n, m, chk[MAXN], w[MAXN], wnt[MAXN];
vi eat[MAXN]; 
vii like;

int other(int x, int y){
	if (like[x].fst == y)
		return like[x].snd;
	return like[x].fst;
}

int32_t main(){
	fastio;
	cin>>m>>n;

	int x, y;
	frr(i, m){
		cin>>x;
		w[i] = x;
	}

	like.pb({0, 0});
	frr(i, n){
		cin>>x>>y;
		wnt[x]++, wnt[y]++;
		eat[x].pb(i);
		eat[y].pb(i);
		like.pb({x, y});
	}

	queue<int> fila;
	frr(i, m)
		if (wnt[i] <= w[i])
			fila.push(i);

	vi ans;
	while (!fila.empty()){
		int id = fila.front();
		fila.pop();

		for (int x : eat[id]){
			if (chk[x])
				continue;

			ans.pb(x);
			chk[x] = 1;

			int e = other(x, id);
			if (wnt[e] == w[e] + 1)
				fila.push(e);
			wnt[e]--;
		}	
	}
	
	reverse(all(ans));

	if (ans.size() == n){
		cout<<"ALIVE"<<endl;
		for (int x : ans)
			cout<<x<<' ';
		gnl;
	}
	else
		cout<<"DEAD"<<endl;
}