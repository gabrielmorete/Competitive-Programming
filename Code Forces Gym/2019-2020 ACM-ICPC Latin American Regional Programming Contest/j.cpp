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
const int MAXN = 2e5 + 10;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// Comandos
// find_by_order(i) -> iterador para o i-ésimo elemento (contando do zero)
// order_of_key(k) -> número de elementos estritamente menores que k
// pode-se subtrair iteradores como em um vector

int n, m, hgt[MAXN], to_lft[MAXN], to_rgt[MAXN];
ordered_set lft, rgt;

void update(int pos, int h){
	// todo mundo que vem depois na esquerda
	int p = lft.order_of_key(pos) + to_lft[pos];

	while (p < lft.size() and hgt[*lft.find_by_order(p)] < h){ // posição não é mais especial
		to_lft[*lft.find_by_order(p)] = 0;
		lft.erase(lft.find_by_order(p));
		p = lft.order_of_key(pos) + to_lft[pos];
	}

	if (to_lft[pos] == 0){ // não é o primeiro
		int p = lft.order_of_key(pos) - 1;
		if (hgt[*lft.find_by_order(p)] < h){
			to_lft[pos] = 1;
			lft.insert(pos);
		}
	}

	p = rgt.order_of_key(pos) - 1;
	while (p >= 0 and hgt[*rgt.find_by_order(p)] < h){
		to_rgt[*rgt.find_by_order(p)] = 0;
		rgt.erase(rgt.find_by_order(p));
		p = rgt.order_of_key(pos) - 1;
	}

	if (to_rgt[pos] == 0){
		p = rgt.order_of_key(pos);
		if (hgt[*rgt.find_by_order(p)] < h){
			to_rgt[pos] = 1;
			rgt.insert(pos);
		}
	}

	hgt[pos] = h;	
}

int query(int dir, int pos){
	if (to_lft[pos] == 0 and to_rgt[pos] == 0){ // posição não é especial
		int esq, dir;
		dir = esq = pos; // não é especial, tem alguem a esquerda e a direita

		int p = lft.order_of_key(pos) - 1;
		esq = *lft.find_by_order(p);
		if (p + 1 < lft.size())
			dir = *lft.find_by_order(p + 1);
		
		p = rgt.order_of_key(pos);
		if ((dir == pos) or dir > *rgt.find_by_order(p))
			dir = *rgt.find_by_order(p);
		p--;
		if (p >= 0 and esq < *rgt.find_by_order(p))
			esq = *rgt.find_by_order(p);

		if (hgt[esq] > hgt[dir])
			return esq;
		return dir;
	}
	else if (to_lft[pos]){
		if (dir == 0 or to_rgt[pos])
			return pos;
		int p = lft.order_of_key(pos) + 1;
		return *lft.find_by_order(p);
	}
	else{
		// especial para direita
		if (dir == 1 or to_lft[pos])
			return pos;
		int p = rgt.order_of_key(pos) - 1;
		return *rgt.find_by_order(p);
	}
	return -1;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin>>n>>m;
	frr(i, n)
		cin>>hgt[i];

	int h = -1;
	
	frr(i, n){
		if (hgt[i] > h){ // special to left
			h = hgt[i];
			to_lft[i] = 1;
			lft.insert(i);
		}
	}

	h = -1;
	for (int i = n; i > 0; i--){ // special to right
		if (hgt[i] > h){
			h = hgt[i];
			to_rgt[i] = 1;
			rgt.insert(i);
		}
	}	

	char c;
	int x, y;
	while (m--){
		cin>>c;
		if (c == 'U'){ // update
			cin>>x>>y;
			update(x, y);
		}
		else{
			cin>>x;
			cout<<query(c == 'R', x)<<endl;
		}
	}
}