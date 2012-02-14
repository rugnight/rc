solution "RC_GAME"
   configurations { "Debug", "Release" }
   platforms { "native" }
   --platforms { "universal64" }
   --platforms { "universal32" }
   --platforms { "Universal" }
   --platforms { "x32" }

   -- ===================================== --
   -- Project "rcTest"                      --
   project "rcTest"
      kind "ConsoleApp" -- WindowedApp or ColsoleApp
      language "C++"
      files { 
          "project/rcTest/src/**.h",
          "project/rcTest/src/**.cpp" 
      }

      includedirs { -- -I/usr/include/openglに相当
          "project/rcBase/src",
          "project/rcMath/src",
      }
      libdirs { -- -L/usr/lib/w32apiに相当
      }
      links { -- -lopengl32 -lglu32 -lglut32 に相当
        "rcMath"
      }

      configuration "Debug"
         defines { "DEBUG" } -- -DDEBUG
         flags { "Symbols" }
         targetdir "project/rcTest/debug"
         targetname "rcTest_debug"

      configuration "Release"
         defines { "NDEBUG" } -- -NDEBUG
         flags { "Optimize" }
         targetdir "project/rcTest/release"
         targetname "rcTest"
   -- Project "rcTest"                      --
   -- ===================================== --

   -- ===================================== --
   -- Project "rcBase"                      --
   project "rcBase"
      kind "StaticLib" -- WindowedApp or ColsoleApp or StaticLib
      language "C++"
      files { 
          "project/rcBase/src/**.h",
          "project/rcBase/src/**.cpp" 
      }

      includedirs { -- -I/usr/include/openglに相当
      }
      libdirs { -- -L/usr/lib/w32apiに相当
      }
      links { -- -lopengl32 -lglu32 -lglut32 に相当
      }
      configuration "Debug"
         defines { "DEBUG" } -- -DDEBUG
         flags { "Symbols" }
         targetdir "project/rcBase/debug"
         targetname "rcBase_debug"

      configuration "Release"
         defines { "NDEBUG" } -- -NDEBUG
         flags { "Optimize" }
         targetdir "project/rcBase/release"
         targetname "rcBase"
   -- Project "rcBase"                      --
   -- ===================================== --

   --[[
   -- ===================================== --
   -- Project "rcGraphic"                   --
   project "rcGraphic"
      kind "StaticLib" -- WindowedApp or ColsoleApp or StaticLib
      language "C++"
      files { 
          "project/rcGraphic/src/**.h",
          "project/rcGraphic/src/**.cpp" 
      }

      includedirs { -- -I/usr/include/openglに相当
          "/System/Library/Frameworks/OpenGL.framework/Headers/",
          --"/Developer/SDKs/MacOSX10.7.sdk/System/Library/Frameworks/GLUT.framework/Versions/A/Headers/",

          "project/rcBase/src",
      }
      libdirs { -- -L/usr/lib/w32apiに相当
          "/System/Library/Frameworks/OpenGL.framework/Libraries/"
      }
      links { -- -lopengl32 -lglu32 -lglut32 に相当
          --"GL", "GLU", 
      }
   -- Project "rcGraphic"                   --
   -- ===================================== --
   ]]

   -- ===================================== --
   -- Project "rcMatn"                      --
   project "rcMath"
      location "project/rcMath/build"  
      kind "StaticLib" -- WindowedApp or ColsoleApp or StaticLib
      language "C++"
      files { 
          "project/rcMath/src/**.h",
          "project/rcMath/src/**.cpp" 
      }

      includedirs { -- -I/usr/include/openglに相当
        "project/rcBase/src/",
      }
      libdirs { -- -L/usr/lib/w32apiに相当
        ""
      }
      links { -- -lopengl32 -lglu32 -lglut32 に相当
        "rcBase"
      }
      configuration "Debug"
          defines { "_DEBUG" }
          flags { "Symbols" }
          targetdir "project/rcMath/debug"
          targetname "rcMath_debug"

      configuration "Release"
          defines { "NDEBUG" }
          flags { "Optimize" }
          targetdir "project/rcMath/release"
          targetname "rcMath"

   -- Project "rcBase"                      --
   -- ===================================== --
