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

int n, p[MAXN], esqy[MAXN], diry[MAXN], esqx[MAXN], dirx[MAXN];
int mpee[MAXN], mped[MAXN], mpde[MAXN], mpdd[MAXN];

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin>>n;
	frr(i, n)
		cin>>p[i];

	esqx[0] = esqy[0] = 0;	
	for (int i = 1; i <= n; i++){
		esqx[i] = esqy[i] = 1;
		if (p[i - 1] < p[i])
			esqx[i] += esqx[i - 1]; // posso diminuir
		else
			esqy[i] += esqy[i - 1]; // posso aumentar
	}

	dirx[n + 1] = diry[n + 1] = 0;
	for (int i = n; i > 0; i--){
		dirx[i] = diry[i] = 1;
		if (p[i + 1] < p[i])
			dirx[i] += dirx[i + 1]; // posso diminuir
		else
			diry[i] += diry[i + 1]; // posso aumentar
	}

	for (int i = 1; i < n; i++){
		mpee[i] = max(esqy[i], mpee[i - 1]); // maximo ir para esquerda entre 1 e i
		mpde[i] = max(diry[i], mpde[i - 1]); //                direita  entre 1 e i   
	}

	for (int i = n; i > 0; i--){
		mped[i] = max(esqy[i], mped[i + 1]); // maximo ir para esquerda entre i e n
		mpdd[i] = max(diry[i], mpdd[i + 1]); //                direita  entre i e n 	
	}

	int ans = n;

	for (int i = 0; i < n; i++){
		int a = esqx[i];
		int b = dirx[i];

		if (a < b)
			swap(a, b);
		if (a % 2 == 0 or (a - 1) >= b){
			ans--;
			continue;
		}

		if (mpde[i - esqx[i] - 1] >= a or mped[i + dirx[i] + 1] >= a){
			ans--;
			continue;
		}

		if (mpee[i] >= a or mpdd[i] >= a){
			ans--;
			continue;
		}
	}
	cout<<ans<<endl;
}