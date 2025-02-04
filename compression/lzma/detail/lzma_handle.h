#pragma once
#include "lzma_alloc.h"

#ifdef _WIN32
#include "../../../extlibs/lzma/LzmaEnc.h"
#endif

#ifdef __linux__
#include "../../../extlibs/lzma/unix/LzmaEnc.h"
#endif

#ifdef __APPLE__
#include "../../../extlibs/lzma/unix/LzmaEnc.h"
#endif

namespace detail
{
	class lzma_handle
	{
	public:
		lzma_handle()
			: _handle(nullptr)
		{
			_handle = LzmaEnc_Create(&_alloc);
		}

		~lzma_handle()
		{
			if (_handle != nullptr)
			{
				LzmaEnc_Destroy(_handle, &_alloc, &_alloc);
			}
		}

		CLzmaEncHandle get_native_handle() const { return _handle; }

	private:
		CLzmaEncHandle  _handle;
		lzma_alloc      _alloc;
	};
}
