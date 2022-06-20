// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/ArmsDown.h"

using namespace ClimbConstants;

ArmsDown::ArmsDown(ClimberSubSystem* subsystem)
  :m_climber{subsystem} {
    AddRequirements({subsystem});
  }

void ArmsDown::Initialize() {
  m_climber->ArmsDown(ArmSpeed);
}

void ArmsDown::End(bool interrupted) {
  m_climber->StopArms();
}

