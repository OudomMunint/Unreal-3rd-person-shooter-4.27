

using UnrealBuildTool;
using System.Collections.Generic;

public class DESN2600TestEditorTarget : TargetRules
{
	public DESN2600TestEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "DESN2600Test" } );
	}
}
