#include <iostream>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <map>
int main()
{
    date current, prev;
    int year, month, day;
    std::map<int, char[]> = {1, "Jan"}
    std::cin>>year>>month>>day;
    month *= -1;
    day *= -1;
    prev = date(year, month, day);

    while (std::cin>>year>>month>>day) {
        month *= -1;
        day *= -1;
        current = date(year, month, day);
        std::cout<<year<<' '<<month<<' '<<day<<std::endl;
    }
    return 0;
}
