#ifndef _CAMERA_HPP_
#define _CAMERA_HPP_

#include "ComponentsSettings.hpp"
#include "Types/Types.hpp"

namespace Eternal
{
	namespace Components
	{
		using namespace Types;

		class Transform;

		class Camera
		{
		public:
			Camera(_In_ float Near, _In_ float Far);
			void GetViewMatrix(_Out_ Matrix4x4& ViewMatrix) const;
			void GetProjectionMatrix(_Out_ Matrix4x4& ProjectionMatrix) const;
			void GetViewProjectionMatrix(_Out_ Matrix4x4& ViewProjectionMatrix) const;
			void GetViewProjectionMatrixTransposed(_Out_ Matrix4x4& ViewProjectionMatrix) const;
			void GetViewProjectionMatrixInverse(_Out_ Matrix4x4& ViewProjectionInverse) const;
			void GetViewProjectionMatrixInverseTransposed(_Out_ Matrix4x4& ViewProjectionInverse) const;
			void SetNear(_In_ float Near);
			void SetFar(_In_ float Far);

			void SetForward(_In_ const Vector3& Forward);
			void SetPosition(_In_ const Vector3& Position);
			void SetUp(_In_ const Vector3& Up);

			const Vector3& GetPosition() const;
			const Vector3& GetForward() const;
			const Vector3& GetRight() const;
			const Vector3& GetUp() const;

			void UpdateView(const Transform& TransformObj);

		protected:
			virtual void _UpdateProjectionMatrix() = 0;
			void _UpdateViewMatrix(_In_ const Vector3& Position, _In_ const Vector3& Forward, _In_ const Vector3& Up);
			void _UpdateViewMatrix();

			Matrix4x4 _View = Matrix4x4::Identity;
			Matrix4x4 _Proj;

			Vector3 _Position = Vector3(0.f, 0.f, 0.f);
			Vector3 _Forward = Vector3(0.f, 0.f, 1.f);
			Vector3 _Up = Vector3(0.f, 1.f, 0.f);

			/**
			 * Cache Value
			 */
			Vector3 _Right = Vector3(1.f, 0.f, 0.f);

			float _Near = 0.f;
			float _Far = 0.f;
		};
	}
}

#endif
