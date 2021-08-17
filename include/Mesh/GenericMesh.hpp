#pragma once

#include "Mesh/Mesh.hpp"
#include "GraphicData/MeshVertexFormat.hpp"

namespace Eternal
{
	namespace Types
	{
		struct Matrix4x4;
	}

	namespace Components
	{
		using namespace std;
		using namespace Eternal::Types;
		using namespace Eternal::GraphicData;

		template<class VertexT, typename IndexT = uint16_t>
		class GenericMesh final : public Mesh
		{
		public:

			virtual uint32_t GetVerticesCount() const override final { return static_cast<uint32_t>(_Vertices.size()); }
			virtual uint32_t GetIndicesCount() const override final { return static_cast<uint32_t>(_Indices.size()); }
			virtual uint32_t GetConstantBufferCount() const override final { return static_cast<uint32_t>(_Transforms.size()); }
			virtual uint32_t GetVertexStride() const override final { return sizeof(VertexT); }
			virtual uint32_t GetIndexStride() const override final { return sizeof(IndexT); }
			virtual uint32_t GetConstantBufferStride() const override final { return sizeof(Matrix4x4); }
			virtual uint32_t GetIndicesMaxCount() const override final { return  1 << (GetIndexStride() * 8); }
			virtual const void* GetVerticesData() const override final { return reinterpret_cast<const void*>(_Vertices.data()); }
			virtual const void* GetIndicesData() const override final { return reinterpret_cast<const void*>(_Indices.data()); }
			virtual const void* GetConstantBufferData() const override final { return reinterpret_cast<const void*>(_Transforms.data()); }

			void AddMesh(_In_ const vector<IndexT>& InIndices, _In_ const vector<VertexT>& InVertices, _In_ const Matrix4x4& InModelMatrix, _In_ Material* InMaterial)
			{
				_GPUMesh.PerDrawInformations.push_back(GPUMesh::PerDrawInformation());
				GPUMesh::PerDrawInformation& PerDraw = _GPUMesh.PerDrawInformations.back();
				PerDraw.IndicesCount	= static_cast<uint32_t>(InIndices.size());
				PerDraw.IndicesOffset	= static_cast<uint32_t>(_Indices.size());
				PerDraw.VerticesOffset	= static_cast<uint32_t>(_Vertices.size());
				PerDraw.PerDrawMaterial	= InMaterial;
				_Vertices.insert(_Vertices.end(), InVertices.begin(), InVertices.end());
				_Indices.insert(_Indices.end(), InIndices.begin(), InIndices.end());
				_Transforms.push_back(InModelMatrix);
			}

			void AddMergeMesh(_In_ const vector<IndexT>& InIndices, _In_ const vector<VertexT>& InVertices, _In_ const Matrix4x4& InModelMatrix, _In_ Material* InMaterial)
			{
				IndexT TotalVertexCount = static_cast<IndexT>(_Vertices.size());
				uint32_t TotalIndexCount = static_cast<uint32_t>(_Indices.size());

				AddMesh(InIndices, InVertices, InModelMatrix, InMaterial);

				for (uint32_t Index = 0; Index < InIndices.size(); ++Index)
					_Indices[TotalIndexCount + Index] += TotalVertexCount;
			}

			const vector<IndexT>& GetIndices() const { return _Indices; }
			const vector<VertexT>& GetVertices() const { return _Vertices; }

		private:

			vector<Matrix4x4>	_Transforms;
			vector<IndexT>		_Indices;
			vector<VertexT>		_Vertices;
		};
	}
}
