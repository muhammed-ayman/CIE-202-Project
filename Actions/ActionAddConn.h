#pragma once
#include "Action.h"
#include "..\Components\Component.h"
#include "..\Defs.h"

class ActionAddConn : public Action
{
private:

	Component* CompList[MaxCompCount];
	ConnectionInfo* cInfo = new ConnectionInfo;
	GraphicsInfo* conn_graph_info = new GraphicsInfo(2);
	GraphicsInfo* CompListGraphicsInfo = new GraphicsInfo(2);
	GraphicsInfo* comp1_graph_info = new GraphicsInfo(2);
	GraphicsInfo* comp2_graph_info = new GraphicsInfo(2);
	Connection* conn = new Connection;

	int getComponent(int x,int y);
public:
	ActionAddConn(ApplicationManager* pApp);
	void ProcessConnection(ConnectionInfo* cInfo);
	virtual ~ActionAddConn(void);
	virtual void Execute();

	// Undo & Redo Related Methods
	virtual void Undo();
	virtual void Redo();

};

