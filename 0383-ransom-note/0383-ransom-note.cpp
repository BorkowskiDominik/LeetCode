class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
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
};