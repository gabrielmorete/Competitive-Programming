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
const ll mod=1e9+7;

int n, f[MAXN], deg[MAXN];

int32_t main(){
	fastio;
	cin>>n;
	int x;
	frr(i, n){
		cin>>x;
		f[i] = x;
		deg[x] = 1;
	}

	queue<int> fila;
	frr(i, n)
		if (deg[i] == 0)
			fila.push(i);
	
	int lst = -1;
	frr(i, n){
		if (f[i] == 0){
			int aux = fila.front();
			fila.pop();

			if (aux == i){
				if (lst == -1){
					fila.push(aux);
					aux = fila.front();
					fila.pop();
					f[i] = aux;
				}
				else{
					f[i] = aux;
					swap(f[i], f[lst]);
				}
			}
			else
				f[i] = aux;
			lst = i;
		}
	}
	frr(i, n)
		cout<<f[i]<<' ';
	gnl;		
}