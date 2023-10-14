workspace "GameFramework"	-- 解决方案名称
	architecture "x64"		-- 体系结构
	startproject "Sandbox"	-- 将Sandbox设为启动项目

	configurations			-- 配置
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"	-- 输出目录

--包含目录列表
IncludeDir = {}
-- IncludeDir["glm"] = "Engine/vendor/glm"

project "Engine"		-- 项目
	location "Engine"	-- 相对路径
	kind "StaticLib"	-- 静态库
	language "C++"		-- 语言
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")	-- 目标目录
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")	-- 中间目录

	-- pchheader "exppch.h"	--预编译头文件
	-- pchsource "Engine/src/exppch.cpp"

	files				--文件
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		-- "%{prj.name}/vendor/glm/glm/**.hpp",
		-- "%{prj.name}/vendor/glm/glm/**.inl"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs			--附加包含目录
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		-- "%{IncludeDir.glm}"
	}

	filter "system:windows"	--windows系统
        systemversion "latest"	--sdk版本

		defines			-- 预处理器定义
		{
			"EG_PLATFORM_WINDOWS",
			"EG_BUILD_DLL",
		}

	filter "configurations:Debug"	-- Debug
        defines "EG_DEBUG"
		runtime "Debug"
        symbols "on"

    filter "configurations:Release"	-- Release
        defines "EG_RELEASE"
		runtime "Release"
        optimize "on"

    filter "configurations:Dist"	-- Dist
        defines "EG_DIST"
		runtime "Release"
        optimize "on"

project "Sandbox"		
	location "Sandbox"	
	kind "ConsoleApp"	
	language "C++"		
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files				
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs			
	{
		"Engine/vendor/spdlog/include",
		"Engine/src",
		"Engine/vendor",
		-- "%{IncludeDir.glm}"
	}

	links
	{
		"Engine"			
	}

	filter "system:windows"
        systemversion "latest"	

		defines			
		{
			"EG_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"	
        defines "EG_DEBUG"
		runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "EG_RELEASE"
		runtime "Release"
        optimize "on"

    filter "configurations:Dist"
        defines "EG_DIST"
		runtime "Release"
        optimize "on"