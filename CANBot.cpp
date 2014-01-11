#include "WPILib.h"
#include "CANJaguar.h"

//MOTOR CAN IDs
const int FRONT_LEFT_MOTOR_ID = 2;
const int BACK_LEFT_MOTOR_ID = 3;
const int FRONT_RIGHT_MOTOR_ID = 4;
const int BACK_RIGHT_MOTOR_ID = 5;

class CANBot : public IterativeRobot
{
	//Joysticks (only 2 of them)
	Joystick *leftStick, *rightStick;
	//Jaguars
	CANJaguar *frontLeftMotor;
	CANJaguar *backLeftMotor;
	CANJaguar *frontRightMotor;
	CANJaguar *backRightMotor;

public:
	CANBot()
	{
		//Initialize the joysticks.
		leftStick = new Joystick(1);
		rightStick = new Joystick(2);
		//Initialize the motors
		frontLeftMotor = new CANJaguar(FRONT_LEFT_MOTOR_ID);
		backLeftMotor = new CANJaguar(BACK_LEFT_MOTOR_ID);
		frontRightMotor = new CANJaguar(FRONT_RIGHT_MOTOR_ID);
		backRightMotor = new CANJaguar(BACK_RIGHT_MOTOR_ID);
	}
	
	void TeleopPeriodic()
	{
		//declare some holder variables
		float leftSpeed, rightSpeed;
		//get the speeds from the joystics
		leftSpeed = leftStick->GetY();
		rightSpeed = rightStick->GetY();
		//set the motor speeds.
		setLeft(leftSpeed);
		setRight(rightSpeed);
	}

	void setLeft(float speed)
	{
		frontLeftMotor -> Set(speed);
		backLeftMotor -> Set(speed);
	}
	
	void setRight(float speed)
	{
		frontRightMotor -> Set(speed);
		backRightMotor -> Set(speed);
	}
	
};

START_ROBOT_CLASS(CANBot);

