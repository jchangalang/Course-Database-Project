/*
	Linux > Windows

	Pricz, Zachary
	Chang, Jacob
	Win, Ye Yint

	Fall 2022
	CS A250 - C++ 2
	Project: CS Courses
*/

#include "CourseList.h"
#include "TestingCases.h"
#include "Interface.h"

#include <iostream>
#include <string>
using namespace std;

int main()
{
	/********************************************************
	*	TESTING database
	********************************************************/
	CourseList courseList;
	createCourseList(courseList);
	displayMenu();
	processChoice(courseList);

	cout << "\n";
	return 0;

}