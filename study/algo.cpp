#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
int main() {
    int n,m; cin >> n >> m;
    set <int> arr;
    for(int i = 0; i < n; i++)
    {
        int a; cin >> a;
        arr.insert(a);
    }
    for(int i = 0; i < m; i++)
    {
        int s,e,t; cin >> s >> e >> t;
        auto low_t = arr.lower_bound(s);
		for(int i = 0; i < t; i++)
		{
			low_t++;
		}
        cout << *low_t << endl;
    }
}
