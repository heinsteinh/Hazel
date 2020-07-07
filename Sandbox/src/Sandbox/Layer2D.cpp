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
		cameraController({context.Window.GetSize().GetAspectRatio()})
	{
	}

	void Layer2D::OnAttach()
	{
		texture = Hazel::TextureBuilder(factory).Build("assets\\textures\\Test.jpg");
		rectangles.emplace_back(color, texture);
	}

	void Layer2D::OnDetach()
	{
	}

	void Layer2D::OnUpdate(float deltaTime)
	{
		framerate = 1.0f / deltaTime;

		if (input.IsKeyPressed(Hazel::Key::Up))
		{
			translation.y += 1.0f * deltaTime;
		}
		if (input.IsKeyPressed(Hazel::Key::Down))
		{
			translation.y -= 1.0f * deltaTime;
		}
		if (input.IsKeyPressed(Hazel::Key::Right))
		{
			translation.x += 1.0f * deltaTime;
		}
		if (input.IsKeyPressed(Hazel::Key::Left))
		{
			translation.x -= 1.0f * deltaTime;
		}

		if (input.IsKeyPressed(Hazel::Key::W))
		{
			cameraTranslation.y += 1.0f * deltaTime;
		}
		if (input.IsKeyPressed(Hazel::Key::S))
		{
			cameraTranslation.y -= 1.0f * deltaTime;
		}
		if (input.IsKeyPressed(Hazel::Key::D))
		{
			cameraTranslation.x += 1.0f * deltaTime;
		}
		if (input.IsKeyPressed(Hazel::Key::A))
		{
			cameraTranslation.x -= 1.0f * deltaTime;
		}
		if (input.IsKeyPressed(Hazel::Key::Q))
		{
			cameraRotation += 90.0f * deltaTime;
		}
		if (input.IsKeyPressed(Hazel::Key::E))
		{
			cameraRotation -= 90.0f * deltaTime;
		}

		rectangles[0].SetColor(color);

		auto &transform = rectangles[0].GetTransform();
		transform.SetTranslation({translation.x, translation.y, 0.0f});
		transform.SetRotation(glm::angleAxis(glm::radians(rotation), glm::vec3(0.0f, 0.0f, 1.0f)));
		transform.SetScale({scale.x, scale.y, 1.0f});

		auto &camera = cameraController.GetCamera();
		camera.Position = {cameraTranslation.x, cameraTranslation.y, 0.0f};
		camera.Rotation = glm::radians(cameraRotation);
		camera.SetZoomLevel(zoomLevel);

		renderer.BeginScene(camera);
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
		if (showTransform)
		{
			ImGui::Begin("Transform", &showTransform);
			ImGui::SliderFloat2("Translation", glm::value_ptr(translation), -1.0f, 1.0f);
			ImGui::SliderFloat("Rotation", &rotation, -180.0f, 180.0f);
			ImGui::SliderFloat2("Scale", glm::value_ptr(scale), 0.1f, 3.0f);
			ImGui::End();
		}
		if (showCamera)
		{
			ImGui::Begin("Camera", &showCamera);
			ImGui::SliderFloat2("Translation", glm::value_ptr(cameraTranslation), -1.0f, 1.0f);
			ImGui::SliderFloat("Rotation", &cameraRotation, -180.0f, 180.0f);
			ImGui::SliderFloat("Zoom", &zoomLevel, 0.1f, 10.0f);
			ImGui::End();
		}
	}

	void Layer2D::OnWindowResized(Hazel::WindowResizeEvent &e)
	{
		cameraController.OnWindowResized(e.GetSize());
	}

	void Layer2D::OnKeyPressed(Hazel::KeyPressEvent &e)
	{
		switch (e.GetKey())
		{
		case Hazel::Key::C:
			showImGui = showFps = showColorPicker = showTransform = showCamera = true;
		case Hazel::Key::Backspace:
			color = glm::vec4(1.0f);
			translation = glm::vec2(0.0f);
			rotation = 0.0f;
			scale = glm::vec2(1.0f);
			cameraTranslation = glm::vec2(0.0f);
			cameraRotation = 0.0f;
			zoomLevel = 1.0f;
			break;
		case Hazel::Key::I:
			settings.ShowImGui(showImGui = !showImGui);
		}
	}

	void Layer2D::OnMouseScrolled(Hazel::MouseScrollEvent &e)
	{
		zoomLevel = std::clamp(zoomLevel + 0.2f * e.GetYOffset(), 0.1f, 10.0f);
	}
}