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

int ans[MAXN]; // ans[i] menor numero em que gera o valor i % mn

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	memset(ans, INF, sizeof ans);

	int n;

	cin>>n;

	int mn;
	cin>>mn;

	ans[0] = 0; // mn % mn
	for (int i = 1; i < n; i++){
		int x;
		cin>>x;

		int mdc = __gcd(x, mn);
		int t = mn / mdc;

		int xm = x % mn;

		for (int j = 0; j < mdc; j++)
			for (int k = 1; k <= 2 * t; k++)
				ans[(j + xm * k) % mn] = min(ans[(j + xm * k) % mn], ans[(j + xm * (k - 1)) % mn] + x);
	}

	int q;
	cin>>q;

	while (q--){
		int x;
		cin>>x;

		if (ans[x % mn] > x)
			cout<<"NIE"<<endl;
		else
			cout<<"TAK"<<endl;
	}
}