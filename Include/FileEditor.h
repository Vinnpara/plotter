#ifndef FILE_EDITOR_H
#define FILE_EDITOR_H

#include <iterator>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

class FileEditor
{
public:
	FileEditor();
	FileEditor(char* filename);
	FileEditor(string filename);
	void OpenFile();
	void OpenFileStr();
	void OpenFileStrIn();

	void SetName(string Name);
	void RecordDataFloat(float Data1, float Data2);
	void ReadInData();

	void CloseFile();
	void CloseFileIn();

	void WriteLine();

	std::vector<double> GetVal1Vector()
	{
		return Value1Vector;
	}

	std::vector<double> GetVal2Vector()
	{
		return Value2Vector;
	}

	std::vector<double> * GetValVector1()
	{
		return &Value1Vector;
	}

	std::vector<double> * GetValVector2()
	{
		return &Value2Vector;
	}

private:
	std::ofstream DataFile;
	std::ifstream DataFileIn;
	char* NameOfFile;
	string name;

	double Value1,
		  Value2;

	std::vector<double> Value1Vector,
		               Value2Vector;
	string line, 
		   word, 
		   temp,
		test;
	stringstream lineread;

	std::vector<std::string>   result;
};


#endif
