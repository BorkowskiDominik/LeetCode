class Solution {
public:
    // first attempt (first idea) to solve the issue
    bool canConstruct_first_attempt(string ransomNote, string magazine) {
        sort(ransomNote.begin(), ransomNote.end());
        sort(magazine.begin(), magazine.end());
        
        int r_pos = 0, m_pos = 0;
        
        while(r_pos != ransomNote.size()) {
            if (magazine[m_pos] > ransomNote[r_pos])
                return false;
            m_pos = magazine.find(ransomNote[r_pos], m_pos);
            if (m_pos == std::string::npos)
                return false;
            m_pos++;
            r_pos++;
        }

        return true;
    }

    // optimal issue
    bool canConstruct(string ransomNote, string magazine) {
        int freqency[26] = {}; // array to count occurences only english letters possible 
        for (char c : magazine) 
            freqency[c - 'a']++;
        for (char c: ransomNote)
            if (--freqency[c - 'a'] < 0) 
                return false;

        return true;
    }
};