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
#define all(x)  x.begin(),x.end()

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 1e6 + 10;

int n, sum[MAXN];
vector<int> pos;

int getsum(int l, int r){
	if (l > r)
		return 0;
	if (l <= 0) return sum[r];
	return sum[min(r, n - 1)] - sum[l - 1];
}

int memo[MAXN]; // primiera posição descoberta usando i - 1 pacmans gastando no máximo tempo val

bool check(int val){
	int m = pos.size();
	memo[0] = 0;

	for (int i = 0; i < m; i++){
		if (getsum(memo[i], pos[i] - val - 1)) //não consigo cobrir o intervalo
			return false;
		
		if (getsum(memo[i], pos[i])){ // intervalo a minha esqurda é não vazio, vou para lá
			memo[i + 1] = pos[i] + 1; // não cubro nada além da minha posição
		
			if (i > 0 and getsum(memo[i - 1], pos[i] - val - 1) == 0)
				memo[i + 1] = max(memo[i + 1], pos[i - 1] + val + 1); // meu antecessor vem para direita
		} else
			memo[i + 1] = pos[i] + val + 1;  // eu vou para direita
	}

	
	return getsum(memo[m], n) == 0; // não sobrou ninguem
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin>>n;

	string s;
	cin>>s;

	for (int i = 0; i < n; i++){
		sum[i] = s[i] == '*';
		if (i > 0)
			sum[i] += sum[i - 1];

		if (s[i] == 'P')
			pos.pb(i);
	}

	if (pos.size() == 1){
		int cnt, tme;
		cnt = tme = 0;
		for (int i = pos[0]; i < n; i++){
			if (s[i] == '*'){
				cnt++;
				tme = i - pos[0];
			}
		}

		int aux = 0;
		for (int i = pos[0]; i >= 0; i--){
			if (s[i] == '*'){
				aux++;
				if (aux == cnt)
					tme = min(tme, pos[0] - i);
				if (aux > cnt){
					cnt = aux;
					tme = pos[0] - i;
				}
			}
		}
		cout<<cnt<<' '<<tme<<endl;	
		return 0;
	}

	int l = 1, r = n, best = -1, meio;

	while (l <= r){ // bb no tempo máximo
		meio = (l + r)/2;
		if (check(meio)){
			best = meio;
			r = meio - 1;
		}
		else
			l = meio + 1;
	}

	cout<<sum[n - 1]<<' '<<best<<endl;
}