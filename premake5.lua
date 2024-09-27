projectName = "spdlogWrapper"

workspace "spdlogWrapper"
	architecture "x86"

	configurations
	{
		"Debug",
		"Release"
	}

project "spdlogWrapper"
	location "%{prj.name}"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

	targetdir ("bin/")
	objdir ("build/")
	debugdir "./%{prj.name}"
	
	files
	{
		"./%{prj.name}/include/**.h",
		"./%{prj.name}/source/**.cpp",
	}

	includedirs
	{
		"./%{prj.name}/include/",
		"./spdlog/include",
	}

	includedirs
	{
		"include/",
		"./spdlog/",
	}
		
			-- Clean Function --
newaction {
   trigger     = "clean",
   description = "clean the build",
   execute     = function ()
      os.rmdir("./build")
	  os.rmdir("./bin")
	  os.remove(projectName .. "/" .. projectName .. ".vcxproj")
	  os.remove(projectName .. "/" .. projectName .. ".vcxproj.user")
	  os.remove(projectName .. "/" .. projectName .. ".vcxproj.filters")
	  os.remove("*.sln")
   end
}