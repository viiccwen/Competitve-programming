class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size()) {
      swap(nums1, nums2);
    }

    int m = nums1.size();
    int n = nums2.size();
    int low = 0, high = m;

    while (low <= high) {
      int partitionX = (low + high) / 2;
      int partitionY = (m + n + 1) / 2 - partitionX;

      int maxX = (!partitionX) ? INT_MIN : nums1[partitionX - 1];
      int maxY = (!partitionY) ? INT_MIN : nums2[partitionY - 1];

      int minX = (partitionX == m) ? INT_MAX : nums1[partitionX];
      int minY = (partitionY == n) ? INT_MAX : nums2[partitionY];

      if (maxX <= minY && maxY <= minX) {
        if ((m + n) % 2 == 0)
          return (max(maxX, maxY) + min(minX, minY)) / 2.0;
        else
          return max(maxX, maxY);
      } else if (maxX > minY)
        high = partitionX - 1;
      else
        low = partitionX + 1;
    }

    return -1;
  }
};

/*

brute force
time complexity - O(log(min(len1, len2)))
space complexity - O(len1 + len2) = O(n)

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        int idx1 = 0, idx2 = 0;
        vector<int> merge(nums1.size() + nums2.size());

        for(int i=0;i<merge.size();i++) {
            if(idx2 != len2 && (idx1 == len1 || nums2[idx2] < nums1[idx1]) )
merge[i] = nums2[idx2++]; else merge[i] = nums1[idx1++];
        }

        int len3 = merge.size();
        if(len3 % 2) return merge[len3 / 2];
        else return (merge[len3 / 2] + merge[len3 / 2 - 1]) / 2.0;
    }
};
*/