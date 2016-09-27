#ifndef _CONTEXT_COLLECTION_HPP_
#define _CONTEXT_COLLECTION_HPP_

namespace Eternal
{
	namespace Graphics
	{
		class Context;
		class Renderer;
	}

	namespace Parallel
	{
		class AtomicS32;
	}

	namespace GraphicData
	{
		using namespace Eternal::Graphics;
		using namespace Eternal::Parallel;

		class ContextCollection
		{
		public:
			ContextCollection(_In_ Renderer& RendererObj, _In_ int ContextCount);
			~ContextCollection();

			Context& Get();
			void Release(_In_ Context& ContextObj);

		private:
			Context** _Contexts;
			int _ContextCount = 0;
			AtomicS32** _ContextReservation = nullptr;
		};
	}
}

#endif
