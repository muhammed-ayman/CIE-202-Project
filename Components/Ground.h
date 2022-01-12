#pragma once
#include "Component.h"

class Ground:public Component
{
public:
	Ground();
	Ground(GraphicsInfo *r_GfxInfo); //Constructor that sets item type for the ground class
	virtual void Operate();	//Calculates the volt on both terminals
	virtual void Draw(UI*);	//Draws the ground
	virtual void Load(GraphicsInfo* r_GfxInfo, string label, double value);
	virtual void Save(ofstream& saveFile, string id); //returns components data to save
};
