#include <iostream>

namespace Testing
{
    // prestupny rok deliteny 400 bez zbytku nebo  delitelny 4 ale nedelitelny 100

    class Year
    {
    private:
        int _year;
        Year(int year);
    public:

        //Year(int year) : _year(year) {}
        static Year* from_value (int year)
        {
            return new Year(year);
        }
        inline static int obj_cnt = 0;
        ~Year();
        bool is_leap(void) const;
        int get_days (int month) const;
        int get_total_days (void) const;
        int get_year(void) const { return this->_year; }
        int get_count (void) const { return this->obj_cnt; }
    };

    Year::Year(int year) : _year(year)
    {
        obj_cnt++;
    }

    Year::~Year()
    {
        obj_cnt--;
    }

    int Year::get_total_days() const
    {
        return (this->is_leap()) ? 366 : 365;
    }

    int Year::get_days(int month) const
    {
        if ((month <= 0) || (month > 12))
        {
            return -1;
        }
        else
        {
            if (month < 8)
            {
                if (month == 2)
                {
                    if (this->is_leap())
                    {
                        return 29;
                    }

                    return 28;
                }

                if (month % 2 == 0)
                {
                    return 30;
                }

                return 31;
            }
            else
            {
                if (month % 2 == 0)
                {
                    return 31;
                }

                return 30;
            }
        }
    }

    bool Year::is_leap(void) const
    {
        return ((this->get_year() % 400 == 0) || ((this->_year % 4 == 0) && (this->_year % 100 != 0)));
    }
}

int main ()
{
    Testing::Year* y = Testing::Year::from_value(2020);
    std::cout<< "pocitadlo objektu: "<<y->get_count()<<std::endl;
    delete y;
    return 0;
}