// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc/shuffleboard/Shuffleboard.h>
#include <frc2/command/button/JoystickButton.h>
#include <frc/Joystick.h>

#include "commands/DefaultDrive.h"
#include "commands/ArmsUp.h"
#include "commands/HalveDriveSpeed.h"

RobotContainer::RobotContainer() {
  // Initialize all of your commands and subsystems here

  // Put the chooser on the dashboard
  frc::Shuffleboard::GetTab("Autonomous").Add(m_chooser);

  // Configure the button bindings
  ConfigureButtonBindings();

  // Set up default drive command
  m_drive.SetDefaultCommand(DefaultDrive(
      &m_drive, [this] { return -driver.GetRawAxis(OIConstants::LeftYAxis); },
      [this] { return driver.GetRawAxis(OIConstants::RightXAxis); }));
}

void RobotContainer::ConfigureButtonBindings() {

  //Turn intake on/off by pressing A
  frc2::JoystickButton(&driver, OIConstants::aButton)
      .ToggleWhenPressed(new Swallow(&m_intake));
  //Turn intake on/off by pressing B but this goes out
  frc2::JoystickButton(&driver, OIConstants::bButton)
      .ToggleWhenPressed(new SpitOut(&m_intake));
  //turn flywheels on/off with X for high shot
  frc2::JoystickButton(&driver,OIConstants::xButton)
      .ToggleWhenPressed(new HighShot(&m_shooter));
  //turn flywheels on/off with Y for low shot
  frc2::JoystickButton(&driver,OIConstants::yButton)
      .ToggleWhenPressed(new LowShot(&m_shooter));
  //index up on left bumper
  frc2::JoystickButton(&driver,OIConstants::LeftBumper)
      .WhenHeld(new Uptake(&m_index));
  //index down on right bumper
  frc2::JoystickButton(&driver,OIConstants::RightBumper)
      .WhenHeld(new Downtake(&m_index));
  //bring climbing hooks up to center
  frc2::JoystickButton(&driver,OIConstants::LeftJoystickButton)
      .WhenHeld(new HooksUp(&m_climber));
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // Runs the chosen command in autonomous
  return m_chooser.GetSelected();
}
