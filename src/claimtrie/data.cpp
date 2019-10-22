
#include <data.h>
#include <log.h>

#include <algorithm>
#include <sstream>

#define logPrint CLogPrint::global()

CClaimValue::CClaimValue(CTxOutPoint outPoint, CUint160 claimId, int64_t nAmount, int nHeight, int nValidAtHeight)
    : outPoint(std::move(outPoint)), claimId(std::move(claimId)), nAmount(nAmount), nEffectiveAmount(nAmount), nHeight(nHeight), nValidAtHeight(nValidAtHeight)
{
}

bool CClaimValue::operator<(const CClaimValue& other) const
{
    if (nEffectiveAmount < other.nEffectiveAmount)
        return true;
    if (nEffectiveAmount != other.nEffectiveAmount)
        return false;
    if (nHeight > other.nHeight)
        return true;
    if (nHeight != other.nHeight)
        return false;
    return outPoint != other.outPoint && !(outPoint < other.outPoint);
}

bool CClaimValue::operator==(const CClaimValue& other) const
{
    return outPoint == other.outPoint && claimId == other.claimId && nAmount == other.nAmount && nHeight == other.nHeight && nValidAtHeight == other.nValidAtHeight;
}

bool CClaimValue::operator!=(const CClaimValue& other) const
{
    return !(*this == other);
}

std::string CClaimValue::ToString() const
{
    std::stringstream ss;
    ss  << "CClaimValue(" << outPoint.ToString()
        << ", " << claimId.ToString()
        << ", " << nAmount
        << ", " << nEffectiveAmount
        << ", " << nHeight
        << ", " << nValidAtHeight << ')';
    return ss.str();
}

CSupportValue::CSupportValue(CTxOutPoint outPoint, CUint160 supportedClaimId, int64_t nAmount, int nHeight, int nValidAtHeight)
    : outPoint(std::move(outPoint)), supportedClaimId(std::move(supportedClaimId)), nAmount(nAmount), nHeight(nHeight), nValidAtHeight(nValidAtHeight)
{
}

bool CSupportValue::operator==(const CSupportValue& other) const
{
    return outPoint == other.outPoint && supportedClaimId == other.supportedClaimId && nAmount == other.nAmount && nHeight == other.nHeight && nValidAtHeight == other.nValidAtHeight;
}

bool CSupportValue::operator!=(const CSupportValue& other) const
{
    return !(*this == other);
}

std::string CSupportValue::ToString() const
{
    std::stringstream ss;
    ss  << "CSupportValue(" << outPoint.ToString()
        << ", " << supportedClaimId.ToString()
        << ", " << nAmount
        << ", " << nHeight
        << ", " << nValidAtHeight << ')';
    return ss.str();
}

CNameOutPointHeightType::CNameOutPointHeightType(std::string name, CTxOutPoint outPoint, int nValidHeight)
    : name(std::move(name)), outPoint(std::move(outPoint)), nValidHeight(nValidHeight)
{
}

CClaimIndexElement::CClaimIndexElement(std::string name, CClaimValue claim)
    : name(std::move(name)), claim(std::move(claim))
{
}
