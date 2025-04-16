@echo off
set str=%1
set str=%str:~0,2%
%str%
cd %1
%1\NuLink.exe -C 
%1\NuLink.exe -E ALL
%1\NuLink.exe -W APROM %2
%1\NuLink.exe -V APROM %2
%1\NuLink.exe -S
exit 0
