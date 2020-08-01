#include "Layer2D.h"

#include "imgui.h"

#include "Hazel/Rendering/Textures/TextureBuilder.h"

namespace Sandbox
{
	Layer2D::Layer2D(Hazel::Context &context)
		: settings(context.Settings),
		renderer(context),
		input(context.Input),
		factory(context.Factory),
		camera({context.Window.GetSize().GetAspectRatio()}),
		controller({context.Input, camera}),
		dispatcher(&controller)
	{
	}

	void Layer2D::OnAttach()
	{
		//texture = Hazel::TextureBuilder(factory).Build("assets\\textures\\Test.jpg");
	}

	void Layer2D::OnDetach()
	{
	}

	void Layer2D::OnUpdate(float deltaTime)
	{
		framerate = 1.0f / deltaTime;

		controller.OnUpdate(deltaTime);

		renderer.BeginScene(camera);
		renderer.EndScene();
	}

	void Layer2D::OnImGuiRender()
	{
	}

	void Layer2D::OnEvent(Hazel::Event &e)
	{
		Hazel::EventDispatcher(&controller).Dispatch(e);
	}

	void Layer2D::OnKeyPressed(Hazel::KeyPressEvent &e)
	{
	}
}