#pragma once

#include "Mystic/Core/Base.h"
#include "Mystic/Log/Log.h"
#include <filesystem>

// TODO: FIX ASSERTS
#ifdef MC_ENABLE_ASSERTS
// #define MC_INTERNAL_ASSERT_IMPL(type, check, msg, ...) \
// 	{                                                    \
// 		if (!(check))                                      \
// 		{                                                  \
// 			if (type == "_CORE_")                            \
// 			{                                                \
// 				MC_CORE_ERROR(msg, __VA_ARGS__)                \
// 			}                                                \
// 			else                                             \
// 			{                                                \
// 				MC_ERROR(msg, __VA_ARGS__)                     \
// 			}                                                \
// 			MC_DEBUGBREAK()                                  \
// 		}                                                  \
// 	}

// #define MC_INTERNAL_ASSERT_WITH_MSG(type, check, ...) MC_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
// #define MC_INTERNAL_ASSERT_NO_MSG(type, check) MC_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", MC_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)

// #define MC_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
// #define MC_INTERNAL_ASSERT_GET_MACRO(...) MC_EXPAND_MACRO(MC_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, MC_INTERNAL_ASSERT_WITH_MSG, MC_INTERNAL_ASSERT_NO_MSG))

// Currently accepts at least the condition and one additional parameter (the message) being optional
#define MC_ASSERT(msg, __VA_ARGS__) MC_EXPAND_MACRO(MC_ERROR(msg, __VA_ARGS__) MC_DEBUGBREAK())
#define MC_CORE_ASSERT(...) MC_EXPAND_MACRO(MC_CORE_ERROR(msg, __VA_ARGS__))
#else
#define MC_ASSERT(...)
#define MC_CORE_ASSERT(...)
#endif