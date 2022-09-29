#pragma once

#include "Mystic/Core/Application.h"
#include "Mystic/Log/Log.h"

extern Mystic::Application *Mystic::CreateApplication();

int main(int argc, const char **argv)
{
	Mystic::Log::Init();
	Mystic::Application *app = Mystic::CreateApplication();
	app->Run();
	delete app;
}