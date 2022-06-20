// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/HighShot.h"

using namespace FlywheelConstants;

HighShot::HighShot(ShooterSubSystem* subsystem)
  :m_shooter{subsystem} {
    AddRequirements({subsystem});
  }
// Called when the command is initially scheduled.
void HighShot::Initialize() {
  m_shooter->HighShot();
}

void HighShot::End(bool interrupted) {
  m_shooter->StopShot();
}
