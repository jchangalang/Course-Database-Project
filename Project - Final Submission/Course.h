/*
    Linux > Windows

    Pricz, Zachary
    Chang, Jacob
    Win, Ye Yint

    Fall 2022
    CS A250 - C++ 2
    Project: CS Courses
*/

#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <set>

class Course
{
public:

    // Constructors

    //Default Constructor via initializer list

    Course() : courseName("N/A"), courseNumber(0), courseUnits(0) {}

    Course(int courseNumParam, std::string courseNameParam,
        int courseUnitsParam, std::set<int> prereqsParam);

    // Accessor functions

    const std::string& getCourseName() const;
    int getCourseNumber() const;
    int getCourseUnits() const;
    const std::set<int>& getCoursePrereqs() const;
    const Course& getCourse() const;
    static std::string getPrefix();

    // Mutator functions

    void setCourseName(std::string name);
    void setCourseNumber(int number);
    void setCourseUnits(int units);
    void setPreReqs(int* array, int length);

    // Destructor
    ~Course() {};

private:
    int courseNumber;
    std::string courseName;
    int courseUnits;
    std::set<int> prereqs;
    static const std::string PREFIX;
};

#endif