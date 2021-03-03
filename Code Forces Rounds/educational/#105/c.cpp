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

int im, in;
vi va, vb, a, b;

int sum[MAXN]; // não mexi, ainda deu

int calc(){
	int n = a.size();
	int m = b.size();

	if (n == 0 or m == 0)
		return 0;

	int p = 0;
	for (int i = 0; i < m; i++){
		while (p < n - 1 and a[p + 1] <= b[i])
			p++;
		
		if (a[p] == b[i])
			sum[i] = 1;
		else
			sum[i] = 0;
	}
	
	// dbg(m);	
	sum[m] = 0;
	for (int i = m - 1; i >= 0; i--)
		sum[i] += sum[i + 1];

	int ans = sum[0]; // faço nada
	// dbg(sum[0]);
	// vou tentar ficar 1 antes de todas as especiais;

	p = -1; // tamanho da sequencia de caixas
	int q = 0;
	for (int i = 0; i < m; i++){ // estou antes da posição i em b
		while (p < n - 1 and a[p + 1] <= b[i]) // caixas atrás
			p++; 
		
		if (p >= 0){
			while (p < n - 1 and b[i] + p >= a[p + 1]) // caixas que eu to pegando dedepois do b[i]
				p++;

			while (q < m - 1 and b[q + 1] <= b[i] + p) // posições especiais dentro da seq
				q++;
			
			if (q - i + 1 + sum[q + 1] > ans)
					ans = q - i + 1 + sum[q + 1];
		}	
	}

	return ans;
}


void solve(){
	va.clear();
	vb.clear();
	a.clear();
	b.clear();
	cin>>in>>im;

	int x;
	fr(i, in){
		cin>>x;
		if (x >= 0)
			a.pb(x);
		else
			va.pb(-x);
	}
	fr(i, im){
		cin>>x;
		if (x >= 0)
			b.pb(x);
		else
			vb.pb(-x);
	}

	reverse(all(va));
	reverse(all(vb));

	// for (auto x : a)
	// 	cout<<x<<' ';
	// gnl;
	// for (auto x : b)
	// 	cout<<x<<' ';
	// gnl;


	int ans = calc();

	a = va;
	b = vb;

	// chapa;

	// for (auto x : a)
	// 	cout<<x<<' ';
	// gnl;
	// for (auto x : b)
	// 	cout<<x<<' ';
	// gnl;

	ans += calc();

	cout<<ans<<endl;
	// gnl;
	// gnl;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin>>T;
	while (T--)
		solve();
}