@echo off
pushd %~dp0\..\
echo "Generating project for windows with vs2022"
call vendor\premake\bin\premake5.exe vs2022
popd
PAUSE