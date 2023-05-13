#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> map(n, vector<int>(n));
    vector<int> perm(n, 1);

    for (int i = 0; i < n / 2; i++)
        perm[i] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    int min_diff = 1000000000;

    do {
        int start = 0;
        int link = 0;
        vector<int> start_team;
        vector<int> link_team;

        for (int i = 0; i < n; i++) {
            if (perm[i] == 1)
                start_team.push_back(i);
            else
                link_team.push_back(i);
        }

        for (int i = 0; i < n / 2; i++) {
            for (int j = i + 1; j < n / 2; j++) {
                start += map[start_team[i]][start_team[j]] + map[start_team[j]][start_team[i]];
                link += map[link_team[i]][link_team[j]] + map[link_team[j]][link_team[i]];
            }
        }

        int diff = abs(start - link);

        if (diff < min_diff)
            min_diff = diff;

    } while (next_permutation(perm.begin(), perm.end()));

    cout << min_diff << "\n";

    return 0;
}
