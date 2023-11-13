class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> counts;

        // loads our target string into the map with +ve char counts.
        for(int i = 0; i < t.size(); i++){
            if (counts.find(t[i]) != counts.end()){
                counts[t[i]]++;
            }else{
                counts[t[i]] = 1;
            }
        }

        int i=0;
        int j=0;
        //counter tells us whether or not we have the entire string found
        int counter = t.size();

        int minstart = 0;
        int minlength = INT_MAX;

        while (j < s.size()){

            if (counts.find(s[j]) != counts.end()){
                // if we find a correct character 
                if (counts[s[j]] > 0)
                    counter--;
                counts[s[j]]--;
            }
            
            // we have the full string in our window
            while (counter == 0){
                int length = j-i+1;//window length
                
                if (length < minlength){
                    minstart = i;
                    minlength = length;
                }
            
                if (counts.find(s[i]) != counts.end()){
                    // add back the char we removed if important. 
                    if (++counts[s[i]] > 0)
                        counter++;
                }                    

                i++;
            }


            j++;

        }
        if (minlength != INT_MAX){
            return s.substr(minstart, minlength);
        }
        return "";


    }
};