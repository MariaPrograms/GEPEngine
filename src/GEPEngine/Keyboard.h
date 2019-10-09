#include <vector>

class Keyboard
{
public:
	Keyboard();
	~Keyboard();
	bool GetKeyDown(int _keyCode);
	bool GetKeyUp(int _keyCode);

private:
	std::vector<int> keyCodes;
};

