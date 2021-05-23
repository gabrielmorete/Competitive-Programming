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

vector<int> v[8];

inline ll sq(ll x){	return x * x; }

void test(){
	vector<pair<ll, ll>> a;
	
	bool ok;	
	ll x;
	for (int i = 0; i < 8; i++)
		for (int j = i + 1; j < 8; j++){
			x = sq(v[i][0] - v[j][0]) + sq(v[i][1] - v[j][1]) + sq(v[i][2] - v[j][2]);
			ok = 0;
			for (int k = 0; k < a.size(); k++){
				if (a[k].fst == x){
					a[k].snd++;
					ok = 1;
					break;
				}
			}
			if (!ok)
				a.pb({x, 1});
		}

	sort(all(a));

	if (a.size() != 3)
		return;

	if (2*a[0].fst != a[1].fst or 3*a[0].fst != a[2].fst)
		return;
	if ((a[0].snd != 12) or (a[1].snd != 12) or (a[2].snd != 4))
		return;

	cout<<"YES"<<endl;
	for (int i = 0; i < 8; i++){
		fr(j, 3)
			cout<<v[i][j]<<' ';
		gnl;	
	}

	exit(0);
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	fr(i, 8){
		v[i].resize(3);
		fr(j, 3)
			cin>>v[i][j];
		sort(all(v[i]));	
	}

	do{
		do{
			do{
				do{
					do{
						do{
							do{
								// do{
									test();
								// } while(next_permutation(all(v[0])));
							} while(next_permutation(all(v[1])));
						} while(next_permutation(all(v[2])));
					} while(next_permutation(all(v[3])));
				} while(next_permutation(all(v[4])));
			} while(next_permutation(all(v[5])));
		} while(next_permutation(all(v[6])));
	} while(next_permutation(all(v[7])));

	cout<<"NO"<<endl;
}