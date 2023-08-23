// 1ST APPROACH
//  ***********USING MAP ***********
class Solution
{
public:
    string reorganizeString(string s)
    {
        map<char, int> freqMap; // Using std::map instead of std::unordered_map
        int n = s.length();
        for (char c : s)
        {
            freqMap[c]++;
        }

        string ans = "";
        char prevChar = ' '; // To track the previously added character

        while (!freqMap.empty())
        {
            char mostFreqChar = ' ';
            int mostFreqCount = 0;

            for (auto it = freqMap.begin(); it != freqMap.end(); ++it)
            {
                if (it->second > mostFreqCount && it->first != prevChar)
                {
                    mostFreqCount = it->second;
                    mostFreqChar = it->first;
                }
            }

            if (mostFreqChar == ' ')
            {
                break;
            }

            ans += mostFreqChar;
            prevChar = mostFreqChar; // Update the previous character
            freqMap[mostFreqChar]--;

            if (freqMap[mostFreqChar] == 0)
            {
                freqMap.erase(mostFreqChar);
            }
        }

        for (auto it = freqMap.begin(); it != freqMap.end(); ++it)
        {
            if (it->second > 0)
            {
                return ""; // If any character cannot be reorganized
            }
        }

        return ans;
    }
};

// 2ND APPROACH
//*********** USING PRIORITY QUEUE ***********
class Solution
{
public:
    string reorganizeString(string s)
    {
        unordered_map<char, int> mp;
        int n = s.length();
        for (char c : s)
        {
            mp[c]++;
        }

        priority_queue<pair<int, char>> pq; // Max heap

        for (auto it = mp.begin(); it != mp.end(); ++it)
        {
            pq.push({it->second, it->first});
        }

        string ans = "";

        while (!pq.empty())
        {
            auto first = pq.top();
            pq.pop();

            if (ans.empty() || first.second != ans.back())
            {
                ans += first.second;
                if (--first.first > 0)
                {
                    pq.push(first);
                }
            }
            else
            {
                if (pq.empty())
                {
                    return "";
                }
                auto second = pq.top();
                pq.pop();
                ans += second.second;
                if (--second.first > 0)
                {
                    pq.push(second);
                }
                pq.push(first); // Put the first character back to the heap
            }
        }

        return ans;
    }
};