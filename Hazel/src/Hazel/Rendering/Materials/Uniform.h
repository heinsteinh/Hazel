#pragma once

#include "Hazel/Rendering/Meshes/VertexHelper.h"
#include "Hazel/Rendering/Meshes/ByteArray.h"

namespace Hazel
{
	class Uniform
	{
	private:
		VertexLayout layout;
		ByteArray data;

	public:
		Uniform() = default;

		Uniform(const VertexLayout &layout)
			: layout(layout),
			data(layout.GetStride(), 1)
		{
		}

		const VertexLayout &GetLayout() const
		{
			return layout;
		}

		void SetLayout(const VertexLayout &layout)
		{
			this->layout = layout;
			data.SetItemSize(layout.GetStride());
			data.SetItemCount(1);
		}

		const void *GetData() const
		{
			return data.GetData();
		}

		size_t GetSize() const
		{
			return data.GetSize();
		}

		const void *GetAttribute(size_t index) const
		{
			return VertexHelper::GetAttribute(layout, data.GetData(), index);
		}

		void *GetAttribute(size_t index)
		{
			return VertexHelper::GetAttribute(layout, data.GetData(), index);
		}

		template<typename T, typename ...Args>
		T &Init(const VertexLayout &layout, Args &&...args)
		{
			SetLayout(layout);
			return data.Construct<T>(0, std::forward<Args>(args)...);
		}

		template<typename T>
		T &As()
		{
			return VertexHelper::Convert<T>(layout, data.GetData());
		}

		template<typename T>
		const T &As() const
		{
			return VertexHelper::Convert<T>(layout, data.GetData());
		}

		template<typename T>
		const T &GetAttribute(size_t index) const
		{
			return VertexHelper::GetAttribute<T>(layout, data.GetData(), index);
		}

		template<typename T>
		T &GetAttribute(size_t index)
		{
			return VertexHelper::GetAttribute<T>(layout, data.GetData(), index);
		}
	};
}