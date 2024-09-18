class Solution {
public:
    string largestNumber(vector<int>& nums) {

        sort(nums.begin(), nums.end(), 
            [](const int &a, const int &b) {
                auto const tens{[](const int &n) -> uint64_t {
                    return n == 0 ? 10 : pow(10, 1 + static_cast<int>(log10(n)));
                }};

                return (b * tens(a) + a) < (a * tens(b) + b);
            }
        );

        if (nums.empty() || nums[0] == 0) {
            return "0";
        }
        string res;
        for (auto const &n : nums) {
            res += to_string(n);
        }
        return res;
  }
};