#include <iostream>
#include <vector>

void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
{
    std::vector<int> temp(m + n);
    int index1 = 0;
    int index2 = 0;
    int index3 = 0;

    while(index1 < m && index2 < n)
    {
        if(nums1[index1] <= nums2[index2])
        {
            temp[index3] = nums1[index1];
            index1++;
        }
        else
        {
            temp[index3] = nums2[index2];
            index2++;
        }
        index3++;
    }

    while(index1 < m)
    {
        temp[index3] = nums1[index1];
        index1++;
        index3++;
    }
    while(index2 < n)
    {
        temp[index3] = nums2[index2];
        index2++;
        index3++;
    }

    for(int i = 0; i < m + n; i++)
    {
        nums1[i] = temp[i];
    }
}

void print_vector(std::vector<int>& vec, int length)
{
    for(int i = 0; i < length; i++)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << "\n";
}


int main()
{
    std::vector<int> nums1, nums2;
    nums1.push_back(1);
    nums1.push_back(2);
    nums1.push_back(3);
    nums1.push_back(0);
    nums1.push_back(0);
    nums1.push_back(0);

    nums2.push_back(2);
    nums2.push_back(5);
    nums2.push_back(6);

    print_vector(nums1, 3);
    print_vector(nums2, 3);

    merge(nums1, 3, nums2, 3);
    print_vector(nums1, 6);




    return 0;
}
