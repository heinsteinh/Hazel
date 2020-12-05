#pragma once

#include "VectorUI.h"
#include "Hazel/Geometry/Transform.h"

namespace Hazel
{
	class TransformUI
	{
	private:
		VectorUI translationUI;
		VectorUI rotationUI;
		VectorUI scaleUI;

	public:
		TransformUI();

		void Draw(const char *label, Transform &transform);
	};
}