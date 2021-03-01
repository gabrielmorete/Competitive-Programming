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
const int MAXN = 1e2 + 10;

int g, c, n;
int tipo[MAXN], pack[MAXN], valor[MAXN];

int memo[2][MAXN][40010];

int pd(){

	for (int pos = n - 1; pos >= 0; pos--){

		for (int ouro = 0; ouro <= 100; ouro++)
			for (int prata = 0; prata < 20010; prata++){
				int &pdm = memo[0][ouro][prata];
				
				pdm = memo[1][ouro][prata]; // faz nada

				if (prata >= valor[pos]) // compro com prata
					pdm = max(pdm, 1 + memo[1][ouro][prata - valor[pos]]);
				
				if ((tipo[pos] < 1 or (tipo[pos] == 1 and prata < valor[pos])) and ouro > 0){ //
					int troco = g - valor[pos];
					if (tipo[pos] == -1) // greedy
						troco /= pack[pos];
					else if (tipo[pos] == 1)
						troco = (troco + pack[pos] - 1)/pack[pos];
					else{
						if (troco % pack[pos] >= (pack[pos] + 1)/2) // arredonda para cima
							troco = (troco + pack[pos] - 1)/pack[pos];
						else
							troco /= pack[pos];
					}

					troco *= pack[pos];
					pdm = max(pdm, 1 + memo[1][ouro - 1][prata + troco]);
				}	
			}

		for (int ouro = 0; ouro <= 100; ouro++)
			for (int prata = 0; prata < 20010; prata++)
				memo[1][ouro][prata] = memo[0][ouro][prata];		
	}

	return memo[0][c][0];
}


int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin>>g>>c>>n;

	string s;
	fr(i, n){
		cin>>s>>pack[i]>>valor[i];
		if (s == "greedy")
			tipo[i] = -1;
		else if (s == "honest")
			tipo[i] = 0;
		else
			tipo[i] = 1;
	}

	cout<<pd()<<endl;
}