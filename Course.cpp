#include <iomanip>
#include "Course.hpp"

using namespace std;

Course::Course (string title, dayOfWeek day, unsigned int start_time, unsigned int finish_time) : title (title), day (day), start_time (start_time), finish_time (finish_time)
{
}
Course::Course (const Course & m) : title (m.title), day (m.day), start_time (m.start_time), finish_time (m.finish_time)
{
}

Course & Course::operator =(const Course & m) {
    this->title = m.title;
    this->day = m.day;
    this->start_time = m.start_time;
    this->finish_time = m.finish_time;
    return *this;
}
bool Course::operator == (const Course & m) const {
    if (this->day == m.day) {
        return true;
    } else if (this->start_time == m.start_time && this->finish_time == m.finish_time) {
        return true;
    }

    return false;
}

bool Course::operator < (const Course & m) const
{
    if (this->day < m.day) {
        return true;
    }
    return false;
}

ostream & operator << (ostream &os, const Course & m)
{
    char day;
    switch(m.day) {
        case 0:
            day = 'M';
            break;
        case 1:
            day = 'T';
            break;
        case 2:
            day = 'W';
            break;
        case 3:
            day = 'R';
            break;
        case 4:
            day = 'F';
            break;
    }
    os << m.title << setw(4) << day << setw(8) << m.start_time << setw(8) << m.finish_time << endl;
    return os;
}