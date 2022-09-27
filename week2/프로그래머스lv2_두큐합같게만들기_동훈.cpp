#include <string>
#include <vector>
#include <deque>
#include <numeric>

using namespace std;

typedef long long ll;

int solution(vector<int> queue1, vector<int> queue2) {
    deque<int> q1(queue1.begin(), queue1.end());
    deque<int> q2(queue2.begin(), queue2.end());
    int answer = 0;
    int size = q1.size() + queue2.size();
    
    ll sum1 = accumulate(q1.begin(), q1.end(), 0);
    ll sum2 = accumulate(q2.begin(), q2.end(), 0);
    
    if(sum1 % 2 != sum2 % 2)
        return -1;
    for (answer = 0; answer <= size + 2; answer++) {
        if (sum1 == sum2)
            break;
        else if (sum1 > sum2) {
            q2.push_back(q1.front());
            sum1 -= q1.front();
            sum2 += q1.front();
            q1.pop_front();
        }
        else {
            q1.push_back(q2.front());
            sum1 += q2.front();
            sum2 -= q2.front();
            q2.pop_front();
        }
    }
    
    if (answer > size + 2)
        answer = -1;
    
    return answer;
}
