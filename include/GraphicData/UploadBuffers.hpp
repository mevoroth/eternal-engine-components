#ifndef _UPLOAD_BUFFERS_HPP_
#define _UPLOAD_BUFFERS_HPP_

#include "GraphicData/StaticCollection.hpp"
#include "Container/FreeList.hpp"

namespace Eternal
{
	namespace Graphics
	{
		class Heap;
		class Resource;
	}

	namespace GraphicData
	{
		using namespace std;
		using namespace Eternal::Graphics;
		using namespace Eternal::Container;

		enum UploadBufferKey
		{
			UPLOAD_BUFFER_BUFFER	= 0,
			UPLOAD_BUFFER_TEXTURE	= 1,
			UPLOAD_BUFFER_COUNT
		};

		class UploadBuffers : public StaticCollection<UploadBufferKey, FreeList<Resource*>, UPLOAD_BUFFER_COUNT>
		{
		public:
			static const uint32_t UPLOAD_BUFFER_PER_HEAP	= 16;

			UploadBuffers();
			virtual ~UploadBuffers();
			virtual void Initialize(_In_ Device& DeviceObj) override;

			//bool HasBuffers() const;
			//Resource* Pop();
			//void Push(_In_ Resource* ResourceObj);

		private:
			Heap*				_UploadHeaps[UPLOAD_BUFFER_COUNT];
			vector<Resource*>	_UploadBuffers;
		};
	}
}

#endif
