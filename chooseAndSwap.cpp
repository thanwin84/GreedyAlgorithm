class Solution{
public:
    string chooseandswap(string a) {
        // Code Here
        set<char> s;
        for (int i = 0; i < a.size(); i++) {
            s.insert(a[i]);
        }
        for (int i = 0; i < a.size(); i++) {
            s.erase(a[i]);
            if (s.empty()) {
                break;
            }
            char ch = *s.begin();
            if (ch < a[i]) {
                int ch2 = a[i];
                for (int j = 0; j < a.size(); j++) {
                    if (a[j] == ch) a[j] = ch2;
                    else if (ch2 == a[j]) a[j] = ch;
                }
                break;
            }
        }
        return a;
    }

};
