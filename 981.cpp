class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> store;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (store.find(key) == store.end()) {
            return "";
        }

        int left = 0;
        int right = store[key].size() - 1;
        int resultIdx = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (store[key][mid].first <= timestamp) {
                resultIdx = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        if (resultIdx == -1) {
            return "";
        }
        return store[key][resultIdx].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

