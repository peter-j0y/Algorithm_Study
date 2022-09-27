#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <sstream>
 
using namespace std;
 
int getTimeDiff(string in, string out) {
    int inHour = stoi(in.substr(0, 2));
    int inMinute = stoi(in.substr(3, 2));
 
    int outHour = stoi(out.substr(0, 2));
    int outMinute = stoi(out.substr(3, 2));
 
    return (outHour - inHour) * 60 + (outMinute - inMinute);
}
 
vector<int> solution(vector<int> fees, vector<string> records) {
    map<string, vector<string>> infos;
    vector<int> answer;
 
    for (int i = 0; i < records.size(); i++) {
        stringstream ss(records[i]);
        string time, id;
 
        ss >> time >> id;
 
        infos[id].push_back(time);
    }
 
    for (const auto &info : infos) {
        string id = info.first;
        vector<string> v = info.second;
        int timeDiff = 0, fee = 0;
 
        if (v.size() & 1) {
            v.push_back("23:59");
        }
 
        for (int i = 0; i < v.size(); i += 2) {
            string in = v[i];
            string out = v[i + 1];
 
            timeDiff += getTimeDiff(in, out);
        }
 
        fee = fees[1];
        if (timeDiff > fees[0]) {
            fee += ceil((timeDiff - fees[0]) / (double)fees[2]) * fees[3];
        }
 
        answer.push_back(fee);
    }
 
    return answer;
}
