workspace "GameFramework"	-- �����������
	architecture "x64"		-- ��ϵ�ṹ
	startproject "Sandbox"	-- ��Sandbox��Ϊ������Ŀ

	configurations			-- ����
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"	-- ���Ŀ¼

--����Ŀ¼�б�
IncludeDir = {}
-- IncludeDir["glm"] = "Engine/vendor/glm"

project "Engine"		-- ��Ŀ
	location "Engine"	-- ���·��
	kind "StaticLib"	-- ��̬��
	language "C++"		-- ����
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")	-- Ŀ��Ŀ¼
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")	-- �м�Ŀ¼

	-- pchheader "exppch.h"	--Ԥ����ͷ�ļ�
	-- pchsource "Engine/src/exppch.cpp"

	files				--�ļ�
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

	includedirs			--���Ӱ���Ŀ¼
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		-- "%{IncludeDir.glm}"
	}

	filter "system:windows"	--windowsϵͳ
        systemversion "latest"	--sdk�汾

		defines			-- Ԥ����������
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