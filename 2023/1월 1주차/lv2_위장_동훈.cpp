#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    int flag = 0;
    map<string, int> m;
    
    for(auto i : clothes) {
        flag = 0;
        for(auto j : m) {
            if (j.first == i[1]) {
                flag = 1;
                m[i[1]]++;
            }
        }
        if (!flag) {
            m[i[1]] = 1;
        }
    }
    
    for(auto i : m) {
        answer *= (i.second + 1);
    }
    answer--;
    
    return answer;
}