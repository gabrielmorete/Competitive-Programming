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

int w, h, n;
vii carp;

bool usado[10], ucanto[20];
int  totarea;
pii esup[10], dinf[10];
vii canto;

// atenção, um retangulo é fechado na esquerda e aberto na direita

bool check(int a, int b, int c, int d){
	if (b <= c or d <= a) return false; // pode colocar, não está contido
	return true;
}

bool intsec(pii a, pii b){ // checa intersecção com outros retangulos
	for (int i = 0; i < n; i++)
		if (usado[i]){
			bool ok = check(a.fst, b.fst, esup[i].fst, dinf[i].fst); // checa em x
			ok &= check(a.snd, b.snd, esup[i].snd, dinf[i].snd); // checa em y
			if (ok) // se intersecta nos dois,deu errado
				return true;
		}

	if (a.fst < 0 or a.fst > w or b.fst < 0 or b.fst > w)	return true; // checa se está no tabuleiro
	if (a.snd < 0 or a.snd > h or b.snd < 0 or b.snd > h)	return true;

	return false;
}

bool cvalid(pii a){ // checa se um ponto inicial é válido
	if (a.fst < 0 or a.fst >= w)
		return false;
	if (a.snd < 0 or a.snd >= h)
		return false;
	for (int i = 0; i < n; i++) //não está contido em ninguem ativo
		if (usado[i]){
			bool ok = (esup[i].fst <= a.fst and a.fst < dinf[i].fst);
			ok &= (esup[i].snd <= a.snd and a.snd < dinf[i].snd);
			if (ok)
				return false;
		}

	return true;
}

void backtrack(){
	if (totarea == w * h){ // consegui
		cout<<"yes"<<endl;
		exit(0);
	}

	if (totarea > w * h) // passou :(
		return;

	int numc = 0;
	pii pos = {-1, -1};
	for (int j = 0; j < canto.size(); j++) // acha o canta mais alto a esquerda
		if (!ucanto[j] and cvalid(canto[j])){
			if (pos.fst == -1){
				pos = canto[j];
				numc = j;
			}
			else{
				if (canto[j].snd < pos.snd){ // mais alto
					pos = canto[j];
					numc = j;
				}	
				if (canto[j].snd == pos.snd and canto[j].fst < pos.fst){ // mais a esquerda
					pos = min(pos, canto[j]);
					numc = j;
				}	
			}
		}

	if (pos.fst == -1) // sem canto valido
		return;	


	for (int i = 0; i < n; i++){ // acha cara para colocar
		if (usado[i])
			continue;
		int x, y;
		tie(x, y) = carp[i];

		fr(k, 2){
			pii pos2 = {pos.fst + x, pos.snd + y};

			if (!intsec(pos, pos2)){ // coloca e continua;
				usado[i] = 1;
				ucanto[numc] = 1;
				canto.pb({pos.fst, pos2.snd});
				canto.pb({pos2.fst, pos.snd});
				totarea += x * y;
		
				esup[i] = pos;
				dinf[i] = pos2;

				backtrack();

				usado[i] = 0;
				ucanto[numc] = 0;
				canto.pop_back();
				canto.pop_back();
				totarea -= x * y;
			}

			swap(x, y); // tenta outra orientação
		}
	}
}


int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>w>>h;

	cin>>n;

	int area = 0;

	int c, a, b;
	fr(i, n){
		cin>>c>>a>>b;
		while (c--){
			carp.pb({a, b});
			area += a * b;
		}
		
	}

	if (area < w * h){
		cout<<"no"<<endl;
		return 0;
	}

	n = carp.size();

	canto.pb({0, 0});

	backtrack();

	cout<<"no"<<endl;
}