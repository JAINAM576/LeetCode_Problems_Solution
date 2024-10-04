class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long sum = 0;
        unordered_map<int, int> mp;
        int n = skill.size();
        for (auto it : skill) {
            mp[it]++;
            sum += it;
        }
        int rem = sum % (n / 2);
        int q = sum / (n / 2);

        if (rem != 0)
            return -1;
        long long prod = 0;
        for (int i = 0; i < n; i++) {
            int cur = skill[i];
            if (mp[cur] <= 0)
                continue;
            if (cur == (q - cur)) {
                if (mp[cur] >= 2) {

                    prod = prod + (cur * (q - cur));
                    mp[q - cur]--;
                    mp[cur]--;
                    continue;
                } else {
                    return -1;
                }
            }

            if (mp.find(q - cur) != mp.end() && mp[q - cur] > 0) {
                prod = prod + (cur * (q - cur));
                mp[q - cur]--;
                mp[cur]--;
            } else {
                cout << "in not equal" << endl;

                return -1;
            }
        }
        return prod;
    }
};
