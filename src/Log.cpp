//
// Created by Tomáš Tatyrek on 15/03/2025.
//

#include "TT2D/Log.h"
#include "SDL3/SDL.h"

namespace TT2D {

	void Log(LogCategory category, LogPriority priority, const char* message) {

		SDL_LogMessage(category, static_cast<SDL_LogPriority>(priority), "%s", message);

	}

	void Log(const char* message) {

		SDL_Log("%s", message);

	}

	void LogInvalid(LogCategory category, const char *message) {

		Log(category, TT2D_LOG_PRIORITY_INVALID, message);

	}

	void LogTrace(LogCategory category, const char *message) {

		Log(category, TT2D_LOG_PRIORITY_TRACE, message);

	}

	void LogVerbose(LogCategory category, const char *message) {

		Log(category, TT2D_LOG_PRIORITY_VERBOSE, message);

	}

	void LogDebug(LogCategory category, const char *message) {

		Log(category, TT2D_LOG_PRIORITY_DEBUG, message);

	}

	void LogInfo(LogCategory category, const char *message) {

		Log(category, TT2D_LOG_PRIORITY_INFO, message);

	}

	void LogWarn(LogCategory category, const char *message) {

		Log(category, TT2D_LOG_PRIORITY_WARN, message);

	}

	void LogError(LogCategory category, const char *message) {

		Log(category, TT2D_LOG_PRIORITY_ERROR, message);

	}

	void LogCritical(LogCategory category, const char *message) {

		Log(category, TT2D_LOG_PRIORITY_CRITICAL, message);

	}

	void LogCount(LogCategory category, const char *message) {

		Log(category, TT2D_LOG_PRIORITY_COUNT, message);

	}

} // TT2D