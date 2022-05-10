workspace "Phoenix"
    architecture "x64"
    startproject "Sandbox"

    configurations {"Debug","Release"}

    outputdir = "%{cfg.buildcfg}_%{cfg.system}-%{cfg.architecture}"

--Dependencies in assoc. table.
IncludeDir = {}
IncludeDir["GLFW"] = "Phoenix/vendor/glfw/include"



project "Phoenix"
    location "Phoenix"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" ..outputdir.. "/%{prj.name}")

    pchheader "PxPCH.h"
    pchsource "Phoenix/src/PxPCH.cpp"

    files{
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs{
        "Phoenix/src",
        "%{IncludeDir.GLFW}"
    }

    libdirs{
        "Phoenix/vendor/glfw/libs"
    }

    links{
        "glfw3.lib",
        "opengl32.lib",
        "user32.lib",
        "gdi32.lib",
        "shell32.lib"
    }

    filter "system:windows"
        cppdialect "C++14"
        staticruntime "On"
        systemversion "latest"
    
        defines{
            "PX_PLATFORM_WINDOWS",
            "PX_BUILD_DLL",
            "PX_ENABLE_ASSERTS",
            "PX_API",
            "_WINDLL"
        }

    postbuildcommands{
        ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox") 
    }

    filter "configurations:Debug"
        defines "PX_DEBUG"    
        symbols "On"
        buildoptions{
            "/MDd"
        }

    filter "configurations:Release"
        defines "PX_RELEASE"
        optimize "On"
        buildoptions{
            "/MD"
        }

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" ..outputdir.. "/%{prj.name}")

    files{
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    filter "system:windows"
        cppdialect "C++14"
        staticruntime "On"
        systemversion "latest"
    
        defines{
            "PX_PLATFORM_WINDOWS",
            "PX_BUILD_DLL",
            "PX_API",
            "_WINDLL"
        }

    includedirs{
        "Phoenix/src"
    }

    links{
        "Phoenix"
    }

    filter "configurations:Debug"
        defines "PX_DEBUG"    
        symbols "On"

    filter "configurations:Release"
        defines "PX_RELEASE"
        optimize "On"