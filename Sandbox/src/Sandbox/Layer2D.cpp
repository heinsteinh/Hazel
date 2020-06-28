#include "Layer2D.h"

#include "imgui.h"

#include "Hazel/Rendering/Textures/TextureBuilder.h"

namespace Sandbox
{
	Layer2D::Layer2D(Hazel::Application &application)
		: application(application),
		renderer(application.GetContext()),
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

		application.GetContext().Drawer.Clear();

		cameraController.OnUpdate(deltaTime);

		float speed = 0.1f;

		glm::vec3 translation(0.0f);
		auto &input = application.GetContext().Input;
		if (input.IsKeyPressed(Hazel::Key::Up))
		{
			translation.x += speed;
		}
		if (input.IsKeyPressed(Hazel::Key::Down))
		{
			translation.x -= speed;
		}
		if (input.IsKeyPressed(Hazel::Key::Right))
		{
			translation.y += speed;
		}
		if (input.IsKeyPressed(Hazel::Key::Left))
		{
			translation.y -= speed;
		}
		rectangles[0].Translate(translation);
		if (translation.x || translation.y || translation.z)
		{
			rectangles[0].ApplyTransform();
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
		case Hazel::Key::Backspace:
			color = {1.0f, 0.0f, 0.0f, 1.0f};
			break;
		case Hazel::Key::I:
			application.ShowImGui(showImGui = !showImGui);
		}
	}
}