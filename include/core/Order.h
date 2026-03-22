#pragma once

#include <cstdint>
#include <string>

enum class OrderSide{
    BID,ASK
};

enum class OrderType{
    LIMIT,
    MARKET,
    // We have not implemented STOP and STOP_LIMIT orders as they are conditional orders they live in a seperate pending list, invisible to the order book, waiting for a trigger price.
    // STOP,
    // STOP_LIMIT,
    IOC,
    FOK
};

struct Order{
// We have created struct becuase all the elements in struct is public by default and we don't need to write public keyword again and again.

    std::int64_t order_id; // Unique identifier — monotonically increasing, assigned by the engine
    std::string symbol; // Instrument name e.g. "NIFTY50", "RELIANCE"
    OrderSide side; // Which side of the book this order belongs to
    OrderType type; // Execution behaviour of this order
    std::int64_t price; // Price in cents — $100.01 stored as 10001. Never float.
    std::uint64_t quantity; // Original order size requested by the trader
    std::uint64_t remaining_quantity; // Shares remaining after partial fills — starts equal to quantity 
    std::int64_t timestamp; // Arrival time in nanoseconds since epoch — used for price-time priority

// Constructor to initialize the order object    
    Order(std::uint64_t order_id
          ,const std::string& symbol
          ,OrderSide side
          ,OrderType type
          ,std::int64_t price
          ,std::uint64_t quantity
          ,std::int64_t timestamp)
        : order_id(order_id),
          symbol(symbol),
          side(side),
          type(type),
          price(price),
          quantity(quantity),
          remaining_quantity(quantity),
          timestamp(timestamp) {};

//  Helper function to check if the order is fully filled
    bool is_filled() const {
        return remaining_quantity == 0;
    }

    bool is_buy() const {
        return side == OrderSide::BID;
    }
};