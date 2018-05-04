// Date.H - Date class definition
// Author - Wade Davidson
// Using Git for version mangement.

#ifndef DATE_H
#define DATE_H

    /**
    * @class Date
    * @brief  Stores the date
    *
    * @author Wade Davidson
    * @version 02
    * @date 29/06/2018 Wade Davidson, Started, Default constructor done.
    *
    * @author Wade Davidson
    * @version 03
    * @date 29/06/2018 Wade Davidson, added m_day setters and getters and tested.
    *
    * @author Wade Davidson
    * @version 04
    * @date 29/06/2018 Wade Davidson, added m_month setters and getters and tested.
    *
    * @author Wade Davidson
    * @version 05
    * @date 29/06/2018 Wade Davidson, added m_year setters and getters and tested.
    *
    * @author Wade Davidson
    * @version 06
    * @date 04/04/2018 Wade Davidson, added function to return month as string
    *
    * @author Wade Davidson
    * @version 07
    * @date 04/04/2018 Wade Davidson, added function to return the entire date as a string
    *
    * @author Wade Davidson
    * @version 08
    * @date 17/04/2018 Wade Davidson, added DatUtils.h. changed SetDay function to add preconditions
    *
    * @author Wade Davidson
    * @version 09
    * @date 17/04/2018 Wade Davidson, added SetDate to check for valid dates. Only able to set it through this!
    *
    * @todo Not sure yet.....
    */

class Date
{
    public:
            /**
            * @brief Default constructor
            **/
        Date();
            /**
            * @brief Clears varirables
            * @return void
            * @post Date object is cleared
            **/
        void Clear();
            /**
            * @brief Returns the day
            * @return unsigned int
            **/
        unsigned GetDay() const;
            /**
            * @brief Returns the month
            * @return unsigned int
            **/
        unsigned GetMonth() const;
            /**
            * @brief Returns the year
            * @return unsigned int
            **/
        unsigned GetYear() const;
            /**
            * @brief  Sets and checks the date
            *
            * Check for valid date including leap years and returns true if successful.
            * Date object must be set this way!!!
            *
            * @param  m_day for the day
            * @param  m_month for the month
            * @param  m_year for the year
            *
            * @return bool
            * @pre Must be a valid date
            * @post will set the date
            */
        bool SetDate(unsigned d, unsigned m, unsigned y);

    private:
            ///Stores the day
        unsigned m_day;
            ///Stores the month
        unsigned m_month;
            ///Stores the year
        unsigned m_year;
            /**
            * @brief Used to set the day
            * @param unsigned int
            * @return void
            * @post The day is set
            **/
        bool SetDay(const unsigned d);
            /**
            * @brief Used to set the month
            * @param unsigned int
            * @return bool true if set
            * @post The month is set
            **/
        bool SetMonth(const unsigned m);
            /**
            * @brief Used to set the year
            * @param unsigned int
            * @return bool true if set
            * @post The year is set
            **/
        bool SetYear(const unsigned y);
};

#endif // DATE_H
