#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;
        int a = 0, b = 0;
        for (string s : tokens)
        {
            if (s == "+")
            {
                a = st.top();
                st.pop();
                b = st.top();
                st.pop();
                st.push(b + a);
            }
            else if (s == "-")
            {
                a = st.top();
                st.pop();
                b = st.top();
                st.pop();

                st.push(b - a);
            }
            else if (s == "*")
            {
                a = st.top();
                st.pop();
                b = st.top();
                st.pop();
                st.push(b * a);
            }
            else if (s == "/")
            {
                a = st.top();
                st.pop();
                b = st.top();
                st.pop();
                st.push(b / a);
            }
            else
            {
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};

class TestCases
{
public:
    void test(Solution s)
    {
        vector<string> tokens1 = {"2", "1", "+", "3", "*"};
        vector<string> tokens2 = {"4", "13", "5", "/", "+"};
        vector<string> tokens3 = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
        assert(s.evalRPN(tokens1) == 9);
        assert(s.evalRPN(tokens2) == 6);
        assert(s.evalRPN(tokens3) == 22);
        cout << "All test cases passed!" << endl;
    }
};

int main()
{
    Solution s;
    TestCases t;
    t.test(s);
}