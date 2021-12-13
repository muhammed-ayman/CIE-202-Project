#pragma once
#include "Component.h"

class Ground:public Component
{
public:
	Ground(GraphicsInfo *r_GfxInfo); //Constructor that sets item type for the ground class
	virtual void Operate();	//Calculates the volt on both terminals
	virtual void Draw(UI*);	//Draws the ground
	virtual string* Save(); //returns components data to save
};
