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
const int MAXN = 1e5 + 10;

ll n, m, k, v[MAXN], up1[MAXN], up2[MAXN];
ll opa[MAXN], opb[MAXN], opc[MAXN];

int32_t main(){
	fastio;
	cin>>n>>m>>k;

	frr(i, n)
		cin>>v[i];
	frr(i, m){
		cin>>opa[i];
		cin>>opb[i];
		cin>>opc[i];
	}
	int a, b;
	fr(i, k){
		cin>>a>>b;
		up1[a]++;
		up1[b + 1]--;
	}

	ll aux = 0;
	frr(i, m){
		aux += up1[i];
		up2[opa[i]] += opc[i] * aux;
		up2[opb[i] + 1] -= opc[i] * aux;
	}
	aux = 0;
	frr(i, n){
		aux += up2[i];
		cout<<v[i] + aux<<' ';
	}
	gnl;

}