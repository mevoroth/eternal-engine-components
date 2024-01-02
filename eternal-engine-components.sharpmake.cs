using Sharpmake;

[module: Sharpmake.Include(@"..\eternal-engine\eternal-engine-project.sharpmake.cs")]

namespace EternalEngine
{
	[Sharpmake.Generate]
	public class EternalEngineComponentsProject : EternalEngineBaseProject
	{
		public EternalEngineComponentsProject()
			: base(
				"components",
				new EternalEngineProjectSettings(
					EternalEngineProjectSettingsFlags.EEPSF_IncludeSettingsHeader |
					EternalEngineProjectSettingsFlags.EEPSF_IncludeHLSLReflection
				)
			)
		{
		}

		public override void ConfigureAll(Configuration InConfiguration, Target InTarget)
		{
			base.ConfigureAll(InConfiguration, InTarget);

			// Include paths
			InConfiguration.IncludePaths.Add(new string[] {
				@"$(SolutionDir)eternal-engine-core\include",
				@"$(SolutionDir)eternal-engine-graphics\include",
				@"$(SolutionDir)eternal-engine-extern\imgui",
				@"$(SolutionDir)eternal-engine-shaders",
				EternalEngineSettings.VulkanPath + @"\Include",
				EternalEngineSettings.FBXSDKPath + @"\include",
			});

			if (InConfiguration.Platform != Platform.win64 && InConfiguration.Platform != Platform.win32)
			{
				InConfiguration.IncludePaths.AddRange(new string[] {
					@"$(SolutionDir)eternal-engine-core\CorePrivate\include",
					@"$(SolutionDir)eternal-engine-graphics\GraphicsPrivate\include",
				});
			}

			InConfiguration.AddPublicDependency<EternalEngineGraphicsProject>(InTarget);
		}
	}
}
