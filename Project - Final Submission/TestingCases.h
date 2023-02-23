/*
	Linux > Windows

	Pricz, Zachary
	Chang, Jacob
	Win, Ye Yint

	Fall 2022
	CS A250 - C++ 2
	Project: CS Courses
*/

#ifndef TESTINGCASES_H
#define TESTINGCASES_H

#include "CourseList.h"

#include <string>
#include <set>

void createCourseList(CourseList& courseList);

void getData(int& number, std::string& newName,
	int& newUnits, std::set<int>& newPrereqs, int idx);

#endif