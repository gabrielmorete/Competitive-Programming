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
const int MAXN = 3e3 + 10;

// https://codeforces.com/blog/entry/77298

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll n, a[MAXN];

	cin>>n;

	fr(i, n){
		cin>>a[i];
		a[i] -= i; // muda a condição de crescente para não decrescente
	}              // proximo numero sera uma unidade maior anyway


	ll ans = 0;
	priority_queue<ll> pq;

	// cuidado com o slope inicial, como fazemos a[i] -= i ele pode atrapalhar no meio	

	for (int i = 0; i < n; i++){
		pq.push(a[i]);

		if (pq.top() == a[i]) continue; // tudo bem, não precisa mudar

		ans += pq.top() - a[i]; // precisamos pagar o preço para fazer não decrescente

		pq.pop(); // retira somente o ultimo slope
		pq.push(a[i]); // reforça que o slope agora é zero
	}

	// nessa versão do slope trick, como o slope é sempre zero,
	// a gente só duplica o ultimo ponto de transição

	cout<<ans<<endl;
}