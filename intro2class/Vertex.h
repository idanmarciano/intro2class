#pragma once

struct Vertex
{
    double m_x;
    double m_y;

    bool isHigherFrom(const Vertex& rhs) const;
    bool isRighterFrom(const Vertex& tr) const;
    bool isValid() const;
};
bool check_parll(double,double,double) ;
