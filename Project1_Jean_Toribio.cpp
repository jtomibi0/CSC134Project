#include <iostream>
using namespace std;

int main()
{
	int clockSpdOfGPU = 0;
	int clockSpdOfCPU = 0;
	int numOfCPUCores = 0;
	int monitorResChoice;
	string monitorRes;
	float multiplier;
	float performanceScore;
	string recommendedGraphicsQuality;
	
	cout << "Please enter the clock speed (in Megahertz) of your graphics card: ";
	cin >> clockSpdOfGPU;
	if (clockSpdOfGPU < 0)
	{
		cout << "Invaild graphics card speed entered. Program will terminate.";
		return 0;
	}
	cout << "Please enter the clock speed (in Megahertz) of your processor: ";
	cin >> clockSpdOfCPU;
	if (clockSpdOfCPU < 0)
	{
		cout << "Invalid processor speed entered. Program will terminate.";
		return 0;
	}
	cout << "Please enter the number of cores of your processor: ";
	cin >> numOfCPUCores;
	if (numOfCPUCores < 0)
	{
		cout << "Invaild number of cores entered. Program will terminate.";
		return 0;
	}
	cout << "What is the resolution of your monitor?\n\t1. 1280 x 720\n\t2. 1920 x 1080\n\t3. 2560 x 1440\n\t4. 3840 x 2160\nPlease select from the options above: ";
	cin >> monitorResChoice;
	switch (monitorResChoice)
	{
		case 1: monitorRes = "1280 x 720";
				multiplier = 1;
				break;
		case 2: monitorRes = "1920 x 1080";
				multiplier = .75;
				break;
		case 3: monitorRes = "2560 x 1440";
				multiplier = .55;
				break;
		case 4: monitorRes = "3840 x 2160";
				multiplier = .35;
				break;
		default: cout << "Invalid Resolution menu choice. Program will terminate.";
				 return 0;
	}
	
	performanceScore = ((5 * clockSpdOfGPU) + (numOfCPUCores * clockSpdOfCPU)) * multiplier;
	if (performanceScore > 17000)
	{
		recommendedGraphicsQuality = "Ultra";
	}
	else if (performanceScore > 15000 && performanceScore < 17000)
	{
		recommendedGraphicsQuality = "High";
	}
	else if (performanceScore > 13000 && performanceScore < 15000)
	{
		recommendedGraphicsQuality = "Medium";
	}
	else if (performanceScore > 11000 && performanceScore < 13000)
	{
		recommendedGraphicsQuality = "Low";
	}
	else if (performanceScore <= 11000)
	{
		recommendedGraphicsQuality = "Unable to Play";
	}
	
}
