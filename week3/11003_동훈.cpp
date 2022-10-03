#include <iostream>
#include <queue>

using namespace std;

struct custom {
    custom(int i, int i1) {
        value = i;
        index = i1;
    }

    int value;
    int index;
};

struct compare {
    bool operator()(custom &a, custom &b) {
        if (a.value == b.value)
            return a.index > b.index;
        return a.value > b.value;
    }
};

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, l;
    int input;
    priority_queue<custom, vector<custom>, compare> pq;
    cin >> n >> l;

    for (int i = 1; i <= n; i++) {
        cin >> input;
        custom tmp = custom(input, i);
        pq.push(tmp);
        while (pq.size() >= l && i - pq.top().index >= l)
            pq.pop();
        cout << pq.top().value << " ";
    }

    return 0;
}