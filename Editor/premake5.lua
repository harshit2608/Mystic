project "Editor"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

  targetdir("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
  objdir("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

  files
  {
    "src/**.h",
    "src/**.cpp"
  }

  includedirs
  {
		"%{wks.location}/MysticMain/src"
  }

	links
	{
		"MysticMain"
	}

	filter "system:windows"
		systemversion "latest"

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
