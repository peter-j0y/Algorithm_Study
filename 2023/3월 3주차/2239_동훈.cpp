#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;

bool check_validate(const vvi&map, pii now, int fill) {
    int x, y;
    x = now.first / 3 * 3;
    y = now.second / 3 * 3;

    for (int i = x; i < x + 3; i++) {
        for (int j = y; j < y + 3; j++) {
            if (map[i][j] == fill) return false;
        }
    }

    for (int i = 0; i < 9; i++) {
        if (map[now.first][i] == fill) return false;
        if (map[i][now.second] == fill) return false;
    }

    return true;
}

int main() {
    vvi map(9, vector<int>(9));
    vector<pii> point;
    int count;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%1d", &map[i][j]);
            if (map[i][j] == 0)
                point.emplace_back(i, j);
        }
    }
    count = point.size();
    vector<pii>::iterator target;
    for (target = point.begin(); target != point.end(); target++) {
        int start = map[target->first][target->second] + 1;
        map[target->first][target->second] = 0;
        int i;
        for (i = start; i <= 9; i++) {
            if (check_validate(map, *target, i)) {
                map[target->first][target->second] = i;
                count--;
                break;
            }
        }
        if (count == 0) break;
        if (i == 10) {
            count++;
            target -= 2;
        }
    }

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << map[i][j];
        }
        cout << endl;
    }

    return 0;
}

