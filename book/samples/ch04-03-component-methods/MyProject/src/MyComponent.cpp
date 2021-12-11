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
	log.Info("MyComponent::Initialize");
    // subscribe events from the event system (Nm) here
}

void MyComponent::SubscribeServices()
{
	log.Info("MyComponent::SubscribeServices");;
	// subscribe the services used by this component here
}

void MyComponent::LoadSettings(const String& settingsPath)
{
	log.Info("MyComponent::LoadSettings - settings path = '{0}'", settingsPath);
	// load firmware settings here
}

void MyComponent::SetupSettings()
{
	log.Info("MyComponent::SetupSettings");
	// setup firmware settings here
}

void MyComponent::PublishServices()
{
	log.Info("MyComponent::PublishServices");
	// publish the services of this component here
}

void MyComponent::LoadConfig()
{
	log.Info("MyComponent::LoadConfig");
    // load project config here
}

void MyComponent::SetupConfig()
{
	log.Info("MyComponent::SetupConfig");
    // setup project config here
}

void MyComponent::ResetConfig()
{
	log.Info("MyComponent::ResetConfig");
    // implement this inverse to SetupConfig() and LoadConfig()
}

void MyComponent::Dispose()
{
	log.Info("MyComponent::Dispose");
	// implement this inverse to SetupSettings(), LoadSettings() and Initialize()
}

void MyComponent::PowerDown()
{
	log.Info("MyComponent::PowerDown");
	// implement this only if data must be retained even on power down event
}

} // end of namespace MyNamespace
