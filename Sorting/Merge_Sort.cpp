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

void merge(vi &v, int beg, int mid, int end) {

	vi tmp;
	int i = beg, j = mid+1;

	while(i <= mid && j <= end) {

		if(v[i] < v[j]) tmp.P_B(v[i++]);
		else tmp.P_B(v[j++]);
	}

	while(i <= mid) tmp.P_B(v[i++]);
	while(j <= end) tmp.P_B(v[j++]);


	for (int i = beg, k = 0; i <= end && k < tmp.size(); i++, k++) v[i] = tmp[k];

}


void mergeSort(vi &v, int beg, int end) {

	if(beg >= end) return;

	int mid = beg + (end-beg)/2;
	mergeSort(v, beg, mid);
	mergeSort(v, mid+1, end);

	merge(v, beg, mid, end);

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
		mergeSort(v, 0, n-1);

		for (auto ele : v) cout<<ele<<" ";
		cout<<endl;

	}	
	
	return 0;
}   
