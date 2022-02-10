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

typedef array<int, 3> point;

point operator+(point a, point b){
	return {a[0] + b[0], a[1] + b[1], a[2] + b[2]};
}

point operator-(point a, point b){
	return {a[0] - b[0], a[1] - b[1], a[2] - b[2]};
}

void print(point a){
	cout<<a[0]<<' '<<a[1]<<' '<<a[2]<<endl;
}

bool vis[25][25][25];
int dim[3], ans;
point fim, pfim;

bool check_in(point p){ // checa se o ponto ta dentro do cubo
	fr(i, 3)
		if (p[i] < 1 or p[i] > dim[i])
			return false;
	return true;	
}

bool all_valid(vector<point> stk){ // checa se p caminho é livre e valido (ponta não precisa ser valida de imediato)
	for (int i = 0; i < stk.size(); i++){
		point p = stk[i];

		if (vis[p[0]][p[1]][p[2]])
			return false;

		if (i + 1 < stk.size() and !check_in(p))
			return false;
	}

	return true;	
}

void mark_vis(vector<point> stk, int state){ // muda o estado de visita
	for (int i = 0; i + 1 < stk.size(); i++){
		point p = stk[i];
		vis[p[0]][p[1]][p[2]] = state;
	}
}

void backtrack(point now, point prev, int itr){
	if (itr > 6) // no maximo 6 peças
		return;

	if (now == fim and pfim == prev){ // estado final
		ans = min(ans, itr);
		return;
	}

	if (!check_in(now)) // se a ponta não ta dentro
		return;

	point dir = now - prev; // direção que eu vim,

	// tipo 1
	fr(i, 3)
		fr(j, 2)
			if (dir[i] == 0){
				vector<point> stk;

				point aux = now;	

				stk.pb(aux);
				aux = aux + dir;
				stk.pb(aux);

				point dir2 = {0, 0, 0};
				dir2[i] = -1 + 2 * j;

				fr(k, 3){
					aux = aux + dir2;
					stk.pb(aux);
				}
		
				point nxt = stk.back();
				point prv = stk[(int)(stk.size()) - 2];

				if (all_valid(stk)){ // checa se o caminho ta livre
					mark_vis(stk, 1);
					backtrack(nxt, prv, itr + 1);
					mark_vis(stk, 0);
				}	

				stk.clear();
			}

	// tipo 2
	fr(i, 3)
		fr(j, 2)
			if (dir[i] == 0){
				vector<point> stk;

				point aux = now;	

				stk.pb(aux);
				fr(k, 2){
					aux = aux + dir;
					stk.pb(aux);
				}

				point dir2 = {0, 0, 0};
				dir2[i] = -1 + 2 * j;

				fr(k, 2){
					aux = aux + dir2;
					stk.pb(aux);
				}

				point nxt = stk.back();
				point prv = stk[(int)(stk.size()) - 2];

				if (all_valid(stk)){ // checa se o caminho ta livre
					mark_vis(stk, 1);
					backtrack(nxt, prv, itr + 1);
					mark_vis(stk, 0);
				}	

				stk.clear();
			}		
}



signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int cnt = 1;
	while (cin>>dim[0]>>dim[1]>>dim[2]){
		int x, y, z;
		cin>>x>>y>>z;

		point st = {x, y, z}; // começo, e pre
		point pst = st;

		string s;
		cin>>s;

		for (char a = 'x'; a <= 'z'; a++)
			if (s[1] == a){
				int aux = 1;
				if (s[0] == '+')
					aux = -1;
				pst[a - 'x'] += aux; // ponto logo antes
			}

		cin>>x>>y>>z;
		pfim = {x, y, z};
		fim = pfim;

		cin>>s;
		for (char a = 'x'; a <= 'z'; a++)
			if (s[1] == a){
				int aux = -1;
				if (s[0] == '+')
					aux = 1;
				fim[a - 'x'] += aux; // ponto logo depois
			}

		ans = 7;

		backtrack(st, pst, 0);

		if (ans > 6)
			cout<<"Case "<<cnt<<": Impossible"<<endl;
		else
			cout<<"Case "<<cnt<<": "<<ans<<endl;

		cnt++;
	}
}