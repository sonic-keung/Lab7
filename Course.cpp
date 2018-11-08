#include "Course.hpp"

using namespace std;

Course::Course (string title, dayOfWeek day, unsigned int start_time, unsigned int finish_time) : title (title), day (day), start_time (start_time), finish_time (finish_time)
{
}
Course::Course (const Course & m) : title (m.title), day (m.day), start_time (m.start_time), finish_time (m.finish_time)
{
}

Course & Course::operator =(const Course & m) {
    //TODO implement the operator
    return *this;
}
bool Course::operator == (const Course & m) const {
    //TODO implement the operator
    return false;
}

bool Course::operator < (const Course & m) const
{
    //TODO implement the operator
    return false;
}

ostream & operator << (ostream &os, const Course & m)
{
    //TODO implement the operator
    return os;
}