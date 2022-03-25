class Solution {
public:
    string pushDominoes(string dominoes) {

    	// initialization
    	int lt_idx = 0, rt_idx = -1;
    	char lt_mark = 'L', rt_mark;

    	// find dominoes has been pushed
    	for (int i = 0; i < dominoes.size(); i++) {
    		if (dominoes[i] == 'L' || dominoes[i] == 'R') {
    			rt_idx = i;
    			rt_mark = dominoes[i];

    			// LL or RR
    			if (lt_mark == rt_mark) {
    				for (int i = lt_idx; i < rt_idx; i++) {
    					dominoes[i] = lt_mark;
    				}
    			}
    			// RL, no need to push if LR
    			else if (lt_mark == 'R' && rt_mark == 'L') {
    				int lt = lt_idx, rt = rt_idx;
    				while (lt < rt) {
	    				dominoes[lt] = 'R';
	    				dominoes[rt] = 'L';
	    				lt++;
	    				rt--;
    				}
    			}

    			lt_idx = rt_idx;
    			lt_mark = rt_mark;
    		}
    	}

    	// check if the last marked domino is falling to the right
    	if (rt_mark == 'R') {
    		for (int i = rt_idx; i < dominoes.size(); i++) {
    			dominoes[i] = 'R';
    		}
    	}
    	return dominoes;
    }
};