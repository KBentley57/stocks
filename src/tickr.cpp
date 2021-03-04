#include <stock/tickr.hpp>
#include <numeric>
#include <iomanip>
#include <sstream>


stock::time_stamp::time_stamp(const std::string& time_string) {
    std::istringstream iss(time_string);
    
}

std::ostream& 
operator<<(std::ostream& os, const stock::time_stamp& ts) {
/*
    os << ts.year << '/' << ts.month << '/' << ts.day << ' ' 
       << ts.hours << ':' << ts.minutes << ':' << ts.seconds;
*/
    return os;

}

stock::tick::tick(stock::time_stamp ts, float O, float H, float L, float C)
 : time(ts), open(O), high(H), low(L), close(C) {
    
}

std::ostream& 
operator<<(std::ostream& os, const stock::tick& t) {
    os << t.time << " " << t.open << " " << t.high << " " << t.low << " " << t.close;
    return os;
}

stock::ticker::ticker(const std::string& Symbol)
 : symbol(Symbol), history{} {
 
}

std::ostream& 
operator<<(std::ostream& os, const stock::ticker& t) {
    os << t.symbol << " -- \n";
    for(const auto& tr : t.history) {
        os << "  " << tr << '\n';
    }
    return os;
}

void
stock::ticker::ticker::add_tick(stock::tick&& t) {
    history.emplace_back(t);
}

float 
stock::ticker::mean() const {
    float mean{};
    for(const tick& t : history) {
        mean += (t.open + t.close)/2;
    }
    mean /= history.size();
    return mean;
}
