#pragma once

namespace Hazel
{
	template<typename FunctorType>
	struct FunctorTraits
		: public FunctorTraits<decltype(&FunctorType::operator())>
	{
	};

	template<typename ClassType, typename ResultType, typename ...Args>
	struct FunctorTraits<ResultType(ClassType:: *)(Args...) const>
	{
		using ReturnType = ResultType;

		template<size_t index>
		struct Arg
		{
			using Type = typename std::tuple_element<index, std::tuple<Args...>>::type;
		};

		template<size_t index>
		using ArgType = typename Arg<index>::Type;

		static constexpr size_t ArgCount = sizeof...(Args);
	};
}