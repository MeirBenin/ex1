

#include <iosfwd>
#pragma once

class Pixel{
public:
    Pixel(unsigned char pixel = ' ');
    unsigned char getColor ()const;
    void operator |= (const Pixel& rhs);
    void operator &= (const Pixel& rhs);
private:
    unsigned char m_color;
};



\
bool operator == (const Pixel& lhs, const Pixel& rhs);
bool operator != (const Pixel& lhs, const Pixel& rhs);
std::ostream& operator<< (std::ostream&, const Pixel&);
Pixel operator | (const Pixel& lhs, const Pixel& rhs);
Pixel operator & (const Pixel& lhs, const Pixel& rhs);


