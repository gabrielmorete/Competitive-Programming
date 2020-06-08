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
const ll mod = 1e9 + 7;

int n, a[MAXN], b[MAXN];
int pos[MAXN], dstl[MAXN], dstr[MAXN];


int32_t main(){
	fastio;
	cin>>n;
	fr(i, n)
		cin>>a[i];
	fr(i, n) // b é o modelo
		cin>>b[i];

	fr(i, n)
		pos[b[i]] = i;

	// esquerda
	int aux;
	for (int i = 0; i < n; i++){
		aux = pos[a[i]];
		if (aux <= i)
			dstl[i - aux]++;
		else
			dstl[i + (n - aux)]++;
	}		
	// direita
	for (int i = 0; i < n; i++){
		aux = pos[a[i]];
		if (aux >= i)
			dstr[aux - i]++;
		else
			dstr[aux + (n - i)]++;
	}

	int ans = 1;
	fr(i, n + 1)
		ans = max({ans, dstl[i], dstr[i]});

	cout<<ans<<endl;	
}