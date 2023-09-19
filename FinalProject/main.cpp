//Includes
#include <iostream>

#include "student.h"
#include "degree.h"
#include "roster.h"

//Main Function
int main()
{
	//Class Data
	std::cout << "Course: Scripting and Programming - Applications - C867" << std::endl;
	std::cout << "Language: C++" << std::endl;
	std::cout << "Student ID: 010552990" << std::endl;
	std::cout << "Name: Canaan White\n" << std::endl;	


	//Instance of Roster
	Roster classRoster;
	
	const std::string studentData[] = { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Canaan,White,cwh1169@wgu.edu,22,12,10,12,SOFTWARE" };

	for (std::string studentInfo : studentData)
	{
		classRoster.ParseStudentInformation(studentInfo);
	}

	//Print All
	classRoster.PrintAll();

	//Print Invalid Emails
	classRoster.printInvalidEmails();
	
	//Loop through all class roster array
	for (int x = 0; x < classRoster.GetClassRosterArray().size(); x++)
	{
		//Call average days in course and pass in student id
		classRoster.printAverageDaysInCourse(classRoster.GetClassRosterArray()[x]->GetStudentId());
	}

	//Print by degree program
	classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);

	//Remove
	classRoster.remove("A3");
	std::cout << "\n";

	//Reprint
	classRoster.PrintAll();
	std::cout << "\n";

	//Try removing again, should throw error
	classRoster.remove("A3");


	return 0;
}