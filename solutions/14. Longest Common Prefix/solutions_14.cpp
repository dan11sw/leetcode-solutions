#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if (strs.empty()) {
            return "";
        }
        else if (strs.size() == 1) {
            return strs.front();
        }

        std::string cPref = "";
        const std::string& target = strs.at(0);
        const std::size_t sizeStrs = strs.size();

        for (int i = 0; i < target.size(); i++) {
            const char& symbol = target.at(i);
            bool checkAll = true;

            for (int j = 1; j < sizeStrs; j++) {
                const std::string& str = strs.at(j);

                if ((str.size() <= i) || (str.at(i) != symbol)) {
                    checkAll = false;
                    break;
                }
            }

            if (checkAll) {
                cPref = cPref + symbol;
            }
            else {
                break;
            }
        }

        return cPref;
    }
};

int main()
{
    std::vector<std::string> strs{
       "cir","car"
    };

    Solution sol;
    std::cout << sol.longestCommonPrefix(strs) << std::endl;

    system("PAUSE");
    return 0;
}
