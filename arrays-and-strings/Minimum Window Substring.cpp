class Solution {
public:
    bool equals(vector<int>& map, vector<int>& tmap)
    {
        for (int i = 0; i < map.size(); i++) {
            if (map[i] < tmap[i]) {
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t)
    {
        if (s.size() < 1 || t.size() < 1) {
            return "";
        }

        vector<int> map(128, 0);
        vector<int> tmap(128, 0);

        for (int i = 0; i < t.size(); i++) {
            tmap[t[i]]++;
        }

        int l = 0, r = 0;
        int minSize = INT_MAX;
        int startingIndex = l, finalIndex = r;

        while (l <= r && r <= s.size()) {
            if (equals(map, tmap)) {

                if (minSize > r - l) {
                    minSize = r - l;
                    startingIndex = l;
                }
                map[s[l]]--;
                l++;
            }
            else {
                map[s[r++]]++;
            }
        }

        if (minSize == INT_MAX) {
            return "";
        }
        return s.substr(startingIndex, minSize);
    }
};