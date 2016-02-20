#include "stdafx.h"
#ifndef OPTIONSCREEN_H
#define OPTIONSCREEN_H

class OptionScreen
{
private:
	bool _hotSeat;
	int _difficulty;
	unsigned _time;
	void saveSettings();
};



#endif
