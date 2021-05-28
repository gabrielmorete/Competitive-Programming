// Algoritmo de Gale–Shapley para o problema do casamento estável
// O(número de preferências)

// Um arranjo é estável se não há uma troca simples em que ambos os membros
// de um novo casal ficam mais satisfeitos

// Retorna sempre o melhor arranjo para os homens e o pior para as mulheres
int n, m; // # de homens e mulheres
vector<int> lista[MAXN]; // lista de mulheres para cada homem
int nota[MAXN][MAXN]; // nota que cada mulher da para cada homem
int matchn[MAXN], matchm[MAXN]; // par de cada membro
int p[MAXN]; // progresso de cada homem

void stable_marriage(){
	fill(matchm, matchm + m, -1);
	fill(p, p + n, 0);
	int hubby, man, wom;
	for (int i = 0; i < n; i++){
		man = i;
		while (man != -1){
			bool ok = 0;
			while (!ok and p[man] < lista[man].size()){
				wom = lista[man][p[man]++];
				if (matchm[wom] == -1 or nota[wom][man] > nota[wom][matchm[wom]]) 
					ok = 1;
			}
			if (!ok){
				matchn[man] = -1;
				man = -1;
			}
			else{
				hubby = matchm[wom];
				matchm[wom] = man;
				matchn[man] = wom;
				man = hubby;
			}
		}
	}
}
// Quando uma mulher pode ter varios homens, adicione capacidade + fila de prioridade