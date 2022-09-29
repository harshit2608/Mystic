#include <Mystic.h>
#include <Mystic/Core/EntryPoint.h>

namespace Mystic
{
	class Editor : public Application
	{
	};

	Application *CreateApplication()
	{
		return new Editor;
	}
} // namespace Mystic
