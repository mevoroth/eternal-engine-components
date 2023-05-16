#pragma once

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
			void GetWorldToView(_Out_ Matrix4x4& OutWorldToView);
			void GetViewToWorld(_Out_ Matrix4x4& OutViewToWorld);
			void GetViewToClip(_Out_ Matrix4x4& OutViewToClip);
			void GetClipToView(_Out_ Matrix4x4& OutClipToView);
			void GetWorldToClip(_Out_ Matrix4x4& OutWorldToClip);
			void GetClipToWorld(_Out_ Matrix4x4& OutClipToWorld);
			void SetNear(_In_ float InNear);
			void SetFar(_In_ float InFar);

			void SetForward(_In_ const Vector3& InForward);
			void SetPosition(_In_ const Vector3& InPosition);
			void SetUp(_In_ const Vector3& InUp);

			const Vector3& GetPosition() const;
			const Vector3& GetForward() const;
			const Vector3& GetRight() const;
			const Vector3& GetUp() const;
			float GetRenderNear() const;
			float GetRenderFar() const;

			void UpdateWorldToView(_In_ const Transform& InTransform);

			void ComputeFrustum(_Out_ Frustum& OutFrustum);

		protected:
			virtual void _UpdateViewToClip() = 0;
			void _UpdateCache();
			void _UpdateWorldToView(_In_ const Vector3& Position, _In_ const Vector3& Forward, _In_ const Vector3& Up);
			void _UpdateWorldToView();

			Matrix4x4 _WorldToView	= Matrix4x4::Identity;
			Matrix4x4 _ViewToWorld	= Matrix4x4::Identity;
			Matrix4x4 _ViewToClip	= Matrix4x4::Identity;
			Matrix4x4 _ClipToView	= Matrix4x4::Identity;

			Vector3 _Position		= Vector3::Zero;
			Vector3 _Forward		= Vector3::Forward;
			Vector3 _Up				= Vector3::Up;

			/**
			 * Cache Value
			 */
			Vector3 _Right			= Vector3::Right;

			bool _Dirty				= true;
			float _Near				= 0.f;
			float _Far				= 0.f;
		};
	}
}
