#ifndef LEVELINFO
#define LEVELINFO

#include "Usings.h"

struct LevelInfo
{
    Price price_;
    Quantity quantity_;
};

using LevelInfos = std::vector<LevelInfo>;

#endif