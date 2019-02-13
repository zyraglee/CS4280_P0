#include <iostream>
#include <fstream>
#include "buildtree.h"
#include "traversals.h"

using namespace std;
int main(int argc, char*argv[])
{
	string fileName;
//user input	
	if(argc == 2){
		// if filename was given
		cout << "You entered " << argv[1] << "as an argument.";
	}
	else if(argc > 2){
		cerr << "You entered too much argument!\nUsage:  " << argv[0] << "\n\t" << argv[0] <<" <file>\n\t" << argv[0]<<" <type string from the keyboard>\n";			
		return 1;
	}else{
		//there's no argument, take user input and store it to a temporary file
		string input;
		ofstream inputFile;  // used to create a file and write data to it
		
		fileName = "temp.input";
		inputFile.open(fileName.c_str()); // copies string initialized to fileName
		
		cout << "Please enter lowercase strings and press CTRL + D when done\n";
		while(cin >> input){ // this will read input from user infinitely until they press CTRL+D to exit
			//adding words to temp file
			inputFile << input << " ";
		}
		inputFile.close();
	}


return 0;
}
