#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int size = triangle.size();
    vector<vector<int>> sum(size, vector<int>(size));
    sum[0][0] = triangle[0][0];
    for(int i = 1; i < size; i++) {
        for(int j = 0; j <= i; j++) {
            sum[i][j] = triangle[i][j];
            if (j == i || sum[i - 1][j - 1] >= sum[i - 1][j])
                sum[i][j] += sum[i - 1][j - 1];
            else if (j == 0 || sum[i - 1][j - 1] < sum[i - 1][j])
                sum[i][j] += sum[i - 1][j];
        }
    }
    
    for(auto i : sum[size - 1]) {
        if (answer < i) answer = i;
    }
    return answer;
}