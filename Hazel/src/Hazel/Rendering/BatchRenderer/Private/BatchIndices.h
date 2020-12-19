#pragma once

#include "BatchArray.h"
#include "Hazel/Rendering/GraphicsContext/IndexFormatHelper.h"
#include "Hazel/Core/Exceptions/AssertionException.h"

namespace Hazel
{
	class BatchIndices
	{
	private:
		IndexFormat format;
		BatchArray<uint8_t> data8;
		BatchArray<uint16_t> data16;
		BatchArray<uint32_t> data32;

	public:
		BatchIndices(size_t maxIndexCount = 0, IndexFormat format = IndexFormat::UInt32);

		size_t GetMaxIndexCount() const;
		void SetMaxIndexCount(size_t maxIndexCount);
		size_t GetIndexCount() const;
		void SetIndexCount(size_t indexCount);
		void Clear();
		bool CanContain(size_t indexCount) const;
		void Add(uint32_t index);
		const void *GetData() const;
		size_t GetSize() const;
	};
}