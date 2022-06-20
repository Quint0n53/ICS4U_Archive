// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/HooksUp.h"

using namespace ClimbConstants;

HooksUp::HooksUp(ClimberSubSystem* subsystem)
  :m_climber{subsystem} {
    AddRequirements({subsystem});
  }

void HooksUp::Initialize() {
  m_climber->HooksUp();
}
void HooksUp::End(bool interrupted) {
  m_climber->StopHooks();
}
