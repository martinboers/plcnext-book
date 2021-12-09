#include "MyOtherComponent.hpp"
#include "MyLibrary.hpp"

namespace MyNamespace
{

MyOtherComponent::MyOtherComponent(IApplication& application, const String& name)
: ComponentBase(application, ::MyNamespace::MyLibrary::GetInstance(), name, ComponentCategory::Custom)
{
}

void MyOtherComponent::Initialize()
{
	log.Info("MyOtherComponent::Initialize");
    // subscribe events from the event system (Nm) here
}

void MyOtherComponent::SubscribeServices()
{
	log.Info("MyOtherComponent::SubscribeServices");;
	// subscribe the services used by this component here
}

void MyOtherComponent::LoadSettings(const String& settingsPath)
{
	log.Info("MyOtherComponent::LoadSettings - settings path = '{0}'", settingsPath);
	// load firmware settings here
}

void MyOtherComponent::SetupSettings()
{
	log.Info("MyOtherComponent::SetupSettings");
	// setup firmware settings here
}

void MyOtherComponent::PublishServices()
{
	log.Info("MyOtherComponent::PublishServices");
	// publish the services of this component here
}

void MyOtherComponent::LoadConfig()
{
	log.Info("MyOtherComponent::LoadConfig");
    // load project config here
}

void MyOtherComponent::SetupConfig()
{
	log.Info("MyOtherComponent::SetupConfig");
    // setup project config here
}

void MyOtherComponent::ResetConfig()
{
	log.Info("MyOtherComponent::ResetConfig");
    // implement this inverse to SetupConfig() and LoadConfig()
}

void MyOtherComponent::Dispose()
{
	log.Info("MyOtherComponent::Dispose");
	// implement this inverse to SetupSettings(), LoadSettings() and Initialize()
}

void MyOtherComponent::PowerDown()
{
	log.Info("MyOtherComponent::PowerDown");
	// implement this only if data must be retained even on power down event
}

} // end of namespace MyNamespace
