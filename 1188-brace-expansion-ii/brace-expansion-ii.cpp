class Solution {
public:
    int n, idx;
    string exp;
        set<string> performConcat() {
        set<string> result = {""};

        while (idx < n && (exp[idx] == '{' || isalpha(exp[idx]))) {
            auto sub = unit();
            set<string> concat;

            for (auto left : result) {
                for (auto right : sub) {
                    concat.insert(left + right);
                }
            }
            result = concat;
        }
        return result;
    }
    set<string> performUnion() {
        set<string> result;
        while (true) {
            auto temp = performConcat();
            result.insert(temp.begin(), temp.end());

            if (idx < n && exp[idx] == ',') idx++;
            else break;
        }
        return result;
    }

    set<string> unit() {
        set<string> result;
        if (idx < n && exp[idx] == '{') {
            idx++;
            result = performUnion();
            idx++;
        } else {
            result.insert(string(1, exp[idx]));
            idx++;
        }
        return result;
    }



    vector<string> braceExpansionII(string expression) {
        exp = expression;
        n = exp.size();
        idx = 0;

        auto ans = performUnion();
        return vector<string>(ans.begin(), ans.end());
    }
};