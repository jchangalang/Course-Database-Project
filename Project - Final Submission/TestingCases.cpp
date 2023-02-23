/*
	Linux > Windows

	Pricz, Zachary
	Chang, Jacob
	Win, Ye Yint

	Project: CS Courses
*/

#include "TestingCases.h"

#include <vector>
using namespace std;

/*************************************************
* NOTE:
* To work on a smaller set of data for your
* testing cases, you can change the number
* of TOTAL_CLASSES to 2 or 3 classes.
**************************************************/
const int TOTAL_CLASSES = 15;

void createCourseList(CourseList& courseList)
{
	int number = 0;
	std::string name;
	int units = 0;
	std::set<int> prereqs;

	for (int i = 0; i < TOTAL_CLASSES; ++i)
	{
		getData(number, name, units, prereqs, i);
		courseList.addCourse(number, name, units, prereqs);
	}
}

void getData(int& newNumber, string& newName,
	int& newUnits, set<int>& newPrereqs, int idx)
{
	int numbers[] = {
		131, 140, 150, 170, 200,
		216, 220, 231, 250, 253,
		255, 257, 262, 263, 272
	};

	string names[] = {
		"Python Programming 1",
		"C#.NET Programming",
		"C++ Programming 1",
		"Java Programming 1",
		"Data Structures",

		"Computer Architecture",
		"Software Engineering",
		"Python Programming 2",
		"C++ Programming 2",
		"Principles in System Design",

		"Cybersecurity Foundations & Principles ",
		"Boolean Algebra & Logic",
		"Discrete Structures",
		"Probability & Statistics for CS",
		"Java Programming 2",
	};

	int units[] = {
		4, 4, 4, 4,	4,
		4, 4, 4, 4, 4,
		4, 3, 3, 4, 4
	};

	// More than one prerquisite: AND
	vector<set<int>> prereqs = {
		{ },			//131 Python Programming 1
		{ },			//140 C#.NET Programming
		{ 170 },		//150 C++ Programming 1
		{ },			//170 Java Programming 1
		{ 150, 250 },	//Data Structures
		//
		{ 150, 170 },	//216 Computer Architecture
		{ 150, 170 },	//220 Software Engineering
		{ 131 },		//231 Python Programming 2
		{ 150, 170 },	//250 C++ Programming 2
		{ 150, 170 },	//253 Principles in System Design
		//
		{ 150, 170 },   //255 Cybersecurity Foundations & Principles  
		{ 150, 170 },	//257 Boolean Algebra & Logic
		{ 150, 170 },	//262 Discrete Structures
		{ 150, 170 },	//263 Probability & Statistics for CS
		{ 170 }, 		//272 Java Programming 2
	};

	newNumber = numbers[idx];
	newName = names[idx];
	newUnits = units[idx];
	newPrereqs = prereqs[idx];
}