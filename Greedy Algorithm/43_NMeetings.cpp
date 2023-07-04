class Solution
{
private:
    static bool cmp(pair<int, int> a, pair<int, int> b)
    {
        return (a.second < b.second);
    }

public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int, int>> meet;
        for (int i = 0; i < n; i++)
            meet.push_back(make_pair(start[i], end[i]));
        sort(meet.begin(), meet.end(), cmp);
        int count = 1;
        int ansEnd = meet[0].second;
        for (int i = 1; i < n; i++)
        {
            if (meet[i].first > ansEnd)
            {
                count++;
                ansEnd = meet[i].second;
            }
        }
        return count;
    }
};