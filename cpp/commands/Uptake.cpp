// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Uptake.h"
#include "Constants.h"

using namespace IndexConstants;

Uptake::Uptake(IndexSubSystem* subsystem)
  :m_index{subsystem} {
    AddRequirements({subsystem});
  }

// Called when the command is initially scheduled.
void Uptake::Initialize() {
  m_index->Uptake();
}

void Uptake::End(bool interrupted) {
  m_index->Stoptake();
}

