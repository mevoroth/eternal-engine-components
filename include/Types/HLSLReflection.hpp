#pragma once

#include "Macros/Macros.hpp"
#include "Types/Types.hpp"

namespace Eternal
{
	namespace Types
	{
		struct Vector4;
		struct Vector3;
		struct Vector2;
		struct Matrix4x4;

		template<typename HLSLType, typename PaddingType, int Count>
		class HLSLArray
		{
			class HLSLArrayEntry
			{
			public:

				HLSLType& operator=(_In_ const HLSLType& InNewValue)
				{
					Value = InNewValue;
					return Value;
				}

			private:
				HLSLType Value;
				PaddingType _Pad;
			};
		public:

			HLSLArrayEntry& operator[](int Index)
			{
				ETERNAL_ASSERT(Index < Count);
				return Entries[Index];
			}

		private:
			HLSLArrayEntry Entries[Count];
		};
	}
}

using float4x4	= Eternal::Types::Matrix4x4;
using float4	= Eternal::Types::Vector4;
using float3	= Eternal::Types::Vector3;
using float2	= Eternal::Types::Vector2;
using uint4		= Eternal::Types::Uint4;
using uint		= unsigned int;

#define HLSL_BEGIN_STRUCT(StructName)			namespace Eternal { \
													namespace HLSL { \
														struct StructName {

#define HLSL_END_STRUCT(StructName)						}; \
													} \
												}

#define HLSL_ARRAY_VEC1(Type, VariableName, Count)	Eternal::Types::HLSLArray<Type, Eternal::Types::Vector3, Count> VariableName
#define HLSL_ARRAY_VEC2(Type, VariableName, Count)	Eternal::Types::HLSLArray<Type, Eternal::Types::Vector2, Count> VariableName
#define HLSL_ARRAY_VEC3(Type, VariableName, Count)	Eternal::Types::HLSLArray<Type, float, Count> VariableName
