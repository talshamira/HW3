#include "HealthPoints.h"

HealthPoints::HealthPoints(const int maxPoints)
{
    if(maxPoints <= 0)
    {
        throw(HealthPoints::InvalidArgument);
    }
    this->m_maxHealthPoints = maxPoints;
    this->m_healthPoints = maxPoints;
}

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

HealthPoints HealthPoints::operator-(const int health)
{
    if(health <=0)
    {
        return *this;
    }
    HealthPoints result(*this);
    return result-=health;
}


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

HealthPoints HealthPoints::operator+(const int health)
{
    if(health <=0)
    {
        return *this;
    }
    HealthPoints result(*this);
    return result+=health;
}

bool operator==(const HealthPoints& a, const HealthPoints& b)
{
    return a.m_healthPoints == b.m_healthPoints;
}

bool operator!=(const HealthPoints& a, const HealthPoints& b)
{
    return a.m_healthPoints != b.m_healthPoints;
}

bool operator>=(const HealthPoints& a, const HealthPoints& b)
{
    return a.m_healthPoints >= b.m_healthPoints;
}

bool operator<=(const HealthPoints& a, const HealthPoints& b)
{
    return a.m_healthPoints <= b.m_healthPoints;
}
bool operator>(const HealthPoints& a, const HealthPoints& b)
{
    return a.m_healthPoints > b.m_healthPoints;
}

 bool operator<(const HealthPoints& a, const HealthPoints& b)
{
    return a.m_healthPoints < b.m_healthPoints;
}

std::ostream& operator<<(std::ostream& os,HealthPoints health)
{
    return os << health.m_healthPoints << "(" << health.m_maxHealthPoints << ")";
}

