class Solution {
public:
    int reverseBits(int n) {
        uint32_t unsignedN = static_cast<uint32_t>(n);
        uint32_t result = 0;

        for (int i = 0; i < 32; ++i) {
            result = (result << 1) | (unsignedN & 1);
            unsignedN >>= 1;
        }

        return result;
    }
};

