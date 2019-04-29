class Solution {
    void reverseBits(uint8_t &n) {
        uint8_t bit0 = n & 1;
        uint8_t bit1 = n & 2;
        uint8_t bit2 = n & 4;
        uint8_t bit3 = n & 8;
        uint8_t bit4 = n & 16;
        uint8_t bit5 = n & 32;
        uint8_t bit6 = n & 64;
        uint8_t bit7 = n & 128;
        n = (bit7 >> 7) | (bit6 >> 5) | (bit5 >> 3) | (bit4 >> 1) |
            (bit3 << 1) | (bit2 << 3) | (bit1 << 5) | (bit0 << 7);
        
    }
public:
    uint32_t reverseBits(uint32_t n) {
        uint8_t *bytes = (uint8_t *)&n;
        reverseBits(bytes[0]);
        reverseBits(bytes[1]);
        reverseBits(bytes[2]);
        reverseBits(bytes[3]);
        swap(bytes[0], bytes[3]);
        swap(bytes[1], bytes[2]);
        
        return n;
    }
};