// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/SpitOut.h"
#include "Constants.h"

using namespace IntakeConstants;

SpitOut::SpitOut(Intake* subsystem)
   : m_intake{subsystem} {
     AddRequirements({subsystem});
   }

// Called when the command is initially scheduled.
void SpitOut::Initialize() {
  m_intake->SpitOut();
}

void SpitOut::End(bool interrupted) {
  m_intake->StopIntake();
}

