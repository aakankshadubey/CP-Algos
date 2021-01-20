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



bool checkCycle(vvi &graph, vb &visited, int node, vi &path, int n, int prev = -1) {

	if(path.size() == n) {

		// for (auto ele : path) cout << ele << " ";
		// 	cout << endl;
		return true;
	}


	
	for (auto ngb : graph[node]) {

		if(ngb == prev) continue;

		if(!visited[ngb]) {

			visited[ngb] = true;
			path.P_B(ngb);
			if(checkCycle(graph, visited, ngb, path, n, node)) return true;
			path.pop_back();
			visited[ngb] = false;

		}
		
	}

	return false;

}

int32_t main() {
    
    // file_io();
    
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T; cin>>T; while(T--) 
    {
        
    	int n, m;
    	cin >> n >> m;

    	vvi graph(n+1);
    	while(m--) {

    		int u, v;
    		cin >> u >> v;
    		// cout << u << " " << v << endl;
    		graph[u].P_B(v);
    		graph[v].P_B(u);

    	}

    	

    	bool answer = false;
    	for (int i = 1; i <= n; i++) {

    		vb visited(n+1, false);
	    	vi path(1, i);
	    	visited[i] = true;
    		if(checkCycle(graph, visited, i, path, n)) {
    			answer = true;
    			break;
    		}
    	}
    	cout << answer << endl;

    }    
    
    return 0;
}   

