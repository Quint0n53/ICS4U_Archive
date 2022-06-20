// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Swallow.h"
#include "Constants.h"

using namespace IntakeConstants;

Swallow::Swallow(Intake* subsystem)
   : m_intake{subsystem} {
     AddRequirements({subsystem});
   }

// Called when the command is initially scheduled.
void Swallow::Initialize() {
  m_intake->Swallow();
}
void Swallow::End(bool interrupted) {
  m_intake->StopIntake();
}
