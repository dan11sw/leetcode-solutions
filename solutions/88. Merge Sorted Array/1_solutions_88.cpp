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

        // Three pointers method
        std::vector<int>::iterator iter1 = nums1.begin() + (m - 1);
        std::vector<int>::iterator iter2 = nums2.begin() + (n - 1);
        std::vector<int>::iterator iter3 = nums1.begin() + ((m + n) - 1);

        while ((iter1 != nums1.end()) && (iter2 != nums2.end())) {
            if ((*iter1) > (*iter2)) {
                (*iter3) = (*iter1);

                if (iter1 == nums1.begin()) {
                    iter1 = nums1.end();
                }
                else {
                    iter1--;
                }

                if (iter3 != nums1.begin()) {
                    iter3--;
                }
            }
            else if ((*iter2) > (*iter1)) {
                (*iter3) = (*iter2);

                if (iter2 == nums2.begin()) {
                    iter2 = nums2.end();
                }
                else {
                    iter2--;
                }

                if (iter3 != nums1.begin()) {
                    iter3--;
                }
            }
            else {
                (*iter3) = (*iter1);

                if (iter1 == nums1.begin()) {
                    iter1 = nums1.end();
                }
                else {
                    iter1--;
                }

                if (iter3 != nums1.begin()) {
                    iter3--;
                }

                (*iter3) = (*iter2);

                if (iter2 == nums2.begin()) {
                    iter2 = nums2.end();
                }
                else {
                    iter2--;
                }

                if (iter3 != nums1.begin()) {
                    iter3--;
                }
            }
        }

        while (iter2 != nums2.end()) {
            (*iter3) = (*iter2);

            if (iter2 == nums2.begin()) {
                iter2 = nums2.end();
            }
            else {
                iter2--;
            }

            if (iter3 != nums1.begin()) {
                iter3--;
            }
        }
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
