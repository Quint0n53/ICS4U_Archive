// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/Joystick.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc2/command/Command.h>

#include "Constants.h"
#include "commands/ArmsDown.h"
#include "commands/ArmsUp.h"
#include "commands/DefaultDrive.h"
#include "commands/Downtake.h"
#include "commands/DriveDistance.h"
#include "commands/HalveDriveSpeed.h"
#include "commands/HighShot.h"
#include "commands/HooksUp.h"
#include "commands/LowShot.h"
#include "commands/SpitOut.h"
#include "commands/Swallow.h"
#include "commands/Uptake.h"
#include "subsystems/ClimberSubSystem.h"
#include "subsystems/DriveSubsystem.h"
#include "subsystems/IndexSubSystem.h"
#include "subsystems/IntakeSubsystem.h"
#include "subsystems/ShooterSubSystem.h"

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();

  frc2::Command* GetAutonomousCommand();

 private:
  // The robot's subsystems and commands are defined here...

  // The robot's subsystems
  ClimberSubSystem m_climber;
  DriveSubsystem m_drive;
  IndexSubSystem m_index;
  Intake m_intake;
  ShooterSubSystem m_shooter;

  // The chooser for the autonomous routines
  frc::SendableChooser<frc2::Command*> m_chooser;

  // The driver's controller
  frc::Joystick driver{OIConstants::kDriverControllerPort};

  void ConfigureButtonBindings();
};
