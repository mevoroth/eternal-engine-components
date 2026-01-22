using Sharpmake;

[module: Sharpmake.Include(@"..\eternal-engine\eternal-engine-project.sharpmake.cs")]

namespace EternalEngine
{
	public class EternalEngineComponentsProjectUtils
	{
		public static void ConfigureAll(Project.Configuration InConfiguration, ITarget InTarget, System.Type InTargetType)
		{
			// Include paths
			InConfiguration.IncludePaths.Add(new string[] {
				@"$(SolutionDir)eternal-engine-core\include",
				@"$(SolutionDir)eternal-engine-core\CorePrivate\include",
				@"$(SolutionDir)eternal-engine-graphics\include",
				@"$(SolutionDir)eternal-engine-graphics\GraphicsPrivate\include",
				@"$(SolutionDir)eternal-engine-extern\imgui",
				@"$(SolutionDir)eternal-engine-shaders",
				EternalEngineSettings.FBXSDKPath + @"\include",
			});

			if (InTargetType == typeof(Target))
			{
				InConfiguration.AddPublicDependency<EternalEngineGraphicsProject>(InTarget);
			}

			if (InTargetType == typeof(AndroidTarget))
			{
				InConfiguration.AddPublicDependency<EternalEngineGraphicsAndroidProject>(InTarget);
			}
		}
	}

	[Sharpmake.Generate]
	public class EternalEngineComponentsProject : EternalEngineBaseProject
	{
		public EternalEngineComponentsProject()
			: base(
				typeof(Target),
				"components",
				new EternalEngineProjectSettings(
					EternalEngineProjectSettingsFlags.EEPSF_IncludeSettingsHeader |
					EternalEngineProjectSettingsFlags.EEPSF_IncludeHLSLReflection
				)
			)
		{
		}

		public override void ConfigureAll(Configuration InConfiguration, ITarget InTarget)
		{
			base.ConfigureAll(InConfiguration, InTarget);
			EternalEngineComponentsProjectUtils.ConfigureAll(InConfiguration, InTarget, Targets.TargetType);
		}
	}

	[Sharpmake.Generate]
	public class EternalEngineComponentsAndroidProject : EternalEngineBaseAndroidProject
	{
		public EternalEngineComponentsAndroidProject()
			: base(
				typeof(AndroidTarget),
				"components",
				new EternalEngineProjectSettings(
					EternalEngineProjectSettingsFlags.EEPSF_IncludeSettingsHeader |
					EternalEngineProjectSettingsFlags.EEPSF_IncludeHLSLReflection
				)
			)
		{
		}

		public override void ConfigureAll(Configuration InConfiguration, ITarget InTarget)
		{
			base.ConfigureAll(InConfiguration, InTarget);
			EternalEngineComponentsProjectUtils.ConfigureAll(InConfiguration, InTarget, Targets.TargetType);
		}
	}
}
