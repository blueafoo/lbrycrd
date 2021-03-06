
#ifndef CLAIMTRIE_UINTS_H
#define CLAIMTRIE_UINTS_H

#include <blob.h>
#include <string>

#include <primitives/robin_hood.h>

class uint160 : public CBaseBlob<160>
{
public:
    uint160() = default;

    explicit uint160(const std::vector<uint8_t>& vec);

    uint160(uint160&&) = default;
    uint160& operator=(uint160&&) = default;

    uint160(const uint160&) = default;
    uint160& operator=(const uint160&) = default;
};

class uint256 : public CBaseBlob<256>
{
public:
    uint256() = default;

    explicit uint256(const std::vector<uint8_t>& vec);
    explicit uint256(int64_t value);

    uint256(uint256&&) = default;
    uint256& operator=(uint256&&) = default;

    uint256(const uint256&) = default;
    uint256& operator=(const uint256&) = default;
};

uint160 uint160S(const char* str);
uint160 uint160S(const std::string& s);

uint256 uint256S(const char* str);
uint256 uint256S(const std::string& s);

namespace std {

    template <>
    struct hash<uint160>
    {
        size_t operator()(const uint160& k) const
        {
            return robin_hood::hash_bytes(k.begin(), k.size());
        }
    };

    template <>
    struct hash<uint256>
    {
        size_t operator()(const uint256& k) const
        {
            return robin_hood::hash_bytes(k.begin(), k.size());
        }
    };
}


#endif // CLAIMTRIE_UINTS_H
