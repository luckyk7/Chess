#include "OptionScreen.h"
#include <Windows.h>
#include <fstream>

void OptionScreen::saveSettings()
{
	std::ofstream out("settings.txt");
	if (!out)
	{
		//unable to save settings
		MessageBox(NULL, "Unable to save file.", NULL, MB_OK);
	}
	else
	{
		out << _hotSeat << " " <<_difficulty << " " << _time;
	}

}
