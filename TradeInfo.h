#ifndef TRADEINFO
#define TRADEINFO

#include "Usings.h"

struct TradeInfo
{
    OrderId orderId_;
    Price price_;
    Quantity quantity_;
};

#endif