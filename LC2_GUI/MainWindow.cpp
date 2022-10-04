#include "MainWindow.h"
#include "GuiRender.h"

MainWindow::MainWindow()
{
	SetupUi();
}

void MainWindow::SetupUi()
{
	centralLayout = new GWidget();
}

void MainWindow::OnSetup()
{
	auto size = GuiRender::GetSize();
	centralLayout->OnSetup();
}
