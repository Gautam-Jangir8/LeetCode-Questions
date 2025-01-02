class LockingTree {
public:
    unordered_map<int, vector<int>>children;// To track the childrens of each node
    unordered_map<int, int>locked_by;// To keep track of locked_nodes and the user who locked them
    vector<int>p;// to store the parent vector

    LockingTree(vector<int>& parent) {
        p = parent;
        // Map all the parent children
        for(int i=0; i<parent.size(); i++) {
            children[parent[i]].push_back(i);
        }
    }
    
    bool lock(int num, int user) {
        // If already locked, then return false
        if(locked_by.find(num) != locked_by.end()) {
            return false;
        }

        locked_by[num] = user;
        return true;
    }
    
    bool unlock(int num, int user) {
        // If already unlocked, then return false
        if(locked_by.find(num)==locked_by.end()) {
            return false;
        }

        if(locked_by[num]!=user) {
            return false;
        }
        locked_by.erase(num);
        return true;
    }

    bool is_locked_child(int num) {
        bool flag = false;
        if(locked_by.find(num)!=locked_by.end()) {
            flag = true;
        }
        for(auto ch: children[num]) {
            flag |= is_locked_child(ch);
        }

        return flag;
    }

    bool is_locked_parent(int num) {
        if (num == -1) return false;
        if (locked_by.find(num) != locked_by.end()) return true;
        return is_locked_parent(p[num]);
    }

    void unlock_descendants(int num) {
        for (auto ch : children[num]) {
            locked_by.erase(ch);
            unlock_descendants(ch);
        }
    }
    
    bool upgrade(int num, int user) {
        // If locked, then we cannot upgrade
        if(locked_by.find(num)!=locked_by.end()) {
            return false;
        }
        if(is_locked_child(num) && !is_locked_parent(p[num])) {
            unlock_descendants(num);
            locked_by[num] = user;
            return true;
        }
        return false;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */