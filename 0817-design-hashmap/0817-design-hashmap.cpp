class MyHashMap {
private:
        vector<pair<int, int>>vec;
public:
    MyHashMap() {
    }
    
    void put(int key, int value) {
        bool updated = false;
        for(int i=0; i<vec.size(); i++) {
            if(vec[i].first == key) { 
                vec[i].second = value;
                updated = true;
            }
        }
        if(updated==false) {
            vec.push_back({key, value});
        }
    }
    
    int get(int key) {
        for(int i=0; i<vec.size(); i++) {
            if(vec[i].first == key) {
                return vec[i].second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        for (auto it = vec.begin(); it != vec.end(); ++it) { // Use an iterator
            if (it->first == key) {
                vec.erase(it);  // Erase the element at the iterator position
                break;          // Exit loop after erasing
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */