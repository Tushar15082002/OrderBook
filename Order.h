#ifndef ORDER
#define ORDER

#include <list>
#include <exception>
#include <format>

#include "Side.h"
#include "Usings.h"
#include "OrderType.h"

class Order {
private:
    OrderType orderType_;
    OrderId orderId_;
    Side side_;
    Price price_;
    Quantity initial_quantity_;
    Quantity remaining_quantity_;

public:
    Order(OrderType orderType, OrderId orderId, Side side, Price price, Quantity quantity) :
        orderType_{orderType},
        orderId_{orderId},
        side_{side},
        price_{price},
        initial_quantity_{quantity},
        remaining_quantity_{quantity}
    {}

    OrderId GetOrderId() const {return orderId_;}
    Side GetSide() const {return side_;}
    Price GetPrice() const {return price_;}
    OrderType GetOrderType() const {return orderType_;}
    Quantity GetInitialQuantity() const {return initial_quantity_;}
    Quantity GetRemainingQuantity() const {return remaining_quantity_;}
    Quantity GetFilledQuantity() const {return initial_quantity_ - remaining_quantity_;}
    bool isFilled() const {return GetRemainingQuantity() == 0;}

    void Fill(Quantity quantity) {
        if(quantity > GetRemainingQuantity()) {
            throw std::logic_error(std::format("Order ({}) cannot be filled for more than its remaining quantity", GetOrderId()));
        }

        remaining_quantity_ -= quantity;
    }
};

using OrderPointer = std::shared_ptr<Order>;
using OrderPointers = std::list<OrderPointer>;

#endif