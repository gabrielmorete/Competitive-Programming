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

ll n, a[MAXN], avg, med;
ll in[MAXN], out[MAXN], v[MAXN];

ll pd(){
	in[0] = out[0] = 0;

	frr(i, n){
		in[i] = max(in[i - 1], out[i - 1]) + v[i];
		out[i] = in[i - 1];
	}

	return max(out[n], in[n]);
}

bool test_avg(ll val){
	frr(i, n)
		v[i] = a[i] - val;

	return pd() >= 0;
}

bool test_med(ll val){
	frr(i, n){
		if (a[i] >= val)
			v[i] = 1;
		else
			v[i] = -1;
	}

	return pd() > 0;
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin>>n;

	frr(i, n){
		cin>>a[i];
		a[i] *= 1000;
	}

	avg = -INF;
	med = -INF;

	ll ini = 1, fim = 1e14;

	while (ini <= fim){
		ll meio = (ini + fim)/2;

		if (test_avg(meio)){
			avg = meio;
			ini = meio + 1;
		}
		else
			fim = meio - 1;
	}

	frr(i, n)
		a[i] /= 1000;

	ini = 1, fim = 1e14;
	while (ini <= fim){
		ll meio = (ini + fim)/2;

		if (test_med(meio)){
			med = meio;
			ini = meio + 1;
		}
		else
			fim = meio - 1;
	}

	double pavg = avg/1000.0;
	
	cout<<setprecision(12)<<fixed;

	cout<<pavg<<endl<<med<<endl;
}