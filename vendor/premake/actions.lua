newaction{
	trigger = "clean",
	description = "Cleans up the project",
	execute = function()
		print("Removing bin and bin-int directories")
		os.rmdir("./bin")
		os.rmdir("./bin-int")
		print("Removing MakeFiles")
		os.remove("**Makefile")
		print("Done")
	end
}