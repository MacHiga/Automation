#include <iostream>
#include <fstream>
#include <string>
#include "automation.hpp"
#include <assert.h>
using namespace std;




void append_testcase(ofstream& AppendFile, int option)
{

	switch(option) //applies text case number depending on what option is (right now 1<=option<=4
	{
		case 1:
			AppendFile << "REG-20X1" << endl;
			break;
		case 2:
			AppendFile << "REG-20X2" << endl;
			break;
		case 3:
			AppendFile << "REG-20X3" << endl;
			break;
		case 4:
			AppendFile << "REG-20X4" << endl;
			break;
		default:
			return;
	}

	return;
}



int main()
{

	string line;

	ifstream myfile;  ///opens original file for reading
	ofstream newfile; ///create new empty file for writing


	myfile.open("hello.txt"); //opens original file
	assert(myfile);			  //makes sure myfile is open

	newfile.open("hello2.txt", ios::trunc); //opens file: allows for appending and erases content of file if there is existing data

	while( myfile.good() )								//goes through file until EOF is found
	{

		getline(myfile, line);							//gets first line, will go through rest after

		newfile << line << endl;


		if( line.find("Scenario") != string::npos ) //npos is -1; size_t are unsigned ints so this value is impossible. Means not found
		{

			if( line.find("can ") != string::npos || line.find("adds ") != string::npos )
			{
				
				if( line.find("MCF")!= string::npos )
					append_testcase(newfile, 1);
				

				if( line.find("web")!= string::npos )
					append_testcase(newfile, 2);

			}


			if ( line.find("cannot")!= string::npos )
			{
				
				if( line.find("MCF")!= string::npos )
					append_testcase(newfile, 3);


				if( line.find("web")!= string::npos )
					append_testcase(newfile, 4);


			}
		

		}
		


	}
	myfile.close();


	cout << "end of program\n";
	return 0;
	



}
