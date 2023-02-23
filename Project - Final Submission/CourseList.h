/*
	Linux > Windows

	Pricz, Zachary
	Chang, Jacob
	Win, Ye Yint

	Fall 2022
	CS A250 - C++ 2
	Project: CS Courses
*/

#ifndef COURSELIST_H
#define COURSELIST_H

#include "Course.h"


#include <string>
#include <set>

class Node
{
public:
	Node() : course(), next(nullptr) {}
	Node(const Course& newCourse, Node* newNext)
		: course(newCourse), next(newNext) {}
	Course getCourse() const { return course; }
	Node* getNext() const { return next; }
	void setCourse(const Course& newCourse) { course = newCourse; }
	void setNext(Node* newNext) { next = newNext; }
	~Node() {}
private:
	Course course;
	Node* next;
};

class CourseList
{
public:
	// Default constructor
	CourseList() : first(nullptr), last(nullptr), count(0) {}

	// Functions addCourse
	void addCourse(const Course&);
	void addCourse(int courseNumber, const std::string& courseName,
		int courseUnits, const std::set<int>& prereqs);

	// Accessor functions
	std::string getPrefix() const;
	int getNumberOfCourses() const;

	// Boolean functions
	bool isEmpty() const;
	bool searchCourse(int courseNumber) const;
	bool searchCourse(int courseNumber, std::string& courseName) const;
	bool searchCourse(int courseNumber, Course& courseObj) const;

	// Function deleteCourse
	void deleteCourse(int courseNumber);

	// Function retrieveAllCourses
	void retrieveAllCourses(std::string& courseFormat) const;

	// Function clearList
	void clearList();

	/********************* THE BIG THREE *********************/

	// Copy constructor
	CourseList(const CourseList& otherCourseList);

	// Overloaded assignment operator
	CourseList& operator=(const CourseList& rightSide);

	// Destructor
	~CourseList();

private:
	// Function getCourseLocation
	Node* getCourseLocation(int courseNumber) const;

	// Function insertInOrder
	void insertInOrder(Node* aCourse);

	// Helper functions for overloaded assignment operator
	void copyCallingObjIsEmpty(const CourseList& aCourse);
	void copyObjectsSameLength(const CourseList& aCourse);
	void copyCallingObjLonger(const CourseList& aCoures);
	void copyCallingObjShorter(const CourseList& aCourse);

	Node* first;
	Node* last;
	int count;
};
#endif
