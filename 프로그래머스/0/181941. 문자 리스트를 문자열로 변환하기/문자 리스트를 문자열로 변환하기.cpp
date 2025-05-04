#include <string>
#include <vector>

using namespace std;

string solution(vector<string> arr) {
    string result = "";
    for (const string& a : arr) {
        result += a;
    }
    return result;
}