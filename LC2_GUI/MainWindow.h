#pragma once
#include "stdafx.h"
#include "GWidget.h"

class MainWindow :public GWidget
{
public:
	MainWindow();
	GWidget* centralLayout;
	void SetupUi();
	void OnSetup();


};

