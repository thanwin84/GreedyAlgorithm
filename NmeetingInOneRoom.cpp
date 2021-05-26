struct meeting {
    int start;
    int end;
    int pos;
};
bool comp(struct meeting m1, struct meeting m2) {
    if (m1.end < m2.end) return true;
    else if (m1.end > m2.end) return false;
    else if (m1.end == m2.end) {
        if (m1.pos < m2.pos) return true;
        else {
            return false;
        }
    }

}
class Solution
{
public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<meeting> meet;
        for (int i = 0; i < n; i++) {
            meeting mee;
            mee.start = start[i], mee.end = end[i], mee.pos = i;
            meet.push_back(mee);
        }
        sort(meet.begin(), meet.end(), comp);
        int counter = 0;
        int limit = meet[0].end;
        for (int i = 1; i < n; i++) {
            if (meet[i].end > limit) {
                counter++;
                limit = meet[i].end;
            }
        }
        return counter;
        
    }
};
