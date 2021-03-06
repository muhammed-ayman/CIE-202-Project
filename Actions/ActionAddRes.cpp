#include "ActionAddRes.h"
#include "..\ApplicationManager.h"

ActionAddRes::ActionAddRes(ApplicationManager *pApp):Action(pApp)
{
}

ActionAddRes::~ActionAddRes(void)
{
}

void ActionAddRes::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	if (!pUI->getWriteMode()) {
		pUI->PrintMsg("You can not perform this action");
		return;
	}

	//Print Action Message
	pUI->PrintMsg("Adding a new resistor: Click anywhere to add");

	//Get Center point of the area where the Comp should be drawn
	pUI->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pUI->ClearStatusBar();

	if (Cx < 1100 && Cx > 20 && Cy >= 130 && Cy < 550) {

		GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the Comp

		//Calculate the rectangle Corners
		int compWidth = pUI->getCompWidth();
		int compHeight = pUI->getCompHeight();

		pGInfo->PointsList[0].x = Cx - compWidth / 2;
		pGInfo->PointsList[0].y = Cy - compHeight / 2;
		pGInfo->PointsList[1].x = Cx + compWidth / 2;
		pGInfo->PointsList[1].y = Cy + compHeight / 2;

		Resistor* pR = new Resistor(pGInfo);
		pManager->AddComponent(pR);
		this->SaveComponentParameters(pR);
	}
	else pUI->PrintMsg("Cannot draw except in the drawing area!");
}

void ActionAddRes::SaveComponentParameters(Resistor* resPointer) {
	this->ResistorPointer = resPointer;
}

void ActionAddRes::Undo()
{
	pManager->MakeCompNull(this->ResistorPointer);
}

void ActionAddRes::Redo()
{
	pManager->AddComponent(this->ResistorPointer);
}

