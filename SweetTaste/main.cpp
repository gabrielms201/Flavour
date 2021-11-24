#include <Flavour.h>
class Sandbox : public Flavour::Application
{
public:
	Sandbox() {}
	~Sandbox() {}
};

Flavour::Application* Flavour::CreateApplication()
{
	return new Sandbox;
}

