#pragma once

#include "Hazel/Rendering/Textures/Texture.h"
#include "Hazel/Utils/Rectangle.h"

namespace Hazel
{
    class HAZEL_API RectangularSprite
    {
    private:
        SharedPtr<Texture> texture;
        glm::vec4 color{1.0f};
        glm::mat4 transform{1.0f};

    public:
        RectangularSprite() = default;

        RectangularSprite(const Rectangle &rectangle)
            : transform(rectangle.GetTransform().ToMatrixWithoutRotation())
        {
        }

        inline const SharedPtr<Texture> &GetTexture() const
        {
            return texture;
        }

        inline const glm::vec4 &GetColor() const
        {
            return color;
        }

        inline const glm::mat4 &GetTransform() const
        {
            return transform;
        }

        inline void SetTexture(const SharedPtr<Texture> &texture)
        {
            this->texture = texture;
        }

        inline void SetColor(const glm::vec4 &color)
        {
            this->color = color;
        }

        inline void SetTransform(const glm::mat4 &transform)
        {
            this->transform = transform;
        }
    };
}