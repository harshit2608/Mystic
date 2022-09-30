#include "mcpch.h"

#include "Systems/Configuration.h"

#include <yaml-cpp/yaml.h>

namespace Mystic
{
	bool Configuration::ReadConfig()
	{
		const std::string filepath = "Config/config.yaml";
		return Deserialize(filepath);
	}

	bool Configuration::ReadConfig(const std::string &filepath)
	{
		return Deserialize(filepath);
	}

	bool Configuration::Deserialize(const std::string &filepath)
	{
		YAML::Node config;
		try
		{
			config = YAML::LoadFile(filepath);
		}
		catch (YAML::ParserException e)
		{
			MC_CORE_ERROR("Failed to load .hazel file '{0}'\n {1}", filepath.c_str(), e.what())
		}

		if (!config["Configurations"])
		{
			return false;
		}
		return false;
	}
} // namespace Mystic
