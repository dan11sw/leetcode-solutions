#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <cstdint>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        result.reserve(numRows);

        result.push_back(vector<int>{1});
        if (numRows == 1) {
            return result;
        }

        result.push_back(vector<int>{1, 1});

        for (std::size_t i = 2; i < numRows; i++) {
            vector<int> value;
            value.resize(i + 1, 1);

            value[0] = 1;
            value[i] = 1;

            const auto& linkToBack = result.at(i - 1);
            for (std::size_t j = 1; j < i; j++) {
                value[j] = linkToBack[j - 1] + linkToBack[j];
            }

            result.push_back(value);
        }

        return result;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> triangle = sol.generate(5);

    for (const auto& item : triangle) {
        for (const auto& subItem : item) {
            std::cout << subItem << " ";
        }

        std::cout << std::endl;
    }

    system("PAUSE");
    return 0;
}
