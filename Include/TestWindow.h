#pragma once

// Window creation happens in two ways. Creation and events. 
// Events are handled with messages. Messages are obtained with GetMessage and PeekMessage. 
// so first is "Get a message and wait for the next if you cannot find any" and next is 
// get message but continue if cannot find any.
// When message is received. Must be sent to the window procedure. This is done by the 
// window procedure. Done using the DispatchMessage function. Window procedure is defined by the user
// Every thing like clicks, key presses is handled in this function:
// Event ---> PeekMessage ---> DispatchMessage ---> WindowProx

#include <Windows.h>
#include <SerialPortSelection.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#define ID_BUTTON 1
#define ID_BUTTON_1 2 //Identifier forCOM 1
#define ID_BUTTON_2 3
#define ID_BUTTON_3 4
#define ID_BUTTON_4 5
#define ID_BUTTON_5 6
#define ID_BUTTON_6 7
#define ID_BUTTON_7 8
#define ID_BUTTON_8 9
#define ID_BUTTON_9 10
#define ID_BUTTON_10 11
#define ID_BUTTON_11 12
#define ID_BUTTON_12 13
#define ID_BUTTON_13 14
#define ID_BUTTON_14 15
#define ID_BUTTON_START_RECORD 16
#define ID_BUTTON_STOP_RECORD 17
#define ID_BUTTON_LOAD_DATA 18
#define ID_BUTTON_VERIFY_DATA 19
#define ID_BUTTON_PLOT_GRAPH 20
#define ID_RESET_PLOTS 21

#define MAX_CHAR_SIZE 64


LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
static bool B1_Done, 
            B2_Done, 
	        B3_Done, 
	        ID1_sel,
	        ID2_sel,
	        ID3_sel,
	        ID4_sel,
	        ID5_sel,
	        ID6_sel,
	        ID7_sel,
	        ID8_sel,
	        ID9_sel,
	        ID10_sel,
	        ID11_sel,
	        ID12_sel,
	        ID13_sel,
	        ID14_sel
	        ; // Supports 3 boards, force user to first choose the primary board, then the second
//This is the actual window procedure arguments are: 1st: what window is being acted on
// 2nd the message, 3rd and 4th gives info about the message;

LRESULT CALLBACK WindProcDiag(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

static bool Board1Selection[15],
            Board2Selection[15],
            Board3Selection[15]
	        ;



class TestWindow
{
public:
	int board1, board2, board3;
	TestWindow();
	TestWindow(bool Diagnotics);
	TestWindow(const TestWindow&) = delete; //User does not need to copy window, so delete
	TestWindow& operator = (const TestWindow&) = delete; //ALso delete the = operator
	~TestWindow();
	void Assignments();
	bool ProcessMessages();

	LRESULT CALLBACK WindProcplt(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	void UpdateDaignostcs(double Pitc_val, double Roll_val, double Yaw_val, unsigned long time);
	void UpdateDaignostcs(double Pitc_val, double Roll_val, double Yaw_val, bool ValidPitch, bool ValidRoll, unsigned long Time);
	void UpdateAccelDiag(double AccelX_val, double AccelY_val, double AccelZ_val);
	void UpdateVelDiag( float velx, float vely, float velcomp);
	void UpdateElapsedTime(float ElapsedTime);
	void UpdateRadarDaignostcs(int Val, int Pos);
	void UpdateMotorSteering(int Steer, int Throttle);
	void DisplayDiagnostics();

	void SetTextBuffer();

	void UpdatePlotNames();

	void GetTextTest();

	LPWSTR GetPitchWritten()
	{
		return PitchWritten;
	};
	LPWSTR GetRollWritten()
	{
		return RollWritten;
	};
	LPWSTR GetYawWritten()
	{
		return YawWritten;
	};
	//For drawing

	HWND ReturnWindowHandle() {
		return m_hWnd;
	};

	void DrawDiagnostic(HWND hWnd);

	void RecordCommandButtons();

	bool RecStartStatus();
	bool RecStopStatus();
	bool LoadButton,
		 PlotButton;

	bool LoadButtonState();
	bool PlotButtonState();

	std::string GetFileName1() {
		return FileNames[0];
	}

	std::string GetFileName2() {
		return FileNames[1];
	}

	std::string GetFileName3() {
		return FileNames[2];
	}

	std::string GetPlotName1() {
		return PlotName[0];
	}

	std::string GetPlotName2() {
		return PlotName[1];
	}

	std::string GetPlotName3() {
		return PlotName[2];
	}

	void AutoResetPlot();
	void AutoResetLoad();

	std::vector<std::string> GetPlotFileName();
	std::vector<std::string> GetPlotResultName();

private:

	std::string ConvertLPCWSTRToString(const LPCWSTR lpcwszStr);

	HINSTANCE m_hInstance; //connected to application
	HWND m_hWnd; //The actual window

	WNDCLASS wndClassDiag = {};  //Window class For diagnostics
	const wchar_t* DIAG_CLASS_NAME = L"Diagnosis Window Class"; //Wide character
	DWORD DiagStyle = WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU; //Display close button ect.
	RECT DiagRect;   //Dimensions of the window

	WNDCLASS DiagBox = {};  // Dynamic textbox

	LPWSTR 
	PitchWritten,
	RollWritten,
	YawWritten,
	RadarPos,
	RadarVal,
    SteerPos,
	ThrottlePos,
    AccelXWritten,
	AccelYWritten,
    AccelZWritten,
	ElapsedTimeWritten,
	VelxWritten,
	VelyWritten,
	VelcWritten
	;

	std::string PlotName[10],
		        FileNames[10];
	char Plots;

	//std::vector<wchar_t> PlotNameFiles[10];
	std::vector<std::vector<wchar_t>> PlotSourceFileNames;
	std::vector<std::vector<wchar_t>> PlotResultFileNames;

	std::vector<std::string> PerfPlotResultName;

	//wchar_t PlotFileNames[100];

	bool PitchValid,
		 RollValid;
};