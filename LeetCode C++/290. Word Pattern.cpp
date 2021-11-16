class Solution {
public:
    bool wordPattern(string pattern, string s) {
    	// <letter, string>
    	unordered_map<char, string> match;
    	// strings bound to a pattern
    	unordered_set<string> saved;
    	stringstream sstream;
    	sstream << s;
    	string temp;
    	for (char ch : pattern) {
    		// has string
    		if (sstream >> temp) {
    			// insert new pairs
    			if (!match.count(ch) && !saved.count(temp)) {
    				match[ch] = temp;
    				saved.insert(temp);
    			// existing pairs
    			} else if (temp != match[ch]) {
				// doesn't match
    				return false;
    			}
    		} else {
    		// no string
    			return false;
    		}
    	}
    	// extra strings
    	if (sstream >> temp) {
    		return false;
    	} else {
    		return true;
    	}
    }
};