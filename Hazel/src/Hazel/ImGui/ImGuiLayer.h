#pragma once

#include "Hazel/Application/Layer.h"
#include "Private/ImGuiContextHolder.h"
#include "ImGuiRenderer.h"

namespace Hazel
{
	class ImGuiLayer : public Layer
	{
	private:
		std::unique_ptr<ImGuiContextHolder> context;
		std::shared_ptr<ImGuiRenderer> renderer;

	public:
		ImGuiLayer();

		void BeginRender();
		void EndRender();
		bool WantCaptureKeyboard() const;
		bool WantCaptureMouse() const;
		bool WantBlockEvent(Event &e) const;

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnEvent(Event &e) override;
	};
}