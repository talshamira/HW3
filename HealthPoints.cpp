#include "HealthPoints.h"

//--------------------------------------------- Member Functions -------------------------------------------------------

//constructor
HealthPoints::HealthPoints(const int maxPoints)
{
    if(maxPoints <= 0)
    {
        throw(HealthPoints::InvalidArgument);
    }
    this->m_maxHealthPoints = maxPoints;
    this->m_healthPoints = maxPoints;
}

// operator -=
HealthPoints& HealthPoints::operator-=(const int health)
{
    if(health < 0)
    {
        return *this;
    }
    if(health > m_healthPoints)
    {
        m_healthPoints = 0;
    }
    else
    {
        m_healthPoints -=health;
    }
    return *this;
}


//operator - 
HealthPoints HealthPoints::operator-(const int health)
{
    if(health <=0)
    {
        return *this;
    }
    HealthPoints result(*this);
    return result-=health;
}

// operator +=
HealthPoints& HealthPoints::operator+=(const int health)
{
    if(health <=0)
    {
        return *this;
    }
    this->m_healthPoints +=health;
    if(this->m_healthPoints > this->m_maxHealthPoints)
    {
        this->m_healthPoints = this->m_maxHealthPoints;
    }
    return *this;
}

//---------------------------------------------- Friend Functions ------------------------------------------------------

// operator <
bool operator<(const HealthPoints& a, const HealthPoints& b)
{
    return a.m_healthPoints < b.m_healthPoints;
}

// operator <<
std::ostream& operator<<(std::ostream& os,HealthPoints health)
{
    return os << health.m_healthPoints << "(" << health.m_maxHealthPoints << ")";
}

//--------------------------------------------- Non Member Non Friends -------------------------------------------------

HealthPoints operator+(const int health, const HealthPoints& current)
{
    if(health <=0)
    {
        return current;
    }
    HealthPoints result(current);
    return result+=health;
}

bool operator==(const HealthPoints& a, const HealthPoints& b)
{
    return (a<=b) && (a>=b);
}

bool operator!=(const HealthPoints& a, const HealthPoints& b)
{
    return !(a == b);
}

bool operator>=(const HealthPoints& a, const HealthPoints& b)
{
    return (a > b) || (a == b);
}

bool operator<=(const HealthPoints& a, const HealthPoints& b)
{
    return (a < b) || (a ==b);
}
bool operator>(const HealthPoints& a, const HealthPoints& b)
{
    return !(a <= b);
}


