

using UnrealBuildTool;
using System.Collections.Generic;

public class DESN2600TestTarget : TargetRules
{
	public DESN2600TestTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "DESN2600Test" } );
	}
}
