#pragma once

#include "glm/glm.hpp"
#include "glm/gtc/quaternion.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "Angle.h"

namespace Hazel
{
    class HAZEL_API Transform
    {
    private:
        glm::vec3 translation{0.0f};
        glm::quat rotation{1.0f, 0.0f, 0.0f, 1.0f};
        glm::vec3 scale{1.0f};

    public:
        Transform() = default;

        Transform(const glm::vec3 &translation, const glm::quat &rotation, const glm::vec3 &scale)
            : translation(translation),
            rotation(rotation),
            scale(scale)
        {
        }

        Transform(const glm::vec2 &translation, Angle rotation, const glm::vec2 &scale)
            : translation(translation.x, translation.y, 0.0f),
            rotation(glm::angleAxis(rotation.ToRadians(), glm::vec3(0.0f, 0.0f, 1.0f))),
            scale(scale.x, scale.y, 1.0f)
        {
        }

        inline void Translate(const glm::vec3 &translation)
        {
            this->translation += translation;
        }

        inline void TranslateX(float translation)
        {
            this->translation.x += translation;
        }

        inline void TranslateY(float translation)
        {
            this->translation.y += translation;
        }

        inline void TranslateZ(float translation)
        {
            this->translation.z += translation;
        }

        inline void Rotate(Angle angle)
        {
            rotation = glm::rotate(rotation, angle.ToRadians(), glm::vec3(0.0f, 0.0f, 1.0f));
        }

        inline void Scale(float scale)
        {
            this->scale *= scale;
        }

        inline glm::mat4 Apply(const glm::mat4 &matrix) const
        {
            return glm::scale(
                glm::rotate(
                    glm::translate(
                        matrix,
                        translation),
                    glm::angle(rotation),
                    glm::axis(rotation)),
                scale);
        }

        inline glm::mat4 ApplyWithoutRotation(const glm::mat4 &matrix) const
        {
            return glm::scale(
                glm::translate(
                    matrix,
                    translation),
                scale);
        }

        inline glm::mat4 ToMatrix() const
        {
            return Apply(glm::mat4(1.0f));
        }

        inline glm::mat4 ToMatrixWithoutRotation() const
        {
            return ApplyWithoutRotation(glm::mat4(1.0f));
        }
    };
}