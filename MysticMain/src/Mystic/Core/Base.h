#pragma once

#include "Mystic/Core/PlatformDetection.h"

#ifdef MC_PLATFORM_WINDOWS
#ifdef MC_BUILD_DLL
#define MC_API __declspec(dllexport)
#else
#define MC_API __declspec(dllimport)
#endif
#else
#pragma Mystic DLL only supports Windows !
#define MC_API
#endif

#ifdef MC_DEBUG
#if defined(MC_PLATFORM_WINDOWS)
#define MC_DEBUGBREAK() __debugbreak()
#elif defined(MC_PLATFORM_LINUX)
#include <signal.h>
#define MC_DEBUGBREAK() raise(SIGTRAP)
#elif defined(MC_PLATFORM_MACOS)
#define MC_DEBUGBREAK() __debugbreak()
#else
#error "Platform doesn't support debugbreak yet!"
#endif
#define MC_ENABLE_ASSERTS
#else
#define MC_DEBUGBREAK()
#endif

#define MC_EXPAND_MACRO(x) x
#define MC_STRINGIFY_MACRO(x) #x

#include "Mystic/Core/Assert.h"
