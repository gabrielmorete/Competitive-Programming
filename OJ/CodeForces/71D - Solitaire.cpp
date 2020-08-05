#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,n)    for(int i=1;i<=n;i++)

#define ms(x,i) memset(x,i,sizeof(x))
#define dbg(x)  cout << #x << " = " << x << endl
#define all(x)  x.begin(),x.end()

#define gnl cout << endl
#define chapa cout << "oi meu chapa" << endl
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
//cout << setprecision(9)<<fixed;

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = (long long)(1e18) + 100;   
const int MAXN = 100100;
const int MAXM = 1001000;
const ll mod=1e9+7;
const int LMAXN = 25;

int n, m;
bool in[100];
std::vector<string> v, joker;
vii jokerp;
string ranq[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K", "A"};
string suits[4] = {"C", "D", "H", "S"};
string tab[18][18];
std::map<string, bool> esta;

void genstrings(){
	fr( i, 4)
		fr( j, 13) {
			v.pb( ranq[j] + suits[i]);
			esta[ranq[j] + suits[i]] = 0;
		}
}

bool inter[18][18];
bool valid(int a, int b, int c, int d){
	ms(inter, 0);
	fr(i,3)
		fr(j,3)
			inter[i + a][j + b] = 1;
	fr(i,3)
		fr(j,3)
			if (inter[i + c][j + d] == 1)
				return false;
	// if (a <= c and c <= a + 2 and b <= d and d <= b + 2)
	// 	return false;
	// if (c <= a and a <= c + 2 and d <= b and b <= d + 2)
	// 	return false;
	return true;
}

bool check_rank(int a, int b) {
	int used_rank[300];
	ms(used_rank, 0);

	fr(i,3)
		fr(j,3) {
			if (used_rank[ tab[i + a][j + b][0] ] == 1)
				return false;
			else
				used_rank[ tab[i + a][j + b][0] ] = 1;
		}	
	return true;
}

vii ans;

bool check_valid(){

	fr(i, n - 2)
		fr(j, m - 2)
			if (check_rank( i, j)) {
				fr(a, n - 2)
					fr(b, m - 2)
						if (valid( i, j, a, b) and check_rank( a, b)){
							ans.pb({i + 1, j + 1});
							ans.pb({a + 1, b + 1});
							return true;
						}
			}
	return false;                   
}

int main(){
	fastio;
	genstrings();
	cin>>n>>m;

	string s;
	fr(i,n) {
		fr(j,m) {
			cin>>s;
			tab[i][j] = s;
			esta[s] = 1;
			if (s == "J1" or s == "J2") {
				joker.pb(s);
				jokerp.pb({i,j});
			}
		}
	}

	if (joker.size() == 2 and joker[0] == "J2"){
		swap(jokerp[0], jokerp[1]);
		swap(joker[0],joker[1]);
	}	

	if (!joker.size()) {
		if (check_valid()) {
			cout<<"Solution exists."<<endl;
			cout<<"There are no jokers."<<endl;
			cout<<"Put the first square to ("<<ans[0].fst<<", "<<ans[0].snd<<")."<<endl;
			cout<<"Put the second square to ("<<ans[1].fst<<", "<<ans[1].snd<<")."<<endl;
			return 0;
		}
		else {
			cout<<"No solution."<<endl;
			return 0;
		}
	}

	if (joker.size() == 1) {
		fr(i,v.size()) {
			if (!esta[v[i]]){
				tab[jokerp[0].fst][jokerp[0].snd] = v[i];
				if (check_valid()) {
					cout<<"Solution exists."<<endl;
					cout<<"Replace "<<joker[0]<<" with "<<v[i]<<"."<<endl;
					cout<<"Put the first square to ("<<ans[0].fst<<", "<<ans[0].snd<<")."<<endl;
					cout<<"Put the second square to ("<<ans[1].fst<<", "<<ans[1].snd<<")."<<endl;
					return 0;
				}
			}
		}	
	}
	if (joker.size() == 1) {
		cout<<"No solution."<<endl;
		return 0;
	}

	fr(i,v.size())
		fr(j,v.size())
			if (i != j and !esta[v[i]] and !esta[v[j]]){
				tab[jokerp[0].fst][jokerp[0].snd] = v[i];
				tab[jokerp[1].fst][jokerp[1].snd] = v[j];
				if (check_valid()) {
					cout<<"Solution exists."<<endl;
					cout<<"Replace "<<joker[0]<<" with "<<v[i]<<" and "<<joker[1]<<" with "<<v[j]<<"."<<endl;
					cout<<"Put the first square to ("<<ans[0].fst<<", "<<ans[0].snd<<")."<<endl;
					cout<<"Put the second square to ("<<ans[1].fst<<", "<<ans[1].snd<<")."<<endl;
					return 0;
				}

			}

	cout<<"No solution."<<endl;
	return 0;
}