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

  includedirs
  {
    "src",
		"%{IncludeDir.yaml_cpp}"
  }

	filter "system:windows"
		systemversion "latest"

		defines
		{
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
