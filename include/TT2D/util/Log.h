//
// Created by Tomáš Tatyrek on 15/03/2025.
//

#ifndef TT2D_LOG_H
#define TT2D_LOG_H

#ifndef TT2D_ENABLE_LOGGING
#define TT2D_ENABLE_LOGGING true  //<-- set to false to disable logging
#endif //TT2D_ENABLE_LOGGING

// Defines logging macros - should be used in the program
#if (TT2D_ENABLE_LOGGING)
#define TT2D_LOG(x) TT2D::log(x)
#define TT2D_LOG_INFO(x) TT2D::logInfo(x)
#define TT2D_LOG_WARN(x) TT2D::logWarn(x)
#define TT2D_LOG_ERROR(x) TT2D::logError(x)
#define TT2D_LOG_CRITICAL(x) TT2D::logCritical(x)
#define TT2D_LOG_DEBUG(x) TT2D::logDebug(x)
#define TT2D_LOG_TRACE(x) TT2D::logTrace(x)
#define TT2D_LOG_VERBOSE(x) TT2D::logVerbose(x)
#define TT2D_LOG_INVALID(x) TT2D::logInvalid(x)
#define TT2D_LOG_COUNT(x) TT2D::logCount(x)
#endif //TT2D_ENABLE_LOGGING

#include "SDL3/SDL.h"

namespace TT2D {

	enum LogCategory {

		TT2D_LOG_CATEGORY_APPLICATION = SDL_LOG_CATEGORY_CUSTOM,
		TT2D_LOG_CATEGORY_ERROR,
		TT2D_LOG_CATEGORY_ASSERT,
		TT2D_LOG_CATEGORY_SYSTEM,
		TT2D_LOG_CATEGORY_AUDIO,
		TT2D_LOG_CATEGORY_VIDEO,
		TT2D_LOG_CATEGORY_RENDER,
		TT2D_LOG_CATEGORY_INPUT,
		TT2D_LOG_CATEGORY_TEST,
		TT2D_LOG_CATEGORY_GPU,

		TT2D_LOG_CATEGORY_RESERVED1,
		TT2D_LOG_CATEGORY_RESERVED2,
		TT2D_LOG_CATEGORY_RESERVED3,
		TT2D_LOG_CATEGORY_RESERVED4,
		TT2D_LOG_CATEGORY_RESERVED5,
		TT2D_LOG_CATEGORY_RESERVED6,
		TT2D_LOG_CATEGORY_RESERVED7,
		TT2D_LOG_CATEGORY_RESERVED8,
		TT2D_LOG_CATEGORY_RESERVED9,

		TT2D_LOG_CATEGORY_CUSTOM

	};

	enum LogPriority {

		TT2D_LOG_PRIORITY_INVALID = SDL_LOG_PRIORITY_INVALID,
		TT2D_LOG_PRIORITY_TRACE,
		TT2D_LOG_PRIORITY_VERBOSE,
		TT2D_LOG_PRIORITY_DEBUG,
		TT2D_LOG_PRIORITY_INFO,
		TT2D_LOG_PRIORITY_WARN,
		TT2D_LOG_PRIORITY_ERROR,
		TT2D_LOG_PRIORITY_CRITICAL,
		TT2D_LOG_PRIORITY_COUNT

	};

	void Log(LogCategory category, LogPriority priority, const char* message);
	void Log(const char* message);
	void LogInvalid(LogCategory category, const char* message);
	void LogTrace(LogCategory category, const char* message);
	void LogVerbose(LogCategory category, const char* message);
	void LogDebug(LogCategory category, const char* message);
	void LogInfo(LogCategory category, const char* message);
	void LogWarn(LogCategory category, const char* message);
	void LogError(LogCategory category, const char* message);
	void LogCritical(LogCategory category, const char* message);
	void LogCount(LogCategory category, const char* message);

} // TT2D

#endif //TT2D_LOG_H