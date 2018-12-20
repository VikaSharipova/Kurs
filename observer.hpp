#pragma once
#include "utilities.h"

class Observer {
	public:
		virtual void updateResult(MList<int> &value, const string &nameOfDiscipline) = 0;
};
