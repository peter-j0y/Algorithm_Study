#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    stringstream sstream;
    sstream.str(s);
    int max = -1e9, min = 1e9, cur;
    while(sstream >> cur) {
        if (max < cur) max = cur;
        if (min > cur) min = cur;
    }
    answer = to_string(min) + " " + to_string(max);
    return answer;
}