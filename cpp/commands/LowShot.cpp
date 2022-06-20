// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/LowShot.h"

using namespace FlywheelConstants;

LowShot::LowShot(ShooterSubSystem* subsystem)
  :m_shooter{subsystem} {
    AddRequirements({subsystem});
  }
// Called when the command is initially scheduled.
void LowShot::Initialize() {
  m_shooter->LowShot();
}

void LowShot::End(bool interrupted) {
  m_shooter->StopShot();
}
