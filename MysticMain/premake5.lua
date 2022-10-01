project "MysticMain"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

  targetdir("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
  objdir("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

  pchheader "mcpch.h"
  pchsource "src/mcpch.cpp"

  files
  {
    "src/**.h",
    "src/**.cpp"
  }

	defines
	{
		"_CRT_SECURE_NO_WARNINGS",
		"GLFW_INCLUDE_NONE"
	}

  includedirs
  {
    "src",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.yaml_cpp}"
  }

	links
	{
		"Glad",
		"GLFW"
		-- "yaml-cpp" TODO: Yaml-Cpp fails to build
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
		}

		links
		{
			"opengl32.lib"
		}

	filter "system:macosx"

		defines
		{
		}

	filter "configurations:Debug"
		defines "MC_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "MC_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "MC_DIST"
		runtime "Release"
		optimize "on"
