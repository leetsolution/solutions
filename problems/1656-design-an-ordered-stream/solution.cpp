#include <vector>
#include <string>

using namespace std;

class OrderedStream {
public:
    OrderedStream(int n) : data(n + 1), ptr(1) {}
    
    vector<string> insert(int idKey, string value) {
        data[idKey] = value;
        vector<string> result;
        while (ptr < data.size() && !data[ptr].empty()) {
            result.push_back(data[ptr]);
            ptr++;
        }
        return result;
    }

private:
    vector<string> data;
    int ptr;
};