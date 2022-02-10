#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define fst first
#define snd second

#define fr(i,n)     for (int i = 0; i < n; i++)
#define frr(i,n)    for (int i = 1; i <= n; i++)

// #define endl '\n'
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

int N;
vi v, a[3]; // piso piso teto

void answer(int val){
	cout<<"ANSWER "<<val<<endl;
	exit(0);
}


void balance(){ // a[0] e a[1] tem menos, a[3] tem mais
	int n = v.size();
	int m = n/3;

	fr(i, 3)
		a[i].clear();

	fr(i, m){
		a[0].pb(v.back());
		v.pop_back();
	}
			
	fr(i, m){
		a[1].pb(v.back());
		v.pop_back();
	}

	a[2] = v;
}

int read(){
	string s;
	cin>>s;

	if (s == "LEFT")
		return -1;

	if (s == "EQUAL")
		return 0;
	
	return 1;
}

int query(int sz, int id1, int id2){
	cout<<"WEIGHT "<<sz<<" ";
	fr(i, sz)
		cout<<a[id1][i]<<' ';
	fr(i, sz)
		cout<<a[id2][i]<<' ';	
	gnl;	

	return read();
}

int query2(int x, int y){
	cout<<"WEIGHT 1 "<<x<<' '<<y<<endl;
	return read();
}


int n, status = 0; // status da bolinha diferente, 0 se não sei, -1 se é mais leve, 1 se é mais pesada



void final(){ // n<3
	// chapa;
	// dbg(a[0].size());
	// dbg(a[1].size());
	// dbg(a[2].size());

	// sei que a[2] é não vazio e a[0] e a[1] são
	if (a[2].size() == 1 and status != 0){
		answer(status * a[2].back());
		exit(0);
	}

	if (a[2].size() == 1 and status == 0){
		// chapa;
		int d = 1;
		frr(i, N)
			if (i != a[2].back())
				d = i;
		
		// sei que a d é neutra
		
		int aux = query2(d, a[2].back());
		assert(aux != 0);

		answer(a[2].back() * aux);
	}

	if (a[2].size() == 2 and status != 0){
		int aux = query2(a[2][0], a[2][1]);
		if (status == -1){
			if (aux == -1)
				answer(-a[2][1]);
			else
				answer(-a[2][0]);
		}
		else{
			if (aux == -1)
				answer(a[2][0]);
			else
				answer(a[2][1]);
		}
	}

	int df = 1;
	frr(i, N)
		if (i != a[2][0] and i != a[2][1])
			df = i;

	int r0 = query2(df, a[2][0]);
	int r1 = query2(df, a[2][1]);

	if (r0 == 0)
		answer(r1 * a[2][1]);
	else		
		answer(r0 * a[2][0]);
}


void solve(){
	n = v.size();
	balance(); // divide em 3

	if (n < 3)
		final();

	// sei que todos os vetores são não vazios e |a[0]| = |a[1]|

	int aux = query(a[0].size(), 0, 1);

	if (aux == 0){ // conjunto 0 e 1 tem o mesmo tamanho e peso
		v = a[2];
		solve();
	}

	// aux != 0
	if (status == 0){ // vou descobrir se a diferente é menor ou maior
		int aux2 = query(a[0].size(), 2, 0); // sei que o 2 só tem neutro

		if (aux2 == 0){ // sei que a[1] é diferente
			status = aux;
			v = a[1];
			solve();
		}
		else{
			status = aux2;
			v = a[0];
			solve();
		}
	}
	else{ // a difete está em a[0] ou a[1]
		if (status == -1){ // mais leve
			if (aux == -1){ // está na direita
				v = a[1];
				solve();
			} else{
				v = a[0];
				solve();
			}	
		}
		else{ // mais pesada
			if (aux == -1){ // está na esquerda
				v = a[0];
				solve();
			} else{
				v = a[1];
				solve();
			}
		}
	}
}


signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>N;

	frr(i, N)
		v.pb(i);

	solve();
}