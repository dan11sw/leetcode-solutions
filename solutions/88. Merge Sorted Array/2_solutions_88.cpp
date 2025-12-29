#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        if (m == 0) {
            nums1 = nums2;
            return;
        }
        else if (n == 0) {
            return;
        }

        std::vector<int> nums3;
        nums3.reserve(m + n);

        // Two pointers method
        std::vector<int>::iterator iter1 = nums1.begin();
        std::vector<int>::iterator iter2 = nums2.begin();

        while ((iter1 != (nums1.end() - n)) && (iter2 != nums2.end())) {
            if ((*iter1) < (*iter2)) {
                nums3.push_back((*iter1));
                iter1++;
            }
            else if ((*iter1) > (*iter2)) {
                nums3.push_back((*iter2));
                iter2++;
            }
            else {
                nums3.push_back((*iter1));
                nums3.push_back((*iter2));
                iter1++;
                iter2++;
            }
        }

        while (iter1 != (nums1.end() - n)) {
            nums3.push_back((*iter1));
            iter1++;
        }

        while (iter2 != nums2.end()) {
            nums3.push_back((*iter2));
            iter2++;
        }

        nums1 = nums3;
    }
};

int main()
{
    std::vector<int> vec1{
        0,0,3,0,0,0,0,0,0
    };

    std::vector<int> vec2{
        -1,1,1,1,2,3
    };

    Solution sol;
    sol.merge(vec1, 3, vec2, 6);

    for (const auto& item : vec1) {
        std::cout << item << " ";
    }

    std::cout << std::endl;

    system("PAUSE");
    return 0;
}
