// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <wpi/numbers>

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or bool constants.  This should not be used for any other purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

namespace DriveConstants {
constexpr int kLeftMotor1Port = 0;
constexpr int kLeftMotor2Port = 1;
constexpr int kLeftMotor3Port = 2;
constexpr int kRightMotor1Port = 3;
constexpr int kRightMotor2Port = 4;
constexpr int kRightMotor3Port = 5;
constexpr int kEncoderCPR = 4096;
constexpr double kWheelDiameterInches = 6;
constexpr double kEncoderDistancePerPulse =
    // Assumes the encoders are directly mounted on the wheel shafts
    (kWheelDiameterInches * wpi::numbers::pi) /
    static_cast<double>(kEncoderCPR);
}  // namespace DriveConstants

namespace IntakeConstants {
constexpr int kIntakeMotorPort = 6;
constexpr double swallowSpeed = 0.6;
constexpr double SpitOutSpeed = 0.4;
}

namespace IndexConstants{
constexpr int kIndexMotorBottomPort = 7;
constexpr int kIndexMotorTopPort = 8;
constexpr int kpesensorPort = 0;
constexpr double uptakeSpeed = 0.4;
constexpr double downtakeSpeed = 0.4;
}

namespace FlywheelConstants{
constexpr int kFrontFlywheelPort = 9;
constexpr int kBackFlywheelPort = 10;
constexpr double HighFlywheelSpeed = 0.6;
constexpr double LowFlywheelSpeed = 0.6;
}

namespace ClimbConstants{
constexpr int kLeftArmMotorPort = 11;
constexpr int kRightArmMotorPort = 12;
constexpr int kLeftHookMotorPort = 13;
constexpr int kRightHookMotorPort = 14;
constexpr int HookSpeed = 0;
constexpr int ArmSpeed = 0;
}

namespace OIConstants {
constexpr int kDriverControllerPort = 0;
constexpr int aButton = 1; //z intake on
constexpr int bButton = 2;//x intake out
constexpr int xButton = 3;//c highshot
constexpr int yButton = 4;//v low shot
constexpr int LeftBumper = 5;//b index up
constexpr int RightBumper = 6;//n index down
constexpr int BackButton = 7;//m no command
constexpr int LeftTrigger = 2;//, arms up?
constexpr int RightTrigger = 3;//. arms down?
constexpr int RightXAxis = 4; //drive left right
constexpr int RightYAxis = 5; // no command
constexpr int RightJoystickButton = 10;//; no command
constexpr int LeftXAxis = 0; // no command
constexpr int LeftYAxis = 1; // drive forward back
constexpr int LeftJoystickButton = 9;//' hooks up
}  // namespace OIConstants
