#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <cstdint>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row;
        row.reserve(rowIndex + 1);

        int val = 1;
        for (int k = 0; k <= rowIndex; ++k) {
            row.push_back(val);
            val = static_cast<int>(((int64_t)val * (int64_t)(rowIndex - k)) / (int64_t)(k + 1));
        }

        return row;
    }
};

int main()
{
    Solution sol;
    vector<int> triangle = sol.getRow(30);

    for (const auto& item : triangle) {
        std::cout << item << " ";
    }

    system("PAUSE");
    return 0;
}
