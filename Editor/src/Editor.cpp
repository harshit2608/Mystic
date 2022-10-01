#include <Mystic.h>
#include <Mystic/Core/EntryPoint.h>

namespace Mystic
{
	class Editor : public Application
	{
	public:
		Editor() = default;
	};

	Application *CreateApplication()
	{
		return new Editor;
	}
} // namespace Mystic
