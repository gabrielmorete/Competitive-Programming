#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1; i <= n; i++)

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

int n, ans[MAXN], in[MAXN], pos[MAXN];

signed main(){
	cin>>n;

	fr(i, MAXN)
		ans[i] = in[i] = pos[i] = 0;

	frr(i, n){
		cout<<"? ";
		frr(j, n)
			cout<< 1 + (j == i)<<' ';
		gnl;
		
		int x;
		cin>>x;

		if (x == 0){ // achei o n
			pos[n] = i;
			ans[i] = n;
		}
		else{
			if (x != i){ // cara uma unidade maior que eu, achei
				in[x] = i; // o cara na posição x é uma unidade maior que i
			}
		}
	}

	for (int j = n; j > 1; j--){
		if (in[pos[j]] == 0){// eu estou a direita desse cara, pois a query devolveu a posição dele
			cout<<"? ";
			for (int i = 1; i <= n; i++){
				if (i == pos[j]) // eu
					cout<<1<<' ';				
				else if (ans[i] != 0)// ja sei quem está aqui
					cout<<n<<' ';
				else
					cout<<2<<' ';
			}
			gnl;

			int x;
			cin>>x;
			in[pos[j]] = x;
		}



		ans[in[pos[j]]] = j - 1;
		pos[j - 1] = in[pos[j]];
	}

	cout<<"! ";
	frr(i, n)
		cout<<ans[i]<<' ';
	gnl;	
}