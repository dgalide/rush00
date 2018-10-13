#include "main.hpp"
#include "Info.hpp"
#include "OSModule.hpp"

int main(void)
{
	OSModule os;

	std::cout << os.getType() << std::endl;
	std::cout << os.getRelease() << std::endl;
	std::cout << os.getVersion() << std::endl;

	return 0;
}
