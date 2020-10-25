#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ll long long 
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


void file_io()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}


const int N = 1e5 + 5;
vii answer;
vvi graph;
vb visited;
vi time_in, low_time;
int timer;


void pre(int n) {
		
		graph.clear();
		visited.clear();
		time_in.clear();
		low_time.clear();
		answer.clear();

		graph.resize(n+1);
		visited.resize(n+1, false);
		time_in.resize(n+1, -1);
		low_time.resize(n+1, -1);
		timer = 0;
}

void dfs(int node, int parent = -1) {

	visited[node] = true;
	time_in[node] = timer;
	low_time[node] = timer;

	timer++;
	
	for (auto ngb : graph[node]) {

		if(parent == ngb) continue;

		if(visited[ngb]) {
			low_time[node] = min(low_time[node], time_in[ngb]);
		}

		else {
			dfs(ngb, node);
			low_time[node] = min(low_time[node], low_time[ngb]);

			if(low_time[ngb] > time_in[node]) {
				answer.P_B({node, ngb});
			}
		}
	}

}


int32_t main() {
	
	// file_io();

	int t = 1;
	
	ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int T; cin>>T; while(T--) 
	{
		
		int n, k;
		cin>>n>>k;

		pre(n);
		
		while(k--) {

			int u, v;
			cin>>u>>v;

			graph[u].P_B(v);
			graph[v].P_B(u);
		}

		for (int i = 1; i <= n; i++) {
			if(!visited[i]) dfs(i);
		}

		cout<<"Caso #"<<t++<<endl;

		if(answer.size() == 0 ) {
			cout<<"Sin bloqueos"<<endl;
			continue;
		}


		sort(answer.begin(), answer.end());

		cout<<answer.size()<<endl;
		for (auto ele : answer) {

			cout<<ele.F<<" "<<ele.S<<endl;
		}

	}	
	
	return 0;
}   
