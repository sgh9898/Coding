class Node{
public:
    int key,val,freq;

    Node(int k,int v,int f) {
        key = k;
        val = v;
        freq = f;
    }
};

class LFUCache {
private:
    int capacity;
    int min_freq;
    unordered_map<int,list<Node>::iterator> cache_iter;
    unordered_map<int,list<Node>> freq_list;

public:
    LFUCache(int cpty) {
        capacity = cpty;
        min_freq = 0;
    }

    int get(int key) {
        if (capacity == 0) return -1;
        auto iter = cache_iter.find(key);
        if (iter == cache_iter.end()) return -1;  //not found

        // update existing Node
        int val = iter->second->val;
        int prev_freq = iter->second->freq;

        freq_list[prev_freq].erase(iter->second);

        // update min_freq
        if (freq_list[prev_freq].empty() && prev_freq == min_freq) {
            min_freq++;
        }

        // insert node to the front of the list
        freq_list[prev_freq+1].push_front(Node(key,val,prev_freq+1));
        cache_iter[key] = freq_list[prev_freq+1].begin();
        return val;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        auto iter = cache_iter.find(key);

        // add new node
        if (iter == cache_iter.end()) {
            // delete previous node if reaches the limit
            if (cache_iter.size() == capacity) {
                int key_to_evict = freq_list[min_freq].back().key;
                freq_list[min_freq].pop_back();
                if (freq_list[min_freq].size() == 0) {
                    min_freq++;
                }
                cache_iter.erase(key_to_evict);
            }

            freq_list[1].push_front(Node(key,value,1));
            min_freq = 1;
            cache_iter[key] = freq_list[1].begin();
        } else {
        // update existing Node
            const int prev_freq = iter->second->freq;

            freq_list[prev_freq].erase(iter->second);

            // update min_freq
            if (freq_list[prev_freq].empty() && prev_freq == min_freq) {
                min_freq++;
            }

            // insert node to the front of the list
            freq_list[prev_freq+1].push_front(Node(key,value,prev_freq+1));
            cache_iter[key] = freq_list[prev_freq+1].begin();
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
