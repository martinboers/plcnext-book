#include "MyComponent.hpp"
#include "MyLibrary.hpp"
#include "Arp/System/Rsc/ServiceManager.hpp"

namespace MyNamespace
{
using Arp::System::Rsc::ServiceManager;

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
	this->deviceInfoServicePtr = ServiceManager::GetService<IDeviceInfoService>();
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
	
	RscVariant<512> serialNumber = this->deviceInfoServicePtr->GetItem("General.SerialNumber");
	if (serialNumber.GetType() == RscType::String)
	{
		this->log.Info("Serial number of this device: {0}%", serialNumber.GetChars());
	}
	else this->log.Info("Error reading device serial number");
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
