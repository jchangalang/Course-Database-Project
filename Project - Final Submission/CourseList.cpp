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
#include <iostream>

using namespace std;

//Function Definition addCourse(Course)
void CourseList::addCourse(const Course& newCourse)
{
	this->insertInOrder(new Node(newCourse, nullptr));
}

//Function addCourse(int, string, int, set<int>)
void CourseList::addCourse(int courseNumber,
	const std::string& courseName,
	int courseUnits, const std::set<int>& prereqs)
{
	this->insertInOrder(new Node(Course(courseNumber,
		courseName, courseUnits, prereqs), nullptr));
}

// Definition function getPrefix
string CourseList::getPrefix() const
{
	return (first->getCourse()).getPrefix();
}

// Definition function getNumberOfCourses
int CourseList::getNumberOfCourses() const
{
	return count;
}

// Definition function isEmpty
bool CourseList::isEmpty() const
{
	return (count == 0);
}

// Definition function searchCourse
bool CourseList::searchCourse(int courseNumber) const
{
	if (count == 0)
	{
		return false;
	}

	else if (this->getCourseLocation(courseNumber) != nullptr)
	{
		return true;
	}

	return false;
}

// Definition function searchCourse Overloaded (int, string)
bool CourseList::searchCourse(int courseNumber,
	string& courseName) const
{

	Node* location = this->getCourseLocation(courseNumber);

	if (count == 0)
	{
		return false;
	}

	else if (location != nullptr)
	{
		courseName = location->getCourse().getCourseName();
		return true;
	}

	return false;
}

// Definition function searchCourse Overloaded (int, Course)
bool CourseList::searchCourse(int courseNumber,
	Course& courseObj) const
{
	Node* location = this->getCourseLocation(courseNumber);
	if (count == 0)
	{
		return false;
	}

	else if (location != nullptr)
	{
		courseObj = location->getCourse();
		return true;
	}

	return false;
}

//Definition deleteCourse
void CourseList::deleteCourse(int courseNumber)
{
	if (first->getCourse().getCourseNumber() == courseNumber)
	{
		Node* temp = first;
		first = first->getNext();
		delete temp;
		temp = nullptr;
	}
	else
	{
		Node* current = first;
		Node* trailCurrent = nullptr;

		while (current != nullptr)
		{
			if (current->getCourse().getCourseNumber() == courseNumber)
			{
				trailCurrent->setNext(current->getNext());
				delete current;
				current = nullptr;
				trailCurrent = nullptr;
			}
			else
			{
				trailCurrent = current;
				current = current->getNext();
			}
		}
	}
	--count;
}

//Definition retrieveAllCourses
void CourseList::retrieveAllCourses(string& courseFormat) const
{
	courseFormat.clear();
	Node* current = first;

	while (current != nullptr)
	{
		courseFormat = courseFormat + current->getCourse().getPrefix() +
			to_string(current->getCourse().getCourseNumber()) +
			" - " + current->getCourse().getCourseName() + '\n';

		current = current->getNext();
	}
}

//Definition clearList
void CourseList::clearList()
{
	Node* trailCurrent = nullptr;
	Node* current = first;

	while (current != nullptr)
	{
		trailCurrent = current;
		current = current->getNext();
		delete trailCurrent;
	}

	count = 0;
	first = last = nullptr;
}

//Definition function getCourseLocation
Node* CourseList::getCourseLocation(int courseNumber) const
{
	Node* current = first;

	while (current != nullptr)
	{
		if (current->getCourse().getCourseNumber() == courseNumber)
		{
			return current;
		}
		current = current->getNext();
	}

	return nullptr;
}
