/* ------------------------------------------------------
CMP2801M: Advanced Programming
Driver program for assignment 1

All additional classes, headers and cpp files in this solution are authored by Kieran Ruby // 11654639
As well as the additions to this file

Last edited 15/12/2019
------------------------------------------------------ */
#pragma once
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Movable.h"

#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string userCommand;
	//vector of class shape to hold all shapes created
	vector <Shape*> shapes;
	//vector of strings to hold parameters, will be cleared at the beginning of each cycle
	vector <string> parameters;

	int x; int y; int h; int w; int e; int r; int shapeNo;
	float scaleX; float scaleY;
	//isNeg is a bool used to check if parameters are negative
	bool isNeg;

	while (userCommand.compare("exit") != 0)
	{
		//reset isNeg to 0 at the start of each loop to avoid an infinite error loop
		isNeg = 0;
		//clear parameters vector at the top due to exception handling continuing to next loop, meaning this would not take effect
		parameters.clear();

		//create a C form string (char array)
		cout << "Enter the command: ";
		getline(cin, userCommand);
		char * cstr = new char[userCommand.length() + 1];
		strcpy_s(cstr, userCommand.length() + 1, userCommand.c_str());
		// String tokeniser seperates each input by either a space or tab (as per delimiters)
		char* token = NULL;
		char* token2 = NULL;
		char delims[] = " \t";
		token = strtok_s(cstr, delims, &token2);
		//inside a while loop to ensure all tokens are collected
		while (token != NULL)
		{
			// Create the tokens and pushback them into the vector.
			parameters.push_back(token);
			//proceed to collect the next token
			token = strtok_s(NULL, delims, &token2);
		}
		//protects the system from crashing if only white-space is input as a command.
		if (parameters.size()==0)
		{
			cout << "Parameters are erroneous, please input a command and the expected values.\n";
			continue;
		}
		for (int i = 1; i < parameters.size(); i++){
			if (stoi(parameters[i]) < 0){
				cout << "\nSorry, parameters with a value less than 0 are not accepted!\n\n";
				isNeg = 1;
				break;
			}
		}
		if (isNeg == 1)
		{
			continue;
		}
		string command = parameters[0];


		if (command.compare("addR") == 0) {
			//check parameters to ensure enough are in place for use.
			if (parameters.size() != 5) {
				cout << "Invalid parameters, please input the command, x value, y value, height and width!";
			}
			else {
				//try to convert from string to int, if inputs are not expected - i.e. alphabetic rather than numeric, could cause an exception
				try
				{
					x = stoi(parameters[1].c_str());
					y = stoi(parameters[2].c_str());
					h = stoi(parameters[3].c_str());
					w = stoi(parameters[4].c_str());
				}
				//catch potential errors and break back into main loop
				catch (const std::exception&)
				{
					cout << "Error converting values to integers, did you use the correct values for the X, Y, height and width?\n\n";
					continue;
				}
				//create new instance of rectangle	
				Rectangle* r = new Rectangle(x, y, h, w);
				//add r to the shapes vector
				shapes.push_back(r);
				//display all information regarding shape
				cout << r->toString();
			}
		}
		else if (command.compare("addS") == 0) {
			//check parameters to ensure enough data is given
			if (parameters.size() != 4){
				cout << "Invalid parameters range, please input the command, the x value, the y value and the edge length";
			}
			else{
				//try conversion from string to int, in case erroneous data is fed, catch issue, display error message and return to main loop
				try {
					x = stoi(parameters[1].c_str());
					y = stoi(parameters[2].c_str());
					e = stoi(parameters[3].c_str());
				}
				catch (const std::exception&) {
					cout << "Error taking in values, were the X, Y and edge values in the correct format?\n\n";
					continue;
				}
				//create square with successful values
				Square* s = new Square(x, y, e);
				//add square to shapes vector
				shapes.push_back(s);
				//display information about shape
				cout << s->toString();
			}
		}
		if (command.compare("addC") == 0) {
			//check parameters to ensure enough data is fed to
			if (parameters.size()!=4) {
				cout << "Invalid parameters, please input the command, the x value, y value and radius of shape.";
			}
			else {
				//try string to int conversion, erroneous data is caught, error message presented, returns to main loop
				try {
					x = stoi(parameters[1].c_str());
					y = stoi(parameters[2].c_str());
					r = stoi(parameters[3].c_str());
				}
				catch (const std::exception&) {
					cout << "Error taking in values, were the X, Y and Radius values in the correct format?\n\n";
					continue;
				}
				//create instance of circle with valid data
				Circle* c = new Circle(x, y, r);
				//add circle to shapes vector
				shapes.push_back(c);
				//display information about circle
				cout << c->toString();
			}
		}
		else if (command.compare("scale") == 0) {
			//check parameters to ensure enough data is given - prevents index out of bounds errors
			if (parameters.size() !=4) {
				cout << "Invalid parameters, please input the command, the shape you wish to edit, the x scale and the y scale.\n";
			}
			else {
				//try string to int conversion, error can be thrown if data is erroneous, present error message and return to main loop if so
				try
				{
					//use of scaleX and scaleY here as potential use of decimals as scale factors
					shapeNo = stoi(parameters[1].c_str());
					scaleX = stof(parameters[2].c_str());
					scaleY = stof(parameters[3].c_str());
				}
				catch (const std::exception&)
				{
					cout << "Error taking in values, were the shape number or scale parameters valid?\n";
					continue;
				}
				//checks the index user is attempting to access, if beyond bounds, throw error.
				if (shapeNo > shapes.size() || shapeNo <= 0) {
					cout << "Error taking in values, shape number you have input does not exist.\n";
				}
				else {
					Movable *s = dynamic_cast<Movable*>(shapes[shapeNo - 1]);
					s->scale(scaleX, scaleY);
				}
			}
		}
		else if (command.compare("move") == 0) {
			//checks the user parameters to ensure there are no out of bounds inputs
			if (parameters.size()!=4){
				cout << "Invalid parameters, please input the command, the shape number, the new x and the new y\n";
			}
			else {
				try {
					//try to convert from string to int, is possible to throw invalid arguments error, hence try-catch
					shapeNo = stoi(parameters[1].c_str());
					x = stoi(parameters[2].c_str());
					y = stoi(parameters[3].c_str());
				}
				catch (const std::exception&) {
					//if exception is caught, present error message and return to main loop
					cout << "Error taking in values, please input the shape number, new x co-ordinate and new y co-ordinate as integers.\n";
					continue;
				}
				//checks the index user is attempting to access, if beyond bounds, throw error.
				if (shapeNo > shapes.size() || shapeNo <= 0) {
					cout<<"Error taking in values, shape number you have input does not exist.\n";
				}
				else {
					Movable *m = dynamic_cast<Movable*>(shapes[shapeNo - 1]);
					m->move(x, y);

					cout << shapes[shapeNo - 1]->toString();
				}
			}
		}
		//use a for loop to trigger toString and display all items in the vector.
		else if (command.compare("display") == 0) {
			for (unsigned int i = 0; i < shapes.size(); i++) {
				cout<<shapes[i]->toString();
			}
		}
		//cstr uses new keyword, needs to be deleted.
		delete cstr;
		cout << endl << endl;
	}
	//remove all items in the vector to prevent memory leaks before exiting program
	for (unsigned int i = 0; i < shapes.size(); i++)
	{
		//this triggers the destructor in the Respective Circle, square and rectangle classes
		delete shapes[i];
	}

	cout << "Press any key to continue...";
	std::getchar();
	
	return 0;
}