#include "mcpch.h"

#include "Mystic/Log/Log.h"

namespace Mystic
{
	void Log::Init()
	{
		GetInstance().m_Filepath = "Mystic.log";
		GetInstance().EnableFileOutput();
	}

	void Log::Init(const char *filepath)
	{
		GetInstance().m_Filepath = filepath;
		GetInstance().EnableFileOutput();
	}

	Log &Log::GetInstance()
	{
		static Log m_Logger;
		return m_Logger;
	}

	void Log::CloseFile()
	{
		fclose(m_File);
		m_File = nullptr;
	}

	void Log::EnableFileOutput()
	{
		if (m_File != 0)
		{
			fclose(m_File);
		}

		m_File = fopen(m_Filepath, "a");
		if (m_File == 0)
		{
			printf("Logger: Failed to open file at %s", m_Filepath);
		}
	}
} // namespace Mystic
