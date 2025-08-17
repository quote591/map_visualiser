#include <memory.h>
#include <memory>

#include <camera.hpp>
#include <window.hpp>

const unsigned int WIN_W = 800;
const unsigned int WIN_H = 400;
const std::string_view windowTitle = "Map visualiser";

int main()
{
	std::unique_ptr<Window> window = 
		std::make_unique<Window>(WIN_W, WIN_H, windowTitle.data());
	window->Init();

	std::unique_ptr<Camera> cam = std::make_unique<Camera>();


	while(true)
	{
		window->UpdateWindow();
	}


	return 0;
}

