/*
	Linux > Windows

	Pricz, Zachary
	Chang, Jacob
	Win, Ye Yint

	Fall 2022
	CS A250 - C++ 2
	Project: CS Courses
*/

#include "Interface.h"

#include <iostream>
#include <stdlib.h>
using namespace std;

void displayMenu()
{
	cout << "**************************************************************\n"
		<< "                          MAIN MENU\n"
		<< "**************************************************************\n";
	cout << "\nSelect one of the following:\n\n"
		<< "    1: Search course\n"
		<< "    2: Add course\n"
		<< "    3: Delete course\n"
		<< "    4: Display all courses\n"
		<< "    5: Display prerequsities for a given course\n"
		<< "    6: To exit\n";
}

void searchCourse(CourseList& courseList)
{
	cout << "Please enter the course number for the course "
		<< "you would like to search for: ";
	int courseNumber = 0;
	cin >> courseNumber;
	Course searchedCourse;
	bool courseFound =
		courseList.searchCourse(courseNumber,
			searchedCourse);
	if (!courseFound)
	{
		cout << "\nPlease try searching for a course again "
			<< "and make another selection.\n";
	}
	else
	{
		cout << "\nCOURSE NUMBER: "
			<< searchedCourse.getCourseNumber() << "\n"
			<< "COURSE NAME: "
			<< searchedCourse.getCourseName() << "\n"
			<< "COURSE UNITS: "
			<< searchedCourse.getCourseUnits() << "\n";
	}
}

void addCourse(CourseList& courseList)
{
	cout << "Cannot add course. "
		<< "Please contact the Ciriculum Committee"
		<< " to start the process of adding a course.\n";
}

void deleteCourse(CourseList& courseList)
{

	int courseNumber = 0;
	int confirmationChoice = 0;
	bool courseFound = false;

	cout << "Please enter the course number of the "
		<< "course you would like to delete: ";
	cin >> courseNumber;

	courseFound = courseList.searchCourse(courseNumber);
	if (!courseFound)
	{
		cout << "\nThe course number you entered was invalid "
			<< "or wasn't found in the system. "
			<< "Please try again.";
	}
	else
	{
		cout << "\nThe specified course was found in our system.\n\n"
			<< "Are you sure you would like to delete this course? "
			<< "Enter 1 for yes, press 0 for no: ";
		cin >> confirmationChoice;

		if (confirmationChoice == 1)
		{
			courseList.deleteCourse(courseNumber);
			cout << "\nThe course was successfully deleted from the system.\n";
		}
		else
		{
			cout << "\nThe course you specified was not "
				<< "deleted from the system.\n";
		}
	}
}

void displayCourses(CourseList& courseList)
{
	string listOfCourses;
	courseList.retrieveAllCourses(listOfCourses);
	cout << "\n" << listOfCourses;
}

void displayPrerequisites(CourseList& courseList)
{
	cout << "Please enter a course number from your course list"
		<< " you would like to see the prerequisites for: ";
	int courseNumber = 0;
	cin >> courseNumber;
	Course searchedCourse;
	bool courseFound = courseList.searchCourse(courseNumber,
		searchedCourse);
	if (!courseFound)
	{
		cout << "\nPlease try searching for a course again "
			<< " and make another selection.";
	}
	else
	{
		const set<int> coursePrereqs = searchedCourse.getCoursePrereqs();
		if (coursePrereqs.size() < 1)
		{
			cout << "\nThere are no prerequisites for this course.\n";
		}
		else
		{
			cout << "\nThe prerequsite course numbers for this course are:\n\n";
			for (const int elem : coursePrereqs)
			{
				cout << elem << "\n";
			}
		}
	}
}

void exitMessage()
{
	cout << "Thank you, have a great day!";
}
void processChoice(CourseList& courseList)
{
	// Write your code in here...

	if (courseList.getNumberOfCourses() == 0)
	{
		cerr << "\nThe course database is empty. Please restart the program "
			<< "with a non empty database.";
	}
	else
	{
		bool systemRunning = true;
		while (systemRunning)
		{
			cout << "\nPlease enter one of the choices above: ";
			int userChoice = 0;
			cin >> userChoice;
			system("CLS");
			if (userChoice < 1 || userChoice > 6)
			{
				cout << "\nNo choice matches that input\n"
					<< "Please choose an integer value between 1 and 6.";
			}
			else if (userChoice == 1)
			{
				searchCourse(courseList);
			}
			else if (userChoice == 2)
			{
				addCourse(courseList);
			}
			else if (userChoice == 3)
			{
				deleteCourse(courseList);
			}
			else if (userChoice == 4)
			{
				displayCourses(courseList);
			}
			else if (userChoice == 5)
			{
				displayPrerequisites(courseList);
			}
			else if (userChoice == 6)
			{
				exitMessage();
				systemRunning = false;
			}

			if (systemRunning)
			{
				cout << "\n";
				system("PAUSE");
				system("CLS");
				displayMenu();
			}
		}

	}







}