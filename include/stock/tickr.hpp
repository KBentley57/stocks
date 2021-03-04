#ifndef TICKR_HPP
#define TICKR_HPP

#include <ctime>
#include <vector>
#include <cstdint>
#include <string>
#include <iostream>

namespace stock {

struct time_stamp {
    time_stamp() = default;
    time_stamp(const std::string& time_string);
    time_stamp(const time_stamp& ) = default;
    time_stamp(time_stamp&& ) = default;
    virtual ~time_stamp() = default;
    
    time_stamp& operator=(const time_stamp& ) = default;
    time_stamp& operator=(time_stamp&& ) = default;
    
    std::tm t;
}; // 5 bytes

struct tick {

    tick() = default;
    tick(time_stamp, float, float, float, float);
    tick(const tick& ) = default;
    tick(tick&& ) = default;
    virtual ~tick() = default;
    
    tick& operator=(const tick& ) = default;
    tick& operator=(tick&& ) = default;

    time_stamp time;
    float open;
    float high;
    float low;
    float close;
}; // 21 bytes

struct ticker {

    ticker() = default;
    ticker(const std::string& Symbol);
    ticker(const ticker& ) = default;
    ticker(ticker&& ) = default;
    virtual ~ticker() = default;
    
    ticker& operator=(const ticker& ) = default;
    ticker& operator=(ticker&& ) = default;

    using history_t = std::vector<tick>;
    
    void add_tick(tick&& );
    
    float mean() const;
    float mean(const time_stamp& t0, const time_stamp& t1) const;
    
    std::string symbol;
    history_t history;
    
};

}

std::ostream& operator<<(std::ostream& os, const stock::time_stamp& ts);

std::ostream& operator<<(std::ostream& os, const stock::tick& t);

std::ostream& operator<<(std::ostream& os, const stock::ticker& t);

#endif
