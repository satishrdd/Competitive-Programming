//[[t1, x, y], [t2, a, b], []]
// 0 - n-1
//logs = [[20190101,0,1],
// [20190104,3,4],
// [20190107,2,3],
// [20190211,1,5],
// [20190224,2,4],
// [20190301,0,3],
//[20190312,1,2],
//[20190322,4,5]], n = 6

// [0, 0, 2, 2, 3, 0] -> P
// [6, 1, 3, 2, 1, 1] -> F


#include<bits/stdc++.h>

using namespace std;

int timeWhereAllFriends(vector<vector<int>> logs, int n) {
    vector<int> parents(n);
    vector<int> friends(n,1);

    for(int i=0;i<n;i++)
        parents[i] = i;

    sort(logs.begin(), logs.end(), [](vector<int> &a, vector<int> &b) {
        return a[0] < b[0];
    });

    for(int i=0;i<logs.size();i++) {
        int f1 = logs[i][1];
        int f2 = logs[i][2];

        while(parents[f1] != f1) {
            f1 = parents[f1];
        }

        while(parents[f2] != f2) {
            f2 = parents[f2];
        }

        if(f1 == f2)
            continue;

        if(f1 > f2) {
            parents[f1] = f2;
            friends[f2] += friends[f1];
            if(friends[f2] == n)
                return logs[i][0];
        } else {
            parents[f2] = f1;
            friends[f1] += friends[f2];
            if(friends[f1] == n)
                return logs[i][0];
        }
    }
    return -1;
}