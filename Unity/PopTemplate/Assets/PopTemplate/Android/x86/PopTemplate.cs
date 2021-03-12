//#define POPTEMPLATE_AS_PACKAGE
using UnityEngine;
using System.Collections;					// required for Coroutines
using System.Runtime.InteropServices;		// required for DllImport
using System;								// requred for IntPtr
using System.Text;
using System.Collections.Generic;


/// <summary>
///	Low level interface
/// </summary>
public static class PopTemplate
{
#if UNITY_UWP
	private const string PluginName = "PopTemplate.Uwp";
#error building uwp
#elif UNITY_EDITOR_OSX || UNITY_STANDALONE_OSX
#if POPTEMPLATE_AS_PACKAGE
	private const string PluginFrameworkPath = "Packages/com.newchromantics.poptemplate/PopTemplate.xcframework/macos-x86_64/";
#else
	// universal xcframework
	//private const string PluginFrameworkPath = "Assets/PopTemplate/PopTemplate.xcframework/macos-x86_64/";
	private const string PluginFrameworkPath = "Assets/PopTemplate/";
#endif
	private const string PluginExecutable = "PopTemplate_Osx.framework/PopTemplate_Osx";
	//private const string PluginExecutable = "PopH264_Osx.framework/Versions/A/PopH264_Osx";
	private const string PluginName = PluginFrameworkPath+PluginExecutable;
#elif UNITY_IPHONE
	private const string PluginName = "__Internal";
#else
	private const string PluginName = "PopTemplate";
#endif
	[DllImport(PluginName, CallingConvention = CallingConvention.Cdecl)]
	private static extern int	PopTemplate_GetVersion();
}

