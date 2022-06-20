// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/ArmsUp.h"

using namespace ClimbConstants;


ArmsUp::ArmsUp(ClimberSubSystem* subsystem, double speed)
  :m_climber{subsystem} {
    AddRequirements({subsystem});
  }

void ArmsUp::Initialize() {
  m_climber->ArmsUp(ArmSpeed);
}

void ArmsUp::End(bool interrupted) {
  m_climber->StopArms();
}
