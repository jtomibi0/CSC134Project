#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	//Initializes Variables
	float clockSpdOfGPU;
	float clockSpdOfCPU;
	float numOfCPUCores;
	int monitorResChoice;
	string monitorRes;
	float multiplier;
	float performanceScore;
	string recommendedGraphicsQuality;
	string title = "Computer Hardware Graphics Quality Recommendation Tool";
	
	//Gets GPU clock speed
	cout << "Please enter the clock speed (in Megahertz) of your graphics card: ";
	cin >> clockSpdOfGPU;
	if (clockSpdOfGPU < 0)
	{
		cout << "Invaild graphics card speed entered. Program will terminate.";
		return 0;
	}
	//Gets CPU clock speed
	cout << "Please enter the clock speed (in Megahertz) of your processor: ";
	cin >> clockSpdOfCPU;
	if (clockSpdOfCPU < 0)
	{
		cout << "Invalid processor speed entered. Program will terminate.";
		return 0;
	}
	//Gets the number of cores in the CPU
	cout << "Please enter the number of cores of your processor: ";
	cin >> numOfCPUCores;
	if (numOfCPUCores < 0)
	{
		cout << "Invaild number of cores entered. Program will terminate.";
		return 0;
	}
	//Gets monitor resolution & determines multipler
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
	
	//Determines performance score
	performanceScore = ((5 * clockSpdOfGPU) + (numOfCPUCores * clockSpdOfCPU)) * multiplier;
	
	//Determines recommended graphics quality
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
	
	/* Displays GPU clock speed, CPU clock speed, number of cores, 
	monitor resolution, performance score, and recommended graphics quality */
	cout << "\n\n" << title << "\n\n";
	cout << "GPU Clock Speed: " << clockSpdOfGPU << " MHz" << endl;
	cout << "CPU Clock Speed: " << clockSpdOfCPU << " MHz" << endl;
	cout << "Number of cores: " << numOfCPUCores << endl;
	cout << "Monitor Resolution: " << monitorRes << endl;
	cout << "Performance Score: " << setprecision(2) << fixed << performanceScore << endl;
	cout << "Recommended Graphics Quality: " << recommendedGraphicsQuality << endl;
	return 0;
}
