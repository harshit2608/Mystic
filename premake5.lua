include "./vendor/premake/premake_customization/solution_items.lua"

workspace "Mystic"
	architecture "x86_64"
  startproject "MysticMain"

  configurations
  {
    "Debug",
		"Release",
		"Dist"
  }

	solution_items
	{
		".editorconfig"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Dependencies"
	include "vendor/premake"
group ""

group "Core"
	include "MysticMain"
group ""

group "Tools"
	include "Editor"
group ""