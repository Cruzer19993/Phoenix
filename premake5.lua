workspace "Phoenix"
    architecture "x64"
    startproject "Sandbox"

    configurations {"Debug","Release"}

    outputdir = "%{cfg.buildcfg}_%{cfg.system}-%{cfg.architecture}"

project "Phoenix"
    location "Phoenix"
    kind "SharedLib"
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
            "_WINDLL"
        }

    postbuildcommands{
        ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox") 
    }

    filter "configurations:Debug"
        defines "PX_DEBUG"    
        symbols "On"

    filter "configurations:Release"
        defines "PX_RELEASE"
        optimize "On"

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