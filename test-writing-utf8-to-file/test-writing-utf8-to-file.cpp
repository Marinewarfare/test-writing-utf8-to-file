
#include <iostream> //Duh.
#include <string> //For strings.
#include <fstream> //File input/output.

#include "json.hpp" //Added in perperation for the JSON portion.

//Function prototyping:
void displayToConsoleTest(std::string testStandardString, std::wstring testWideString); //Test 1
void writeStringToStandardFile(std::string testStandardString); //Test 2
void writeWStringToWideFile(std::wstring testWideString); //Test 3


int main()
{
	//Example/Test text:
	//ここにいる (I'm Here) ft. rionos (Stephen Walking Remix) - Aiobahn.mp3▼7277101▼1619445172▼1642879539▼▼MATCHED▼821
	std::string testStandardString = "ここにいる (I'm Here) ft. rionos (Stephen Walking Remix) - Aiobahn.mp3▼7277101▼1619445172▼1642879539▼▼MATCHED▼821";
	std::wstring testWideString = L"ここにいる (I'm Here) ft. rionos (Stephen Walking Remix) - Aiobahn.mp3▼7277101▼1619445172▼1642879539▼▼MATCHED▼821";

	//Test 1:
		//Testing how strings and wide strings differ when displaying to the console.
		//The projects encoding is set to "Multi-byte" in Visual Studio.
		//This is expected to give some problems due to switching between cout and wcout, as well as the console not showing the complex characters properly.
		displayToConsoleTest(testStandardString, testWideString);
		//Results:
			//As expected, the standard string is shown completely with the Japanese characters replaced with question marks.
			//The wide version fails to display at all, and even omits the "new line" at the end.

	//Test 2:
		//Sanity check on a method of writing to a file.
		writeStringToStandardFile(testStandardString);
		//Results:
			//This displays the Japanese characters as question marks, while having the file encoded as UTF-8.
			//All other characters display properly.


	//Test 3:
		//Checking if wstrings will write to the wide stream file using the same method of writing the string to a standard file stream.
		writeWStringToWideFile(testWideString);
		//Results:
			//This does not seem to write to the file at all. I am unsure why.


	//After sitting on this for a long time, I found this: https://docs.microsoft.com/en-us/cpp/build/reference/utf-8-set-source-and-executable-character-sets-to-utf-8?view=msvc-170

	std::cout << "PROGRAM FINSHED" << std::endl;
	system("PAUSE");
	return 1;
}


//Test 1
void displayToConsoleTest(std::string testStandardString, std::wstring testWideString)
{
	//Displaying in console.
	std::cout << "Standard String: " << testStandardString << std::endl;
	std::wcout << "Wide String: " << testWideString << std::endl;
}

//Test 2
void writeStringToStandardFile(std::string testStandardString)
{
	std::ofstream standardFileHandle("standardTest.txt", std::ios::out); //Creating stream.
	standardFileHandle << testStandardString << std::endl; //Writing to the file.

	standardFileHandle.close(); //Closing file.
}

//Test 3
void writeWStringToWideFile(std::wstring testWideString)
{
	std::wofstream wideFileHandle("wideTest.txt", std::ios::out);
	wideFileHandle << testWideString << std::endl;

	//Writing stuff to the file.
	wideFileHandle.close();
}