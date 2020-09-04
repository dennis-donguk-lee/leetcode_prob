#include <string>         // std::string

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> ressult;
        vector<string> letVec;
        vector<string> digVec;

        // loop thru logs
        for (auto&& log : logs)
        {
            // find 1st space (string::find(' '))
            std::size_t found = 

            // determine whether let or dig

            // if dig
                // check identifier to sort
                    // push back to dig vec

            // if let
                // sort in lexicographical manner (std::lexicographical_compare(foo,foo+5,bar,bar+9))
                    // push back to let vec
        }

        // attach dig vec to let vec and assign to result

        // return result
    }
};
