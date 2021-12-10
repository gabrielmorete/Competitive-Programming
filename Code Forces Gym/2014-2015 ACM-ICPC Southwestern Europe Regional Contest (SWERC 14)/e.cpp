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
const int MAXN = 1e8 + 10;

uint8_t dist[MAXN];

int n, w, h, l, pend, pwr[10];
int revto[10][10], tox[100], toy[100];
string mapa[10];

vi nxt;
void get_next(int ste){
	int aux = ste;
	vii in;
	fr(i, n){
		int p = aux % 100;
		mapa[tox[p]][toy[p]] = '0' + i;
		in.pb({tox[p], toy[p]});
		aux /= 100;
	}

	int x, y;

	fr(i, n){
		pii e = in[i];

		int aux = ste;
		aux -= revto[e.fst][e.snd] * pwr[2 * i]; // me tirei do estado

		tie(x, y) = e;
		while (x > 0 and mapa[x - 1][y] == '.')
			x--;

		int p = revto[x][y];
		int stnew = aux + p * pwr[2 * i];
		nxt.pb(stnew);

		tie(x, y) = e;
		while (x < h - 1 and mapa[x + 1][y] == '.')
			x++;
		
		p = revto[x][y];
		stnew = aux + p * pwr[2 * i];
		nxt.pb(stnew);

		tie(x, y) = e;
		while (y > 0 and mapa[x][y - 1] == '.')
			y--;
		
		p = revto[x][y];
		stnew = aux + p * pwr[2 * i];
		nxt.pb(stnew);

		tie(x, y) = e;
		while (y < w - 1 and mapa[x][y + 1] == '.')
			y++;
		p = revto[x][y];
		stnew = aux + p * pwr[2 * i];
		nxt.pb(stnew);
	}

	aux = ste;
	fr(i, n){
		int p = aux % 100;
		mapa[tox[p]][toy[p]] = '.';
		aux /= 100;
	}
}


signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	pwr[0] = 1;
	frr(i, 6)
		pwr[i] = pwr[i - 1] * 10;

	cin>>n>>w>>h>>l;

	int cnt = 0;
	fr(i, h)
		fr(j, w){
			revto[i][j] = cnt;
			tox[cnt] = i;
			toy[cnt] = j;
			cnt++;
		}

	int str = 0; // start

	fr(i, h){
		cin>>mapa[i];
		fr(j, w){
			if (mapa[i][j] == '.' or mapa[i][j] == 'W')
				continue;

			if (mapa[i][j] == 'X')
				pend = revto[i][j];

			else{
				int x = mapa[i][j] - '1';
				int p = revto[i][j];
				str += p * pwr[2 * x];
			}
			mapa[i][j] = '.';
		}
	}

	queue<int> fila;
	fila.push(str);

	int v;
	while (!fila.empty()){
		v = fila.front();
		fila.pop();


		if (v % 100 == pend){
			cout<<((int)dist[v])<<endl;
			return 0;
		}

		get_next(v);

		for (auto x : nxt)
			if (dist[x] == 0 and x != str){
				dist[x] = dist[v] + 1;
				if (dist[x] <= l)
					fila.push(x);
			}
		nxt.clear();	
	}

	cout<<"NO SOLUTION"<<endl;
}