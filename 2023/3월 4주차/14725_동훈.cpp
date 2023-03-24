#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class node {
public:
    string name;
    vector<node *> children;

    node(string name) {
        this->name = name;
    }
};

bool compare(node *a, node *b) {
    return a->name < b->name;
}

void result(node *root, int level) {
    sort(root->children.begin(), root->children.end(), compare);

    for (int i = 1; i <= level; i++) {
        cout << "--";
    }
    cout << root->name << "\n";
    for (auto child: root->children) {
        result(child, level + 1);
    }
}

int main() {
    int n;
    cin >> n;

    node *tree = new node(""), *target;
    queue<string> names;

    while (n--) {
        int k;
        cin >> k;

        while (k--) {
            string input;
            cin >> input;
            names.push(input);
        }
        target = tree;
        while (!names.empty()) {
            int chk = 0;
            for (auto i: target->children) {
                if (i->name == names.front()) {
                    chk = 1;
                    target = i;
                    names.pop();
                    break;
                }
            }
            if (chk == 0) {
                node *child = new node(names.front());
                target->children.push_back(child);
                target = child;
                names.pop();
            }
        }
    }

    sort(tree->children.begin(), tree->children.end(), compare);
    for (auto i: tree->children) {
        result(i, 0);
    }

    return 0;
}