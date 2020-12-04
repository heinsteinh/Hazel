#pragma once

#include "VectorUI.h"
#include "Hazel/Geometry/Transform.h"

namespace Hazel
{
	class TransformUI
	{
	private:
		static inline const std::string translationTitle = "Translation";
		static inline const std::string rotationTitle = "Rotation";
		static inline const std::string scaleTitle = "Scale";

		VectorUI translationUI;
		VectorUI rotationUI;
		VectorUI scaleUI;

	public:
		TransformUI();

		void Draw(const std::string &label, Transform &transform);
	};
}