#ifndef _GRAPHIC_BUFFERS_HPP_
#define _GRAPHIC_BUFFERS_HPP_

#include "GraphicData/StaticCollection.hpp"

namespace Eternal
{
	namespace Graphics
	{
		class View;
		class Heap;
		class Resource;
		class DescriptorHeap;
	}

	namespace GraphicData
	{
		using namespace Eternal::Graphics;

		enum GraphicBufferKey
		{
			GRAPHIC_BUFFER_ALBEDO		= 0,
			GRAPHIC_BUFFER_SPECULAR		= 1,
			GRAPHIC_BUFFER_NORMAL		= 2,
			GRAPHIC_BUFFER_ROUGHNESS	= 3,
			GRAPHIC_BUFFER_DEPTH		= 4,
			GRAPHIC_BUFFER_COUNT,

			GRAPHIC_BUFFER_NO_DEPTH_COUNT = GRAPHIC_BUFFER_DEPTH
		};

		class GraphicBuffers : public StaticCollection<GraphicBufferKey, View, GRAPHIC_BUFFER_COUNT>
		{
		public:
			GraphicBuffers();

			virtual void Initialize(_In_ Device& DeviceObj) override;

		private:
			Heap*			_GraphicBuffersHeap[GRAPHIC_BUFFER_COUNT];
			Resource*		_GraphicBuffersResource[GRAPHIC_BUFFER_COUNT];
			DescriptorHeap*	_GraphicBuffersDescriptorHeap = nullptr;
		};
	}
}

#endif
