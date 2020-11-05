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


// void file_io()
// {
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
// }


const int N = 1e5 + 5;



int partition(vi &v, int beg, int end) {

	int pivot = end;
	int idx = beg;

	for (int i = beg; i < end; i++) {

		if(v[i] < v[pivot]) {

			swap(v[i], v[idx]);
			idx++;
		}
	}

	swap(v[idx], v[pivot]);
	
	return idx;
}

int randomPartition(vi &v, int beg, int end) {

	int n = rand();
	int pivot = beg + n%(end-beg+1);
	swap(v[pivot], v[end]);

	return partition(v, beg, end);
}

void quickSort(vi &v, int beg, int end) {

	if(beg >= end) return;

	// int idx = randomPartition(v, 0, end);
	int idx = partition(v, 0, end);

	quickSort(v, beg, idx-1);
	quickSort(v, idx+1, end);
}

int32_t main() {
	
	// file_io();
	
	ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	// int T; cin>>T; while(T--) 
	{
		
		int n;
		cin>>n;

		vi v(n);
		for (auto &ele : v) cin>>ele;

		quickSort(v, 0, n-1);	

		for (auto ele : v) cout<<ele<<" ";

	}	
	
	return 0;
}   
