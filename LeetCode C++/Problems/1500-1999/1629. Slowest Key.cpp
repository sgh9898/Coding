class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
    	char key = keysPressed[0];
    	int duration = releaseTimes[0];

    	for (int i = 1; i < releaseTimes.size(); i++) {
    		char temp_key = keysPressed[i];
    		int temp_duration = releaseTimes[i] - releaseTimes[i - 1];

    		if (temp_duration > duration || (temp_duration == duration && temp_key > key)) {
    			duration = temp_duration;
    			key = temp_key;
    		}
    	}
    	return key;
    }
};