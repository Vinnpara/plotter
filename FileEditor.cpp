#include <iterator>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include "Include\FileEditor.h"

FileEditor::FileEditor()
{

}

FileEditor::FileEditor(char* filename)
{
	this->NameOfFile = filename;



}

FileEditor::FileEditor(string filename)
{
    name = filename;



}

void FileEditor::SetName(string Name) {

    name = Name;

}

void FileEditor::OpenFile() {

	DataFile.open(NameOfFile);

}

void FileEditor::OpenFileStrIn() {

    DataFileIn.open(name);
    if(DataFileIn.is_open())
    {
        std::cout << "\nIN FILE OPEN";
    }
    else
    {
        std::cout << "\nIN FILE CLOSED";
    }

}

void FileEditor::OpenFileStr() {

    DataFile.open(name);
    if (DataFile.is_open()) {
        std::cout << "\n OPEN  ";
    }
    else {
        std::cout << "\n CLOSED  ";
    }
}


void FileEditor::RecordDataFloat(float Data1, float Data2) {
    
    if (DataFile.is_open()) {

        //DataFile << "\nText";
        
        DataFile << Data1;
        DataFile << ",";
        DataFile << Data2;
        DataFile << "\n";

        //std::cout << "\n START  " << Data1;
        //std::cout << "\n STOP  " << Data2;
    }
    //std::cout << "\n START  ";
    //std::cout << "\n STOP  ";
}

void FileEditor::ReadInData()
{

    if (DataFileIn.is_open()) 
    {

        /*std::string                line;
        //getline(DataFileIn, line);

        std::stringstream          lineStream(line);
        std::string                Strin;*/

        char temp;
        
        while(1)
        {
        
            DataFileIn >> Value1 >> temp >> Value2;

            Value1Vector.push_back(Value1);
            Value2Vector.push_back(Value2);

            line.push_back(temp);


            if (DataFileIn.eof())
                break;

        }
        
        
        /*while (std::getline(lineStream, cell))
        {
            result.push_back(cell);
        }
        if (!lineStream && cell.empty())
        {
           
            result.push_back("");
        }*/
        //getline(DataFileIn, line); 
        /*while (getline(DataFileIn, line)) 
        {
            cout << "\t" << line.size() << endl;
            //cout << "\n reading " << endl;
            cout << line << endl;
            
        }*/
        



    }


}

void FileEditor::WriteLine()
{

    for (size_t i = 0; i < Value1Vector.size(); i++)
    {

        cout << "\nVEC_1 " << Value1Vector[i] << endl;

    }

    cout << "n\**************_VEC 2_**************";


    for (size_t i = 0; i < Value2Vector.size(); i++)
    {

        cout << "\nVEC_2 " << Value2Vector[i] << endl;

    }

}

void FileEditor::CloseFile() {

    DataFile.close();

}

void FileEditor::CloseFileIn() {

    DataFileIn.close();

}