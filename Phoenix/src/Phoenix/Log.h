#pragma once

#include <memory>
#include "Core.h"
#include "easylogging++.h"
#include <stdlib.h>

namespace Phoenix {
	class PX_API Log
	{
	public:
		static void Init();
		static void ERROR(std::string msg);
	};
}

