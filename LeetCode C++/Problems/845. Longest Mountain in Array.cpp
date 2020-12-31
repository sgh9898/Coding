class Solution {
public:
    int longestMountain(vector<int>& A) {

        if(A.size() < 3){
            return 0;
        }

        int mountain = 0;

        for(int i=1;i<A.size()-1;i++){
            if(A[i] > A[i-1] && A[i] > A[i+1]){ //Possible Peak

				//Expanding on left
				int j = i-1;
                int left = 0;
                int prev = A[i];
                while(j >= 0 && A[j] < prev){
                    prev = A[j];
                    j--;
                    left++;
                }

                //Expanding on right
				j = i+1;
                prev = A[i];
                int right = 0;
                while(j < A.size() && A[j] <  prev){
                    prev = A[j];
                    j++;
                    right++;
                }

				//Store maximum in 'mountain'
                mountain = max(mountain, left+right+1);
            }
        }

        return mountain;
    }
};
