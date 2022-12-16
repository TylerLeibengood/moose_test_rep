#include "moose_test_repApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
moose_test_repApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  return params;
}

moose_test_repApp::moose_test_repApp(InputParameters parameters) : MooseApp(parameters)
{
  moose_test_repApp::registerAll(_factory, _action_factory, _syntax);
}

moose_test_repApp::~moose_test_repApp() {}

void
moose_test_repApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"moose_test_repApp"});
  Registry::registerActionsTo(af, {"moose_test_repApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
moose_test_repApp::registerApps()
{
  registerApp(moose_test_repApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
moose_test_repApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  moose_test_repApp::registerAll(f, af, s);
}
extern "C" void
moose_test_repApp__registerApps()
{
  moose_test_repApp::registerApps();
}
