#include <iostream>
#include <vector>
#include <string>

class flat
{
private:
    double price;
    double area;
public:
    flat() : price(0), area(0) { };
    flat(const double& prc, const double& area) : price(prc), area(area) { };
    flat(const flat& date) : price(date.price), area(date.area) { };
    ~flat() { };
    flat& operator = (const flat& date);

    friend bool operator == (const flat& lhs, const flat& rhs);
    friend bool operator != (const flat& lhs, const flat& rhs);

    friend bool operator > (const flat& lhs, const flat& rhs);
    friend bool operator < (const flat& lhs, const flat& rhs);
};

flat& flat::operator = (const flat& date)
{
    if (this == &date)
    {
        return *this;
    }

    price = date.price;
    area = date.area;
    return *this;
}

bool operator == (const flat& lhs, const flat& rhs)
{
    return lhs.area == rhs.area;
}

bool operator != (const flat& lhs, const flat& rhs)
{
    return !(lhs.area == rhs.area);
}

bool operator > (const flat& lhs, const flat& rhs)
{
    return lhs.price > rhs.price;
}

bool operator < (const flat& lhs, const flat& rhs)
{
    return lhs.price < rhs.price;
}

int main() {
	setlocale(LC_ALL, "Russian");

    flat f1(47000, 40);
    flat f2(50000, 70);
    flat f3;

    if (f1 == f2) {
       std::cout << " вартиры равны по площади" << std::endl;
    }
    else {
        std::cout << " вартиры не равны по площади" << std::endl;
    }

    f3 = f2;

    if (f1 > f2) {
        std::cout << " вартира f1 дороже" << std::endl;
    }
    else
    {
        std::cout << " вартира f1 дешевле" << std::endl;
    }

	return 0;
}