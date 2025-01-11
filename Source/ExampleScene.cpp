#include "ExampleScene.h"
#include "Random.h"

bool ExampleScene::Initialize()
{
	m_renderer.Initialize();
	m_renderer.CreateWindow("Example", 800, 600);

	m_input.Initialize();
	m_input.Update();

	m_framebuffer = std::make_unique<Framebuffer>(m_renderer, m_renderer.m_width, m_renderer.m_height);

	return true;
}

void ExampleScene::Draw()
{
	m_framebuffer->Clear(color_t{ 0, 0, 0, 255 });


	m_framebuffer->DrawPoint(100, 100, color_t{ (uint8_t)random(m_renderer.m_width), (uint8_t)random(m_renderer.m_height), 255, 255 });


	// update framebuffer
	m_framebuffer->Update();

	// show screen
	m_renderer = *m_framebuffer;
	SDL_RenderPresent(m_renderer.m_renderer);
}
