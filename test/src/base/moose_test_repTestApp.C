//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "moose_test_repTestApp.h"
#include "moose_test_repApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
moose_test_repTestApp::validParams()
{
  InputParameters params = moose_test_repApp::validParams();
  return params;
}

moose_test_repTestApp::moose_test_repTestApp(InputParameters parameters) : MooseApp(parameters)
{
  moose_test_repTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

moose_test_repTestApp::~moose_test_repTestApp() {}

void
moose_test_repTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  moose_test_repApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"moose_test_repTestApp"});
    Registry::registerActionsTo(af, {"moose_test_repTestApp"});
  }
}

void
moose_test_repTestApp::registerApps()
{
  registerApp(moose_test_repApp);
  registerApp(moose_test_repTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
moose_test_repTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  moose_test_repTestApp::registerAll(f, af, s);
}
extern "C" void
moose_test_repTestApp__registerApps()
{
  moose_test_repTestApp::registerApps();
}
