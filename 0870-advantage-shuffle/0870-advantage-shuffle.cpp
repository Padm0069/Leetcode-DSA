class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        multiset<int> s(begin(nums1), end(nums1));
  for (auto i = 0; i < nums2.size(); ++i) {
    auto p =  s.upper_bound(nums2[i]);
    if(p == s.end()) p =s.begin();
    nums1[i] = *p;
    s.erase(p);
  }
  return nums1;
    }
};