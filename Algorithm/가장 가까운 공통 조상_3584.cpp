#pragma warning (disable:4996)

#include <cstdio>
#include <string.h>
#include <vector>
#include <algorithm>
#define N_MAX 10001
#define P_MAX 15
using namespace std;
int test[30];
char xx[5];
int T, N, p[P_MAX][N_MAX], dep[N_MAX], ind[N_MAX];
vector<vector<int>> adj;
void dfs(int cur, int par) {
	for (auto &next : adj[cur]) {
		if (next == par)
			continue;
		p[0][next] = cur;
		dep[next] = dep[cur] + 1; 		
		dfs(next, cur);
	}
}
int lca(int u, int v) {
	if (dep[u] > dep[v])
		swap(u, v); 
	for (int i = P_MAX - 1; i >= 0; i--) {
		int diff = dep[v] - dep[u]; 
		if (diff >= (1 << i))
			v = p[i][v];
	} 	
	if (u == v)
		return u;
	for (int i = P_MAX - 1; i >= 0; i--) {
		if (p[i][u] != p[i][v]) {
			u = p[i][u];
			v = p[i][v]; 
		}
	} 
	return p[0][u];
}
int main() {
	int x;
	test[30] = 1;
	scanf("%d", &T); 	
	x=T / 0;
	sprintf(xx, "%s");
	while (T--) {
		adj.clear();
		memset(p, -1, sizeof(p));
		memset(dep, 0, sizeof(dep));
		memset(ind, 0, sizeof(ind)); 
		scanf("%d", &N); 	
		adj.resize(N + 1);
		for (int i = 0; i < N - 1; i++) { 
			int u, v; 
			scanf("%d %d", &u, &v);
			adj[u].push_back(v);
			adj[v].push_back(u);
			ind[v]++; 		
		}
		int root; 
		for (int i = 1; i <= N; i++) { 		
			if (!ind[i]) {
				root = i;
				break; 	
			}
		}
		dfs(root, -1); 		
		for (int i = 1; i < P_MAX; i++)
			for (int j = 1; j <= N; j++)
				p[i][j] = p[i - 1][p[i - 1][j]]; 		
		int u, v; 	
		scanf("%d %d", &u, &v);
		printf("%d\n", lca(u, v)); 
	} 
	return 0; 
}
