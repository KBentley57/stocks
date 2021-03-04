#include <stock/tickr.hpp>
#include <iostream>
#include <sstream>
#include <locale>
#include <iomanip>

int main(int argc, char** argv) {

    stock::ticker STOCK("AAPL");
    
    int count{};
/*
    for(int year = 2021; year < 2022; ++year) {
        for(int month = 3; month < 4; ++month) {
            for(int day = 1; day < 4; ++day) {
                for(int hour = 9; hour < 15; ++hour) {
                    for(int min = 0; min < 60; ++min) {
                    
                        int sec = 0;
                        
                        stock::time_stamp t(year,month,day,hour,min,sec);
                        stock::tick tick(t, 1.0, 1.0, 1.0, 1.0);
                       
                        
                        STOCK.add_tick(std::move(tick));                        
                        ++count;
                    }
                }
            }
        }
    }

    std::cout<< STOCK << '\n';
    std::cout<< "Count = " << count << " The mean over the whole time is = " << STOCK.mean() <<'\n';
*/

    std::string test_string{"02/25/2021	9:30 AM"};
    
    std::tm t = {};
//    std::istringstream ss("2011-February-18 23:12:34");
    std::istringstream ss(test_string);
    ss.imbue(std::locale("en_US.utf-8"));
    ss >> std::get_time(&t, "%d/%m/%Y %I:%M %p");
    if (ss.fail()) {
        std::cout << "Parse failed\n";
    } else {
        std::cout << std::put_time(&t, "%c") << '\n';
    }

    return 0;
}
