#include "Camera/Camera.hpp"

#include "Transform/Transform.hpp"

namespace Eternal
{
	namespace Components
	{
		Camera::Camera(_In_ float Near, _In_ float Far)
			: _Near(Near)
			, _Far(Far)
		{
			_Dirty = true;
		}

		void Camera::GetWorldToView(_Out_ Matrix4x4& OutWorldToView)
		{
			_UpdateCache();
			OutWorldToView = _WorldToView;
		}

		void Camera::GetViewToWorld(_Out_ Matrix4x4& OutViewToWorld)
		{
			_UpdateCache();
			OutViewToWorld = _ViewToWorld;
		}

		void Camera::GetViewToClip(_Out_ Matrix4x4& OutViewToClip)
		{
			_UpdateCache();
			OutViewToClip = _ViewToClip;
		}
		
		void Camera::GetClipToView(_Out_ Matrix4x4& OutClipToView)
		{
			_UpdateCache();
			OutClipToView = _ClipToView;
		}

		void Camera::GetWorldToClip(_Out_ Matrix4x4& OutWorldToClip)
		{
			_UpdateCache();
			OutWorldToClip = _WorldToView * _ViewToClip;
		}

		void Camera::GetClipToWorld(_Out_ Matrix4x4& OutClipToWorld)
		{
			_UpdateCache();
			OutClipToWorld = _ClipToView * _ViewToWorld;
		}

		void Camera::SetNear(_In_ float Near)
		{
			_Near = Near;
			_Dirty = true;
		}

		void Camera::SetFar(_In_ float Far)
		{
			_Far = Far;
			_Dirty = true;
		}

		const Vector3& Camera::GetPosition() const
		{
			return _Position;
		}

		const Vector3& Camera::GetForward() const
		{
			return _Forward;
		}

		const Vector3& Camera::GetRight() const
		{
			return _Right;
		}

		const Vector3& Camera::GetUp() const
		{
			return _Up;
		}

		float Camera::GetRenderNear() const
		{
			return ETERNAL_USE_REVERSED_Z ? _Far : _Near;
		}

		float Camera::GetRenderFar() const
		{
			return ETERNAL_USE_REVERSED_Z ? _Near : _Far;
		}

		void Camera::SetPosition(_In_ const Vector3& Position)
		{
			_Position = Position;
			_Dirty = true;
		}

		void Camera::SetForward(_In_ const Vector3& Forward)
		{
			_Forward = Forward;
			_Dirty = true;
		}

		void Camera::SetUp(_In_ const Vector3& Up)
		{
			_Up = Up;
			_Dirty = true;
		}

		void Camera::_UpdateCache()
		{
			if (_Dirty)
			{
				_UpdateViewToClip();
				_UpdateWorldToView();
				_Dirty = false;
			}
		}

		void Camera::_UpdateWorldToView(_In_ const Vector3& Position, _In_ const Vector3& Forward, _In_ const Vector3& Up)
		{
			_Position	= Position;
			_Forward	= Normalize(Forward);
			_Up			= Normalize(Up);
			_Dirty		= true;
		}

		void Camera::_UpdateWorldToView()
		{
			_Right			= Normalize(Cross(_Up, _Forward));
			_WorldToView	= LookToLHMatrix(_Position, _Forward, _Up);
		}

		void Camera::UpdateWorldToView(_In_ const Transform& InTransform)
		{
			const Vector3& Position = InTransform.GetTranslation();

			Transform TransformNoTranslation = InTransform;
			TransformNoTranslation.SetTranslation(Vector3::Zero);
			Vector3 TempForward3	= Vector3::Forward;
			Vector3 TempUp3			= Vector3::Up;

			// Compute rotation
			Vector4 Forward			= TransformNoTranslation.GetViewToWorld() * Vector4::ForwardPosition;
			Vector4 Up				= TransformNoTranslation.GetViewToWorld() * Vector4::UpPosition;

			TempForward3.x = Forward.x;
			TempForward3.y = Forward.y;
			TempForward3.z = Forward.z;

			TempUp3.x = Up.x;
			TempUp3.y = Up.y;
			TempUp3.z = Up.z;
			
			_ViewToWorld = InTransform.GetViewToWorld();
			_UpdateWorldToView(Position, TempForward3, TempUp3);
		}
	}
}
