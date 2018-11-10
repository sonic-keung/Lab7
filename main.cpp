#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include "Course.hpp"

using namespace std;

/*
 * print schedule - outputs course schedule to the screen
 * @param - add any new parameters you need
 */
void printSchedule(vector<Course> &path)
{
    for(auto i = path.begin(); i != prev(path.end()); ++i) {
        for(auto j = next(i); j != path.end(); ++j) {
            if((j->start_time >= i->start_time && j->start_time <= i->finish_time && j->day == i->day)
               || (j->finish_time >= i->start_time && j->finish_time <= i->finish_time && j->day == i->day)) {
                cout << "CONFLICT:" << endl;
                cout << *i;
                cout << *j << endl;
            }
        }
    }

    //Prints the entire course list using o_stream iterator
    ostream_iterator<Course> out_it (std::cout,"");
    copy(path.begin(), path.end(), out_it);
}

int main () {
    vector<Course> myVector;
    ifstream file;
    file.open("../courses.txt");
    if (!file) {
        cout << "cannot open the file" << endl;
    }
    string readLine;
    while(getline(file, readLine)) {
        istringstream iss(readLine);
        string courseName;
        Course::dayOfWeek day;
        char tempDay;
        unsigned int start_time;
        unsigned int end_time;
        iss >> courseName;
        iss >> tempDay;
        switch(tempDay) {
            case 'M':
                day = Course::MON;
                break;
            case 'T':
                day = Course::TUE;
                break;
            case 'W':
                day = Course::WED;
                break;
            case 'R':
                day = Course::THUR;
                break;
            case 'F':
                day = Course::FRI;
                break;
            default:
                break;
        }
        iss >> start_time;
        iss >> end_time;
        Course course(courseName, day, start_time, end_time);
        myVector.push_back(course);
    }
    //sort the stl container
    sort(myVector.begin(), myVector.end());
    printSchedule(myVector);
    return 0;
}