#include "Layer2D.h"

#include "imgui.h"

#include "Hazel/Rendering/Textures/TextureBuilder.h"

namespace Sandbox
{
	Layer2D::Layer2D(Hazel::Application &application)
		: application(application),
		renderer(application.GetContext()),
		input(application.GetContext().Input),
		drawer(application.GetContext().Drawer),
		cameraController(application.GetContext())
	{
	}

	void Layer2D::OnAttach()
	{
		texture = Hazel::TextureBuilder(application.GetContext().Factory).Build("assets\\textures\\Test.jpg");
		rectangles.emplace_back(color, texture);
	}

	void Layer2D::OnDetach()
	{
	}

	void Layer2D::OnUpdate(float deltaTime)
	{
		framerate = 1.0f / deltaTime;

		drawer.Clear();

		cameraController.OnUpdate(deltaTime);

		float speed = 1.0f;
		glm::vec3 translation(0.0f);

		if (input.IsKeyPressed(Hazel::Key::Up))
		{
			translation.y += speed * deltaTime;
		}
		if (input.IsKeyPressed(Hazel::Key::Down))
		{
			translation.y -= speed * deltaTime;
		}
		if (input.IsKeyPressed(Hazel::Key::Left))
		{
			translation.x -= speed * deltaTime;
		}
		if (input.IsKeyPressed(Hazel::Key::Right))
		{
			translation.x += speed * deltaTime;
		}

		if (translation.x || translation.y)
		{
			rectangles[0].GetTransform().Translation += translation;
		}
		rectangles[0].SetColor(color);

		renderer.BeginScene(cameraController.GetCamera());
		renderer.Draw(rectangles[0]);
		renderer.EndScene();
	}

	void Layer2D::OnImGuiRender()
	{
		if (showFps)
		{
			ImGui::Begin("Framerate", &showFps);
			ImGui::Text("%.2f FPS", framerate);
			ImGui::End();
		}
		if (showColorPicker)
		{
			ImGui::Begin("Settings", &showColorPicker);
			ImGui::ColorPicker4("Color", glm::value_ptr(color));
			ImGui::End();
		}
	}

	void Layer2D::OnEvent(Hazel::Event &e)
	{
		e.Dispatch(&cameraController);
	}

	void Layer2D::OnKeyPressed(Hazel::KeyPressEvent &e)
	{
		switch (e.GetKey())
		{
		case Hazel::Key::R:
			cameraController.SetRotationEnabled(!cameraController.HasRotationEnabled());
			break;
		case Hazel::Key::C:
			showFps = showColorPicker = true;
			break;
		case Hazel::Key::Backspace:
			color = {1.0f, 0.0f, 0.0f, 1.0f};
			rectangles[0].GetTransform() = Hazel::Transform();
			break;
		case Hazel::Key::I:
			application.ShowImGui(showImGui = !showImGui);
		}
	}
}