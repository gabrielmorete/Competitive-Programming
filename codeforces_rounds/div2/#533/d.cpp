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

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;  
const int MAXN = 100100;
const ll mod=1e9+7;
const int LMAXN = 20;

typedef tuple<int,int,int> tup;
int mx[4]={1,-1,0,0};
int my[4]={0,0,-1,1};

int n,m,p;
int freq[11],s[11];
set<tup> fila[11],tem[11];
int mapa[1111][1111];

bool valido(int x,int y){
	if(x<0 || y<0) return false;
	if(x>=n || y>=m) return false;
	return true;
}

bool end(){
	int ok=1;
	frr(i,p)
		if(!tem[i].empty()){
			//dbg(i);
			ok=0;
		}

//	dbg(ok);	
	return ok;	
}


void bfs(){

	do{
		frr(cara,p){
			
		
			for(auto x:tem[cara])
				fila[cara].insert(x);
			tem[cara].clear();

			
			tup aux;
			while(!fila[cara].empty()){
				aux=*fila[cara].begin();
				fila[cara].erase(fila[cara].begin());
				
				int x,y;
				x=get<1>(aux);
				y=get<2>(aux);

				if(get<0>(aux)==s[cara]){
					tem[cara].insert({0,x,y});
					continue;
				}

				fr(i,4){
					if(valido(x+mx[i],y+my[i]) && mapa[x+mx[i]][y+my[i]]==0){
						freq[cara]++;
						fila[cara].insert({get<0>(aux)+1,x+mx[i],y+my[i]});
						mapa[x+mx[i]][y+my[i]]=cara;
					}
				}
			}

		}


	}while(!end());

}



int main(){
	fastio;
	cin>>n>>m>>p;
	frr(i,p) cin>>s[i];

	string aux;
	fr(i,n){
		cin>>aux;
		fr(j,m){
			if(aux[j]>='1' and aux[j]<='9'){
				freq[aux[j]-'0']++;
				tem[aux[j]-'0'].insert({0,i,j});
				mapa[i][j]=aux[j]-'0';
			}
			else if(aux[j]=='#')
				mapa[i][j]=-1;
			else
				mapa[i][j]=0;
		}
	}
	
	bfs();
	frr(i,p)
		cout<<freq[i]<<' ';
	gnl;	

}