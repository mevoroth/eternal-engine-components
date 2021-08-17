#pragma once

namespace Eternal
{
	namespace Types
	{
		struct Vector4;
		struct Vector3;
		struct Vector2;
		struct Matrix4x4;
	}
}

using float4x4	= Eternal::Types::Matrix4x4;
using float4	= Eternal::Types::Vector4;
using float3	= Eternal::Types::Vector3;
using float2	= Eternal::Types::Vector2;
using uint		= unsigned int;

#define HLSL_BEGIN_STRUCT(StructName)		namespace Eternal { \
												namespace HLSL { \
													struct StructName {

#define HLSL_END_STRUCT(StructName)					}; \
												} \
											}
