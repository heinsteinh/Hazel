#pragma once

#include "Hazel.h"

namespace Sandbox
{
	class SandboxLayer : public Hazel::Layer
	{
	private:
		std::shared_ptr<Hazel::Renderer2D> renderer;
		Hazel::SubTexture spriteSheet;
		std::shared_ptr<Hazel::Scene> scene;
		Hazel::Entity square;
		Hazel::Entity camera1;
		Hazel::Entity camera2;

	public:
		SandboxLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnEvent(Hazel::Event &e) override;
		virtual void OnUpdate() override;
		virtual void OnGui() override;
	};
}