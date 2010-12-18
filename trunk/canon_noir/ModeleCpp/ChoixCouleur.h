#pragma once
#include "state.h"
class ChoixCouleur : public State
{
public:
	ChoixCouleur(void);
	~ChoixCouleur(void);
	void gerer();
};

