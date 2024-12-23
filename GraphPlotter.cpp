#include<FileEditor.h>
#include <pbPlots.hpp>
#include <supportLib.hpp>
#include<TestWindow.h>

#include <vector>
#include <typeinfo>

#include <GraphPlotter.h>

GraphPlotter::GraphPlotter() 
{
	
}
GraphPlotter::GraphPlotter(string Name)
{
	File.SetName(Name);
}


void GraphPlotter::SetFileName(string name)
{
	File.SetName(name);
}

void GraphPlotter::InitilalizePlot() 
{
	//File.SetName(FileName);
	File.OpenFileStrIn();
	File.ReadInData();

}

void GraphPlotter::PlotGraph(string plotname) {

	RGBABitmapImageReference* imgRef1 = CreateRGBABitmapImageReference();;
    std:StringReference* errorMessage1 = CreateStringReferenceLengthValue(0, L' ');
	DrawScatterPlot(imgRef1, 1500, 1500, File.GetValVector1(), File.GetValVector2(), errorMessage1);
	std::vector<double>* pngData1 = ConvertToPNG(imgRef1->image);
	WriteToFile(pngData1, plotname);
	DeleteImage(imgRef1->image);

}

void GraphPlotter::BulkSetFileName(std::vector<std::string> Names) {

	for (int i = 0; i < NumberOfPlots; i++) 
	{
		BulkFile[i].SetName(Names[i]);
	}

}

void GraphPlotter::BulkInitialize() {

	for (int i = 0; i < NumberOfPlots; i++)
	{
		BulkFile[i].OpenFileStrIn();
		BulkFile[i].ReadInData();
	}

}

void GraphPlotter::BulkPlotGraph(std::vector<std::string> Names) {

	for (int i = 0; i < NumberOfPlots; i++)
	{
		std::cout << "\n PLOTING....START ";
		RGBABitmapImageReference* imgRef1 = CreateRGBABitmapImageReference();;
	    std:StringReference* errorMessage1 = CreateStringReferenceLengthValue(0, L' ');
		DrawScatterPlot(imgRef1, 500, 500, BulkFile[i].GetValVector1(), BulkFile[i].GetValVector2(), errorMessage1);
		std::vector<double>* pngData1 = ConvertToPNG(imgRef1->image);
		WriteToFile(pngData1, Names[i]);
		DeleteImage(imgRef1->image);

		//BulkFile[i].WriteLine();
		std::cout << "\n PLOTING....END";

	}
}