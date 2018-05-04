#include "Date.h"

Date::Date()
    :m_day(1), m_month(1), m_year(1900)
{

}

void Date::Clear()
{
    m_day = 1;
    m_month = 1;
    m_year = 1900;
}

bool Date::SetDay(const unsigned d)
{
    if(d < 1 || d > 31)
    {
        return false;
    }

    if(m_month == 02)
    {
        if(d == 29 && m_year % 4 == 0)//Check for leap year
        {
            m_day = d;
            return true;
        }

        if(d <= 28)
        {
            m_day = d;
            return true;
        }

        return false;
    }

    if(m_month == 4 || m_month == 6 || m_month == 9 || m_month == 11)
    {
        if(d < 31)
        {
            m_day = d;
            return true;
        }

        return false;
    }

    m_day = d;

    return true;
}

unsigned Date::GetDay() const
{
    return m_day;
}

bool Date::SetMonth(const unsigned m)
{
    if(m < 13 && m > 0)
    {
        m_month = m;

        return true;
    }
    else
    {
        return false;
    }
}

unsigned Date::GetMonth() const
{
    return m_month;
}

bool Date::SetYear(const unsigned y)
{
    if(y < 9999 && y > 0)
    {
        m_year = y;

        return true;
    }
    else
    {
        return false;
    }
}

unsigned Date::GetYear() const
{
    return m_year;
}

bool Date::SetDate(unsigned d, unsigned m, unsigned y)
{
    if(SetYear(y) && SetMonth(m) && SetDay(d))
    {
        return true;
    }
    else
    {
        return false;
    }

}
