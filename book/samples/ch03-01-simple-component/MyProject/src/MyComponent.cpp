#include "MyComponent.hpp"
#include "MyLibrary.hpp"

namespace MyNamespace
{

MyComponent::MyComponent(IApplication& application, const String& name)
: ComponentBase(application, ::MyNamespace::MyLibrary::GetInstance(), name, ComponentCategory::Custom)
{
}

void MyComponent::Initialize()
{
    // subscribe events from the event system (Nm) here
}

void MyComponent::SubscribeServices()
{
	// subscribe the services used by this component here
}

void MyComponent::LoadSettings(const String& /*settingsPath*/)
{
	// load firmware settings here
}

void MyComponent::SetupSettings()
{
	// setup firmware settings here
}

void MyComponent::PublishServices()
{
	// publish the services of this component here
}

void MyComponent::LoadConfig()
{
    // load project config here
}

void MyComponent::SetupConfig()
{
    // setup project config here
}

void MyComponent::ResetConfig()
{
    // implement this inverse to SetupConfig() and LoadConfig()
}

void MyComponent::Dispose()
{
	// implement this inverse to SetupSettings(), LoadSettings() and Initialize()
}

void MyComponent::PowerDown()
{
	// implement this only if data must be retained even on power down event
}

} // end of namespace MyNamespace
