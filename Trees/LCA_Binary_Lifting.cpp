#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define F first
#define S second
#define pii pair<int, int>
#define vi vector<int>
#define vb vector<bool>
#define vii vector<pii>
#define vvi vector<vector<int>>
#define P_B push_back
#define M_P make_pair
#define endl "\n"

#define MOD 1000000007
#define pi 3.141592653589793238


// void file_io()
// {
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
// }


const int N = 1e5 + 5;

vvi tree, parent;
vi height;


void dfs(int node, int p, int ht = 0) {

	parent[node][0] = p;
	height[node] = ht;
	for (auto child : tree[node]) {

		if(p == child) continue;

		dfs(child, node, ht+1);
	}
}

int32_t main() {
	
	// file_io();
	
	int t = 0;

	ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int T; cin>>T; while(T--) 
	{
			
		int n;
		cin>>n;

		int maxN = ceil(log(n));
		if(n == 0) return 0;

		tree.clear();
		height.clear();
		parent.clear();

		tree.resize(n+1);
		height.resize(n+1);
		parent.resize(n+1, vi (maxN + 1, -1));

		vvi adj(n+1);
		for (int i = 1; i <= n; i++) {
			int c;
			cin>>c;
			if(c == 0) continue;

			while(c--) {
				int u;
				cin>>u;
				adj[i].P_B(u);
			}
		}

		for (int i = 1; i <= n; i++) {
			
			if(adj[i].size() == 0) continue;

			int u = i;
			for (auto v : adj[i]) {	
				tree[u].P_B(v);
				tree[v].P_B(u);
			}

		}

		dfs(1, -1);

		for (int j = 1; j <= maxN; j++) {

			for (int i = 1; i <= n; i++) {	
				if(parent[i][j-1] != -1) parent[i][j] = parent[parent[i][j-1]][j-1];
			}
		}

 		int q;
 		cin>>q;

 		cout<<"Case "<< ++t<<":" <<endl;
		while(q--) {
			int u, v;
			cin>>u>>v;

			if(height[u] > height[v]) swap(u, v);
			while(height[v] != height[u]) {

				int i = height[v] - height[u];
				int li = log(i);
				v = parent[v][li];
			}

			if(u == v) {
				cout<<u<<endl;
			}

			else {

				for (int i = maxN; i >= 0; i--) {

					if(parent[v][i] != -1 && parent[u][i] != -1 && parent[u][i] != parent[v][i]) {
						u = parent[u][i], v = parent[v][i];
					}
				}

				cout<<parent[u][0]<<endl;
			}

		}

	}	
	
	return 0;
}   
