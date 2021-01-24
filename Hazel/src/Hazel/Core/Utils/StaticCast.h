#pragma once

#include <memory>

#include "Hazel/Core/Exceptions/AssertionException.h"

namespace Hazel
{
	class StaticCast
	{
	public:
		template<typename DestinationType, typename SourceType>
		static DestinationType *Convert(SourceType *source)
		{
			HZ_ASSERT(!source || dynamic_cast<Destination Type *>(source), "Invalid conversion");
			return static_cast<DestinationType *>(source);
		}

		template<typename DestinationType, typename SourceType>
		static std::shared_ptr<DestinationType> Convert(const std::shared_ptr<SourceType> &source)
		{
			HZ_ASSERT(!source || std::dynamic_pointer_cast<DestinationType>(source), "Invalid conversion");
			return std::static_pointer_cast<DestinationType>(source);
		}
	};
}