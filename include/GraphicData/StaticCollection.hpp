#ifndef _STATIC_COLLECTION_HPP_
#define _STATIC_COLLECTION_HPP_

#include <cstdint>
#include "Macros/Macros.hpp"

namespace Eternal
{
	namespace Graphics
	{
		class Device;
	}

	namespace GraphicData
	{
		using namespace Eternal::Graphics;

		class StaticCollectionInitialization
		{
		public:
			virtual ~StaticCollectionInitialization() {}
			virtual void Initialize(_In_ Device& DeviceObj) = 0;
		};

		template<typename Key, class Value, uint32_t EntriesCount>
		class StaticCollection : public StaticCollectionInitialization
		{
		public:
			static StaticCollection* Get()
			{
				ETERNAL_ASSERT(_Instance);
				return _Instance;
			}
			
			StaticCollection()
			{
				ETERNAL_ASSERT(!_Instance);
				_Instance = this;

#ifdef ETERNAL_DEBUG
				Invalidate();
#endif
			}

			virtual ~StaticCollection()
			{
				Release();

				delete _Instance;
				_Instance = nullptr;
			}

			void Release()
			{
				for (uint32_t ObjectIndex = 0; ObjectIndex < EntriesCount; ++ObjectIndex)
				{
					delete _Objects[ObjectIndex];
					_Objects[ObjectIndex] = nullptr;
				}
			}

#ifdef ETERNAL_DEBUG
			void Invalidate()
			{
				for (uint32_t ObjectIndex = 0; ObjectIndex < EntriesCount; ++ObjectIndex)
				{
					_Objects[ObjectIndex] = nullptr;
				}
			}
#endif

			Value* Get(_In_ const Key& KeyObj)
			{
				ETERNAL_ASSERT(KeyObj < EntriesCount);
				return _Objects[KeyObj];
			}

		protected:
			Value** GetArray()
			{
				return _Objects;
			}

		private:
			static StaticCollection* _Instance;

			Value* _Objects[EntriesCount];
		};

		template<typename Key, class Value, uint32_t EntriesCount> StaticCollection<Key, Value, EntriesCount>* StaticCollection<Key, Value, EntriesCount>::_Instance = nullptr;
	}
}

#endif
