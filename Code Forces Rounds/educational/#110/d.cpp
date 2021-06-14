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
const int MAXN = 5e5 + 10;

int n, k;
string s;

vi adj[MAXN];
int pai[MAXN], esq[MAXN], dir[MAXN], value[MAXN];

void update(int v){
	if (v <= 1<<(k - 1)){
			value[v] = 1;
			if (s[v - 1] == '?')
				value[v] = 2;
		}
		else{
			value[v] = value[esq[v]] + value[dir[v]];
			if (s[v - 1] == '0')
				value[v] -= value[dir[v]];
			if (s[v - 1] == '1')
				value[v] -= value[esq[v]];
		}
}


int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>k;
	cin>>s;

	n = s.size();

	int nxt = (1<<(k - 1)) + 1;

	queue<int> fila;
	frr(i, 1<<(k - 1))
		fila.push(i);

	while (fila.size() > 1){
		int v = fila.front();
		fila.pop();
		int u = fila.front();
		fila.pop();
	
		pai[v] = pai[u] = nxt;
		esq[nxt] = v;
		dir[nxt] = u;

		fila.push(nxt);
		nxt++;
	}	
	pai[n] = n;

	frr(i, n)
		update(i);
	
	int q, p;
	char c;

	cin>>q;

	while (q--){
		cin>>p>>c;
		s[p - 1] = c;

		update(p);
		do{
			p = pai[p];
			update(p);
		} while (p != pai[p]);

		cout<<value[n]<<endl;
	}
}