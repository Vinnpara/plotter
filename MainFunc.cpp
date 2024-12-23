// Plotter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<FileEditor.h>
#include<pbPlots.hpp>
#include<supportLib.hpp>
#include<TestWindow.h>
#include<GraphPlotter.h>

#include <vector>
#include <typeinfo>
int main()
{
    
    TestWindow* PlotWindow = new TestWindow(true);

    bool run = true;

    GraphPlotter Pitch,
                 Roll,
                 Yaw,
                 BulkPlot;
    static bool PlotFinished = 0;

    while (run)
    {
        PlotWindow->GetTextTest();

        if (PlotWindow->LoadButtonState())
        {
            /*Pitch.SetFileName(PlotWindow->GetFileName1());
            Roll.SetFileName(PlotWindow->GetFileName2());
            Yaw.SetFileName(PlotWindow->GetFileName3());*/

            //PlotWindow->UpdatePlotNames();
            BulkPlot.setNumberOfPlots(3);
            BulkPlot.BulkSetFileName(PlotWindow->GetPlotFileName());

            std::cout << "\nLoad Button window";
            //std::cout << "\n" << PlotWindow->GetFileName1();
            PlotWindow->AutoResetLoad();
        }

        if (PlotWindow->PlotButtonState())
        {

            /*Pitch.InitilalizePlot();
            Roll.InitilalizePlot();
            Yaw.InitilalizePlot();
            
            Pitch.PlotGraph(PlotWindow->GetPlotName1());
            Roll.PlotGraph(PlotWindow->GetPlotName2());
            Yaw.PlotGraph(PlotWindow->GetPlotName3());*/

            std::cout << "\nPLOT Button window";

            //std::cout << "\n" << PlotWindow->GetFileName1();

            BulkPlot.BulkInitialize();
            BulkPlot.BulkPlotGraph(PlotWindow->GetPlotResultName());

            PlotWindow->AutoResetPlot();
        }

        if (!PlotWindow->ProcessMessages())
        {
            run = false;
            std::cout << "\nClose window";
        }

        Sleep(1);
    }

    delete PlotWindow;

    //The plot window takes in the arguments such as the name of the graph and the name of the file
    //This is then passed into the GraphPlotter func. This will plot and save the file, then pass on status
    //
    //To complete::
    //There needs to function from the PlotWindow to pass the name of the plot, and the name of the data file
    //to each FileEditor object (Maybe change to GraphPlot, better name). The FileEditor could also contain the plot functions. There are 7 slots,
    //So will need 7 FileEditor objects.

    /*FileEditor PitchIn;
    PitchIn.SetName("Pitch.csv");

    PitchIn.OpenFileStrIn();
    PitchIn.ReadInData();
    //PitchIn.WriteLine();

    PitchIn.CloseFileIn();


    FileEditor RollIn;
    RollIn.SetName("Roll.csv");

    RollIn.OpenFileStrIn();
    RollIn.ReadInData();
    //RollIn.WriteLine();

    RollIn.CloseFileIn();*/

    /*double xsa[] = {-2, -1, 0, 1, 2};
    vector<double> xs(xsa, xsa + sizeof(xsa) / sizeof(double));
    double ysa[] = { 2, -1, -2, -1, 2 };
    vector<double> ys(ysa, ysa + sizeof(ysa) / sizeof(double));*/

    /*RGBABitmapImageReference* imgRef1 = CreateRGBABitmapImageReference();
    std:StringReference* errorMessage1 = CreateStringReferenceLengthValue(0, L' ');;
    DrawScatterPlot(imgRef1, 1500, 1500, PitchIn.GetValVector1(), PitchIn.GetValVector2(), errorMessage1);
    std::vector<double>* pngData1 = ConvertToPNG(imgRef1->image);
    WriteToFile(pngData1,"tst_pitch_new.png");
    DeleteImage(imgRef1->image);


    RGBABitmapImageReference* imgRef2 = CreateRGBABitmapImageReference();
    StringReference* errorMessage2 = CreateStringReferenceLengthValue(0, L' ');;
    DrawScatterPlot(imgRef2, 1500, 1500, RollIn.GetValVector1(), RollIn.GetValVector2(), errorMessage2);
    std::vector<double>* pngData2 = ConvertToPNG(imgRef2->image);
    WriteToFile(pngData2, "Steer_Test.png");
    DeleteImage(imgRef2->image);*/


    /*GraphPlotter Plot1("Pitch.csv");
    //Plot1.SetFileName("Pitch.csv");

    Plot1.InitilalizePlot();
    Plot1.PlotGraph("tst_pitch_class.png");*/

    //std::cout << "Hello World!\n";
}


