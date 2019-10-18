#include "TestScene.h"

TestScene::TestScene()
{
	std::cout << "Made" << std::endl;

}

TestScene::~TestScene()
{


}

void TestScene::OnDisplay()
{
	std::cout << "Displaying Test" << std::endl;
}

void TestScene::OnUpdate()
{
	std::cout << "Updating Test" << std::endl;
}