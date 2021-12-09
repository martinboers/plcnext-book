#include "MyLibrary.hpp"
#include "Arp/System/Core/CommonTypeName.hxx"
#include "MyComponent.hpp"
#include "MyOtherComponent.hpp"

namespace MyNamespace
{

MyLibrary::MyLibrary(AppDomain& appDomain)
    : LibraryBase(appDomain, ARP_VERSION_CURRENT)
{
    this->componentFactory.AddFactoryMethod(TypeName<::MyNamespace::MyComponent>(), &::MyNamespace::MyComponent::Create);
    this->componentFactory.AddFactoryMethod(TypeName<::MyNamespace::MyOtherComponent>(), &::MyNamespace::MyOtherComponent::Create);
}

void MyLibrary::Main(AppDomain& appDomain)
{
    SingletonBase::CreateInstance(appDomain);
}

extern "C" ARP_CXX_SYMBOL_EXPORT ILibrary& ArpDynamicLibraryMain(AppDomain& appDomain)
{
    MyLibrary::Main(appDomain);
    return  MyLibrary::GetInstance();
}

} // end of namespace MyNamespace
