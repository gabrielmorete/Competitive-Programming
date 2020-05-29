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
const int MAXN = 5e5 + 10;
const ll mod=1e9+7;

int n, v[MAXN], p[MAXN];

int32_t main(){
	fastio;
		
	cin>>n;
	frr(i, n)
		cin>>v[i];
	
	fill(p, p + MAXN, 0);	

	p[0] = p[1] = p[n] = p[n + 1] = 1;
	
	for (int i = 2; i <= n - 1; i++)
		if (v[i - 1] == v[i] or v[i] == v[i + 1])
			p[i] = 1;

	queue<pii> fila;			
	for (int i = 1; i <= n; i++)
		if (p[i] == 1)
			fila.push({0, i});

	int ans = 0;	
	pii x;
	while (!fila.empty()){
		x = fila.front();
		fila.pop();
		
		if (x.fst % 2)
			v[x.snd] = 1 - v[x.snd];
		ans = max(ans, x.fst);

		if (p[x.snd - 1] != 1){
			fila.push({x.fst + 1, x.snd - 1});
			p[x.snd - 1] = 1;
		}
		if (p[x.snd + 1] != 1){
			fila.push({x.fst + 1, x.snd + 1});
			p[x.snd + 1] = 1;
		}
	}

	cout<<ans<<endl;
	frr(i, n)
		cout<<v[i]<<' ';
	gnl;		
}