class Solution {
public:

    int Sum(int num) {
        int sum = 0;

        while (num > 0) {
            int dig = num % 10;
            sum += dig * dig;
            num /= 10;
        }

        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> st;

        while (n != 1) {
            n = Sum(n);

            if (st.find(n) != st.end()) {
                return false;
            }

            st.insert(n);
        }

        return true;
    }
};
