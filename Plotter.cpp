// Plotter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include<FileEditor.h>
#include<pbPlots.hpp>
#include<supportLib.hpp>
#include<TestWindow.h>


#include <vector>
#include <typeinfo>
int main()
{
    
    FileEditor PitchIn;
    PitchIn.SetName("AccZ.csv");

    PitchIn.OpenFileStrIn();
    PitchIn.ReadInData();
    //PitchIn.WriteLine();

    PitchIn.CloseFileIn();


    FileEditor RollIn;
    RollIn.SetName("ThrottleCommand.csv");

    RollIn.OpenFileStrIn();
    RollIn.ReadInData();
    //PitchIn.WriteLine();

    RollIn.CloseFileIn();



    RGBABitmapImageReference* imgRef1 = CreateRGBABitmapImageReference();

    std:StringReference* errorMessage1 = CreateStringReferenceLengthValue(0, L' ');;

    DrawScatterPlot(imgRef1, 1500, 1500, &PitchIn.GetVal1Vector(), &PitchIn.GetVal2Vector(), errorMessage1);

    std::vector<double>* pngData1 = ConvertToPNG(imgRef1->image);
    WriteToFile(pngData1,"AccZ_Test.png");

    DeleteImage(imgRef1->image);



    RGBABitmapImageReference* imgRef2 = CreateRGBABitmapImageReference();

    StringReference* errorMessage2 = CreateStringReferenceLengthValue(0, L' ');;

    DrawScatterPlot(imgRef2, 1500, 1500, &RollIn.GetVal1Vector(), &RollIn.GetVal2Vector(), errorMessage2);

    std::vector<double>* pngData2 = ConvertToPNG(imgRef2->image);
    WriteToFile(pngData2, "ThrottleCommand_Test.png");

    DeleteImage(imgRef2->image);


    //std::cout << "Hello World!\n";
}


