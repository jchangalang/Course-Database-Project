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

//Copy Constructor
CourseList::CourseList(const CourseList& paramCourseList)
{
	first = last = nullptr;
	count = 0;

	Node* currentParam = paramCourseList.first;

	while (currentParam != nullptr)
	{
		this->addCourse(currentParam->getCourse());
		currentParam = currentParam->getNext();
	}
}

// Definition overloaded assignment operator
CourseList& CourseList::operator=(const CourseList& rightSide)
{
	if (&rightSide == this)
	{
		cerr << "Attempted assignment to itself.\n";
	}
	else
	{
		int callingCourses = this->getNumberOfCourses();
		int rightSideCourses = rightSide.getNumberOfCourses();
		if (rightSide.count == 0)
		{
			clearList();
		}
		else if (this->count = 0)
		{
			copyCallingObjIsEmpty(rightSide);
		}
		else if (callingCourses == rightSideCourses)
		{
			copyObjectsSameLength(rightSide);
		}
		else if (callingCourses > rightSideCourses)
		{
			copyCallingObjLonger(rightSide);
		}
		else
		{
			copyCallingObjShorter(rightSide);
		}
	}

	return *this;
}


// Definition function copyCallingObjIsEmpty
void CourseList::copyCallingObjIsEmpty
(const CourseList& paramCourseList)
{
	Node* current = paramCourseList.first;

	while (current != nullptr)
	{
		this->addCourse(current->getCourse());
		current = current->getNext();
	}
}


// Definition function copyObjectsSameLength
void CourseList::copyObjectsSameLength
(const CourseList& paramCourseList)
{
	Node* paramCurrent = paramCourseList.first;
	Node* current = first;

	while (current != nullptr)
	{
		current->setCourse(paramCurrent->getCourse());
		current = current->getNext();
		paramCurrent = paramCurrent->getNext();
	}
}

// Definition function copyCallingObjLonger
void CourseList::copyCallingObjLonger
(const CourseList& paramCourseList)
{
	Node* paramCurrent = paramCourseList.first;
	Node* current = first;
	Node* tempCurrent = nullptr;

	// Copy directly for as how long the parameter paramCourseList is

	for (size_t i = 0; i < paramCourseList.count; ++i)
	{
		current->setCourse(paramCurrent->getCourse());
		tempCurrent = current;
		current = current->getNext();
		paramCurrent = paramCurrent->getNext();
	}

	// Delete the rest

	last = tempCurrent;
	tempCurrent->setNext(nullptr);
	while (current != nullptr)
	{
		tempCurrent = current;
		current = current->getNext();
		delete tempCurrent;
		tempCurrent = current;
	}
	count = paramCourseList.count;
}

// Definition function copyCallingObjShorter
void CourseList::copyCallingObjShorter
(const CourseList& paramCourseList)
{
	Node* paramCurrent = paramCourseList.first;
	Node* current = first;

	// Copy until the end of calling paramCourseList 

	while (current != nullptr)
	{
		current->setCourse(paramCurrent->getCourse());
		current = current->getNext();
		paramCurrent = paramCurrent->getNext();
	}

	// Add courses for remaining

	while (paramCurrent != nullptr)
	{
		this->addCourse(paramCurrent->getCourse());
		paramCurrent = paramCurrent->getNext();
	}
}

// Destructor
CourseList::~CourseList()
{
	if (count > 0)
	{
		clearList();
	}
}