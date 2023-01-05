#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string getHint(string secret, string guess)
    {
        // find number of bulls:
        int bulls = 0, cows = 0;
        for (int i = 0; i < secret.length(); i++)
        {
            if (secret[i] == guess[i])
            {
                bulls++;
                secret[i] = '-';
                guess[i] = '-';
            }
        }
        // find number of cows
        // make frequencey map
        unordered_map<char, int> fq;
        for (char c : secret)
        {
            fq[c]++;
        }
        // count cows
        for (int i = 0; i < secret.length(); i++)
        {
            if (secret[i] != '-' and fq[guess[i]] > 0)
            {
                cows++;
                fq[guess[i]]--;
            }
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};

class TestCase
{
    vector<vector<string>> test_cases;

public:
    TestCase()
    {
        test_cases = {
            {"1807", "7810", "1A3B"},
            {"1123", "0111", "1A1B"},
            {"1122", "1222", "3A0B"},
            {"1122", "2211", "0A4B"},
            {"4214", "4214", "4A0B"},
        };
    }

    void test(Solution s)
    {
        for (auto test_case : test_cases)
        {
            if (s.getHint(test_case[0], test_case[1]) != test_case[2])
            {
                cout << "Test case failed!" << endl;
                cout << "Expected: " << test_case[2] << endl;
                cout << "Got: " << s.getHint(test_case[0], test_case[1]) << endl;
                return;
            }
        }

        cout << "All test cases passed successfully!" << endl;
    }
};

int main()
{
    Solution s;
    TestCase t;
    t.test(s);
}