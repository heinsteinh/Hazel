#include "SandboxLayer.h"

#include "imgui.h"

#include "Hazel/Textures/TextureBuilder.h"
#include "Hazel/Rendering/SquareMesh.h"

namespace Sandbox
{
	SandboxLayer::SandboxLayer(Hazel::Context &context)
		: renderer(context),
		window(context.Window),
		input(context.Input),
		factory(context.Factory),
		camera({context.Window.GetSize().GetAspectRatio()}),
		controller({context.Input, camera}),
		dispatcher(&controller),
		drawData({Hazel::SquareMesh::Get()})
	{
	}

	void SandboxLayer::OnAttach()
	{
		spriteSheet = Hazel::TextureBuilder(factory).BuildFromFile("assets\\textures\\SpriteSheet.png");
		drawData.Mesh.SetColor({1.0f, 1.0f, 1.0f, 1.0f});
		drawData.Texture = spriteSheet;
		drawData.Transform.SetScale({spriteSheet->GetAspectRatio(), 1.0f});
	}

	void SandboxLayer::OnDetach()
	{
	}

	void SandboxLayer::OnUpdate(float deltaTime)
	{
		renderTime = deltaTime;

		controller.OnUpdate(deltaTime);

		drawData.Texture.SetCoordinates({bottomLeft, size});
		//drawData.Transform.SetScale({drawData.Texture.GetAspectRatio(), 1.0f});

		renderer.BeginScene(camera);
		renderer.Draw(drawData);
		renderer.EndScene();
	}

	void SandboxLayer::OnImGuiRender()
	{
		dockspace.Begin();
		ImGui::Begin("Info");
		ImGui::Text("Update Time: %f", renderTime);
		ImGui::Text("Camera Position: %f %f %f", camera.GetPosition().x, camera.GetPosition().y, camera.GetZoomLevel());
		ImGui::Text("Camera Rotation: %fdeg", glm::degrees(camera.GetRotation()));
		ImGui::End();

		ImGui::Begin("Transform");
		ImGui::SliderFloat2("Translation", glm::value_ptr(drawData.Transform.Position), -10.0f, 10.0f);
		ImGui::SliderFloat("Rotation", &drawData.Transform.Angle, 0.0f, glm::radians(360.0f));
		ImGui::SliderFloat2("Scale", glm::value_ptr(drawData.Transform.Scale), 0.0f, glm::radians(360.0f));
		ImGui::End();

		ImGui::Begin("Texture Coordinates");
		ImGui::SliderFloat("Left", &bottomLeft.x, 0.0f, 2560.0f);
		ImGui::SliderFloat("Bottom", &bottomLeft.y, 0.0f, 1664.0f);
		ImGui::SliderFloat("Width", &size.Width, 0.0f, 2560.0f);
		ImGui::SliderFloat("Height", &size.Height, 0.0f, 1664.0f);
		ImGui::End();
		dockspace.End();
	}

	void SandboxLayer::OnEvent(Hazel::Event &e)
	{
		dispatcher.Dispatch(e);
	}

	void SandboxLayer::OnKeyPressed(Hazel::KeyPressEvent &e)
	{
		if (e.GetKey() == Hazel::Key::Backspace)
		{
			camera = Hazel::OrthographicCamera(window.GetAspectRatio());
		}
	}

	void SandboxLayer::OnMouseButtonPressed(Hazel::MouseButtonPressEvent &e)
	{
	}
}