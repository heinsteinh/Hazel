#pragma once

#include "Hazel/Framebuffer/Framebuffer.h"
#include "Platform/OpenGL/Textures/OpenGLTexture.h"

namespace Hazel
{
	class OpenGLFramebuffer : public Framebuffer
	{
	private:
		uint32_t id;
		FramebufferInfo info;
		std::shared_ptr<OpenGLTexture> colorAttachment;
		std::shared_ptr<OpenGLTexture> depthAttachment;

	public:
		OpenGLFramebuffer(const FramebufferInfo &info);
		virtual ~OpenGLFramebuffer();

		void Bind() const;
		void Unbind() const;
		uint32_t GetStatus() const;
		bool IsComplete() const;
		const std::string &GetStatusName() const;
		void SetColorAttachment(const std::shared_ptr<OpenGLTexture> &colorAttachment);
		void SetDepthAttachment(const std::shared_ptr<OpenGLTexture> &depthAttachment);

		virtual std::shared_ptr<Texture> GetColorAttachement() const override;
		virtual std::shared_ptr<Texture> GetDepthAttachement() const override;

		constexpr uint32_t GetId() const
		{
			return id;
		}

	private:
		void Attach(int attachmentType, const std::shared_ptr<OpenGLTexture> &texture);
	};
}