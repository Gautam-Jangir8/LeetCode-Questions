class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        deque<int>dq;
        for(int i=0; i<students.size(); i++) {
            dq.push_back(students[i]);
        }

        int i=0;// pointing to sandwich
        int cnt = 0;
        while(i<sandwiches.size()) {
            if(cnt>dq.size()) {
                return dq.size();
            }
            if(dq.front()==sandwiches[i]) {
                cnt = 0;
                i++;
                dq.pop_front();
            } else {
                dq.push_back(dq.front());
                dq.pop_front();
            }
            cnt++;
        }

        return dq.size();
    }
};