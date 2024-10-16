class MyHashSet {
private:
    vector<bool>mp;
public:
    MyHashSet() {
        // False indicates there is no element present in the vector initially
        mp.resize(1000001, false); 
    }
    
    void add(int key) {
        mp[key] = true;// Mark it as present
    }
    
    void remove(int key) {
        mp[key] = false;// mark it as absent
    }
    
    bool contains(int key) {
        return mp[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */