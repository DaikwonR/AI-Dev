#include "ExampleScene.h"
#include "CAScene.h"
#include "GOL.h"
#include <memory>
#include <SDL.h>

int main(int, char**)
{
	//std::unique_ptr<ExampleScene> scene = std::make_unique<ExampleScene>();
	//std::unique_ptr<CAScene> scene = std::make_unique<CAScene>();
	std::unique_ptr<GOL> scene = std::make_unique<GOL>();

	scene->Initialize();
	while (!scene->IsQuit())
	{
		scene->Update();
		scene->Draw();
	}

	return 0;
}