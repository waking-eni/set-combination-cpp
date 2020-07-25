#include "combination.hpp"

int main()
{
    Set<int> s1, s2, s3(s1.getBr(),s1), s4(s2.getBr(),s2);

    s1.insert(10);
    s1.insert(3);
    s1.print();


    s2.insert(32);
    s2.insert(1);
    s2.insert(10);
    s2.print();

    std::cout << s3.getBr() << std::endl;
    s3.print();

    return 0;
}
