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

// Definition function insertInOrder
// Assume there are no duplicates.
void CourseList::insertInOrder(Node* aCourse)
{
	if (first == nullptr)
	{
		first = aCourse;
		last = aCourse;
	}
	else
	{
		int courseNumber =
			aCourse->getCourse().getCourseNumber();

		// insert into beginning
		if (courseNumber <=
			first->getCourse().getCourseNumber())
		{
			aCourse->setNext(first);
			first = aCourse;
		}
		// insert into end
		else if (courseNumber >=
			last->getCourse().getCourseNumber())
		{
			last->setNext(aCourse);
			last = aCourse;
		}
		// insert inbetween
		else
		{
			Node* current = first->getNext();
			Node* tempCurrent = first;
			int currentCourseNumber = 0;
			bool found = false;

			while (current != nullptr && !found)
			{
				currentCourseNumber =
					current->getCourse().getCourseNumber();
				if (currentCourseNumber >= courseNumber)
				{
					tempCurrent->setNext(aCourse);
					aCourse->setNext(current);
					found = true;
				}
				tempCurrent = current;
				current = current->getNext();
			}
		}
	}
	++count;
}
