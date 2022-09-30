newaction{
	trigger = "clean",
	description = "Cleans up the project",
	execute = function()
		print("Removing bin and bin-int directories")
		os.rmdir("./bin")
		os.rmdir("./bin-int")
		os.rmdir("./vendor/yaml-cpp/bin")
		os.rmdir("./vendor/yaml-cpp/bin-int")
		print("Removing MakeFiles")
		os.remove("**Makefile")
		print("Removing Visual Studio files")
		os.remove("**.vcxproj")
		os.remove("**.vcxproj.**")
		print("Done")
	end
}