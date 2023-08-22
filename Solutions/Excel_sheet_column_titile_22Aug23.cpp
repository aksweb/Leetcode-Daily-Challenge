class Solution
{
public:
    string convertToTitle(int columnNumber)
    {

        string s;
        long long n = columnNumber;

        while (n > 0)
        {
            n--;
            char ch = char('A' + n % 26);
            n /= 26;
            s += ch;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};