/*
    Linux > Windows

    Pricz, Zachary
    Chang, Jacob
    Win, Ye Yint

    Fall 2022
    CS A250 - C++ 2
    Project: CS Courses
*/

#include "Course.h"

#include <iostream>
#include <iomanip>
using namespace std;

const string Course::PREFIX = "CS A";

// Definition overloaded constructor
Course::Course(int courseNumParam, std::string courseNameParam,
    int courseUnitsParam, std::set<int> prereqsParam)
{
    courseNumber = courseNumParam;
    courseName = courseNameParam;
    courseUnits = courseUnitsParam;
    prereqs = prereqsParam;
}

// Definition function getCourseNumber
int Course::getCourseNumber() const
{
    return courseNumber;
}

// Definition function getCourseName
const std::string& Course::getCourseName() const
{
    return courseName;
}

// Definition function getCourseUnits
int Course::getCourseUnits() const
{
    return courseUnits;
}

// Definition function getPrereqs
const std::set<int>& Course::getCoursePrereqs() const
{
    return prereqs;
}

// Definition function getCourse
const Course& Course::getCourse() const
{
    return *this;
}

// Definition function getPrefix
std::string Course::getPrefix()
{
    return PREFIX;
}

// Definition function setCourseName
void Course::setCourseName(std::string name)
{
    courseName = name;
}

// Definition function setCourseNumber
void Course::setCourseNumber(int number)
{
    courseNumber = number;
}

// Definition function setCourseUnits
void Course::setCourseUnits(int units)
{
    courseUnits = units;
}

// Definition function setPrereqs
void Course::setPreReqs(int* array, int length)
{
    prereqs.clear();
    for (int i = 0; i < length; ++i)
    {
        prereqs.insert(array[i]);
    }
}