// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>
#include <frc/AnalogInput.h>

#include "Constants.h"

class IndexSubSystem : public frc2::SubsystemBase {
 public:
  IndexSubSystem();

  void Periodic() override;

  void Uptake();

  void Downtake();

  void Stoptake();

 private:
  WPI_VictorSPX indexTop;
  WPI_VictorSPX indexBottom;
  frc::AnalogInput pesensor;
};
