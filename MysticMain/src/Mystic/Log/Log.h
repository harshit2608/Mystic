#pragma once

#include "Mystic/Core/Base.h"
#include "Mystic/Log/ColorCodes.h"

#include <stdio.h>
#include <mutex>
#include <string>
#include <ctime>

// TODO: Allow string to be passed in the logs
namespace Mystic
{
	enum LogPriority
	{
		TracePriority = 0,
		InfoPriority,
		WarnPriority,
		ErrorPriority,
		CriticalPriority
	};

	enum class LogUser
	{
		Core = 0,
		Application
	};

	class MC_API Log
	{
	public:
		static void Init();
		static void Init(const char *filepath);

		template <typename... Args>
		static void Trace(int line, const char *sourceFile, LogUser logUser, const char *color, const char *message, Args... args)
		{
			GetInstance().WriteLog(line, sourceFile, logUser, color, "[Trace] : ", TracePriority, message, args...);
		}

		template <typename... Args>
		static void Info(int line, const char *sourceFile, LogUser logUser, const char *color, const char *message, Args... args)
		{
			GetInstance().WriteLog(line, sourceFile, logUser, color, "[Info] : ", InfoPriority, message, args...);
		}

		template <typename... Args>
		static void Warn(int line, const char *sourceFile, LogUser logUser, const char *color, const char *message, Args... args)
		{
			GetInstance().WriteLog(line, sourceFile, logUser, color, "[Warn] : ", WarnPriority, message, args...);
		}

		template <typename... Args>
		static void Error(int line, const char *sourceFile, LogUser logUser, const char *color, const char *message, Args... args)
		{
			GetInstance().WriteLog(line, sourceFile, logUser, color, "[Error] : ", ErrorPriority, message, args...);
		}

		template <typename... Args>
		static void Critical(int line, const char *sourceFile, LogUser logUser, const char *color, const char *message, Args... args)
		{
			GetInstance().WriteLog(line, sourceFile, logUser, color, "[Critical] : ", CriticalPriority, message, args...);
		}

	private:
		LogPriority m_Priority = LogPriority::TracePriority;
		std::mutex m_LogMutex;
		const char *m_Filepath;
		FILE *m_File = nullptr;

	private:
		Log()
		{
			// printf("Cons calleed");
		}
		~Log()
		{
			// printf("DEStructor calleed");
			CloseFile();
		}

		Log(Log &other) = delete;
		void operator=(const Log &other) = delete;

		static Log &GetInstance();

	private:
		void CloseFile();
		void EnableFileOutput();

		template <typename... Args>
		void WriteLog(int line, const char *sourceFile, LogUser logUser, const char *color, const char *messagePriorityStr, LogPriority messagePriority, const char *message, Args... args)
		{
			char *logger;
			switch (logUser)
			{
			case LogUser::Core:
				logger = (char *)"Mystic";
				break;
			case LogUser::Application:
				logger = (char *)"App";
				break;
			default:
				break;
			}
			if (m_Priority <= messagePriority)
			{
				std::time_t current_time = std::time(0);
				std::tm *timestamp = std::localtime(&current_time);
				char buffer[80];
				strftime(buffer, 80, "%I:%M:%S %p", timestamp);

				std::scoped_lock lock(m_LogMutex);
				printf("%s", color);
				printf("[%s]", buffer);
				printf("[%s]: ", logger);
				//printf("%s", messagePriorityStr);
				printf(message, args...);
				// printf(" on line %d in %s ", line, sourceFile);
				printf(Reset);
				printf("\n");

				if (m_File)
				{
					fprintf(m_File, "[%s]", buffer);
					fprintf(m_File, "[%s]", logger);
					fprintf(m_File, "%s", messagePriorityStr);
					fprintf(m_File, message, args...);
					fprintf(m_File, " on line %d in %s ", line, sourceFile);
					fprintf(m_File, "\n");
				}
			}
		}
	};
} // namespace Mystic

#define MC_TRACE(message, ...) ::Mystic::Log::Trace(__LINE__, __FILE__, ::Mystic::LogUser::Application, White, message, __VA_ARGS__);
#define MC_WARN(message, ...) ::Mystic::Log::Warn(__LINE__, __FILE__, ::Mystic::LogUser::Application, Yellow, message, __VA_ARGS__);
#define MC_INFO(message, ...) ::Mystic::Log::Info(__LINE__, __FILE__, ::Mystic::LogUser::Application, Green, message, __VA_ARGS__);
#define MC_ERROR(message, ...) ::Mystic::Log::Error(__LINE__, __FILE__, ::Mystic::LogUser::Application, Red, message, __VA_ARGS__);
#define MC_CRITICAL(message, ...) ::Mystic::Log::Critical(__LINE__, __FILE__, ::Mystic::LogUser::Application, Magenta, message, __VA_ARGS__);

#define MC_CORE_TRACE(message, ...) ::Mystic::Log::Trace(__LINE__, __FILE__, ::Mystic::LogUser::Core, White, message, __VA_ARGS__);
#define MC_CORE_WARN(message, ...) ::Mystic::Log::Warn(__LINE__, __FILE__, ::Mystic::LogUser::Core, Yellow, message, __VA_ARGS__);
#define MC_CORE_INFO(message, ...) ::Mystic::Log::Info(__LINE__, __FILE__, ::Mystic::LogUser::Core, Green, message, __VA_ARGS__);
#define MC_CORE_ERROR(message, ...) ::Mystic::Log::Error(__LINE__, __FILE__, ::Mystic::LogUser::Core, Red, message, __VA_ARGS__);
#define MC_CORE_CRITICAL(message, ...) ::Mystic::Log::Critical(__LINE__, __FILE__, ::Mystic::LogUser::Core, WhiteOnRed, message, __VA_ARGS__);
