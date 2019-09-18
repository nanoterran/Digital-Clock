#include "ClockController.h"

ClockController::ClockController(ClockModel *model, I_View *view)
{
	this->model = model;
	this->view = view;

	// model->SetClockState(ClockSM_Init);
}

ClockController::~ClockController()
{
	model->~ClockModel();
	view->~I_View();
}

// void ClockController::Run()
// {
// 	Clock_State state = model->GetClockState();
	
// 	/////////////////////
// 	//STATE TRANSITIONS//
// 	/////////////////////
// 	switch (state) {   //states transitions
// 		case ClockSM_Init:

// 			//Update the view.
// 			view->ClearView();

// 			//Intitial transition when system starts
// 			state = ClockSM_FaceOne;

// 		//   //Initial system setup
// 		//   clearScreen();                      //clears the matrix.
// 		//   drawFaceOne(t.hour, t.min, t.sec);  //draws the clock face.
// 		//   previousHour = t.hour;              //sets the value of previous hour

// 		//   //Initiazes the counter to zero
// 		//   hourCounter = 0;
// 		//   minuteCounter = 0;
// 		  break;

// 		// case ClockSM_FaceOne:
// 		//   //transition to SetHour state
// 		//   if (setupButton.getState() == 1 && nextButton.getState() == 0
// 		//                                   && prevButton.getState() == 0) {
// 		//     Clock_State = ClockSM_SetHour;
// 		//     clearScreen();      //clears the screen

// 		//     //reset the state of the buttons
// 		//     setupButton.reset();    //resets setup button state
// 		//     nextButton.reset();     //resets next button state
// 		//     prevButton.reset();    //resets enter button state

// 		//     faceOneFlag = 1;  //set the face one flag

// 		//     //sets the hour counter to the current hour
// 		//     hourCounter = t.hour;

// 		//     //prints the hour screen
// 		//     printSetHour(hourCounter);
// 		//   }
// 		//   //transition to FaceTwo 
// 		//   else if (setupButton.getState() == 0 && nextButton.getState() == 1
// 		//                                        && prevButton.getState() == 0) {
																						
// 		//     Clock_State = ClockSM_FaceTwo;
// 		//     clearScreen();      //clears the screen

// 		//     //reset the state of the buttons
// 		//     setupButton.reset();    //resets setup button state
// 		//     nextButton.reset();     //resets next button state
// 		//     prevButton.reset();    //resets enter button state

// 		//     //sets the hour counter to the current hour
// 		//     hourCounter = t.hour;

// 		//     drawFaceTwo(t.hour, t.min);
// 		//   }
// 		//   break;

// 		// case ClockSM_FaceTwo:
// 		//   //transition to FaceOne
// 		//   if (setupButton.getState() == 0 && nextButton.getState() == 1
// 		//                                   && prevButton.getState() == 0) {
																				
// 		//     Clock_State = ClockSM_FaceOne;

// 		//     clearScreen();                      //clears the matrix.
// 		//     drawFaceOne(t.hour, t.min, t.sec);  //draws the clock face.

// 		//     //reset the state of the buttons
// 		//     setupButton.reset();    //resets setup button state
// 		//     nextButton.reset();     //resets next button state
// 		//     prevButton.reset();    //resets enter button state
				
// 		//   }
// 		//   //transition to SetHour from FaceTwo
// 		//   else if (setupButton.getState() == 1 && nextButton.getState() == 0
// 		//                                        && prevButton.getState() == 0) {
																						
// 		//     Clock_State = ClockSM_SetHour;
// 		//     clearScreen();      //clears the screen

// 		//     //reset the state of the buttons
// 		//     setupButton.reset();    //resets setup button state
// 		//     nextButton.reset();     //resets next button state
// 		//     prevButton.reset();    //resets enter button state

// 		//     faceOneFlag = 0;
				
// 		//     //sets the hour counter to the current hour
// 		//     hourCounter = t.hour;

// 		//     //prints the hour screen
// 		//     printSetHour(hourCounter);
// 		//   }
// 		//   break;

// 		// case ClockSM_SetHour:
// 		//   //transition to SetMinutes state
// 		//   if (setupButton.getState() == 1 && nextButton.getState() == 0
// 		//                                   && prevButton.getState() == 0) {
// 		//     Clock_State = ClockSM_SetMinutes;

// 		//     clearScreen();    //clears the screen

// 		//     rtc.setTime(hourCounter, t.min, t.sec);
				
// 		//     //sets the minute counter to current minutes
// 		//     minuteCounter = t.min;

// 		//     //reset the state of the buttons
// 		//     setupButton.reset();    //resets setup button state
// 		//     nextButton.reset();     //resets next button state
// 		//     prevButton.reset();    //resets enter button state

// 		//     //prints the setup screen
// 		//     printSetMinutes(minuteCounter);
// 		//   }
// 		//   break;

// 		// case ClockSM_SetMinutes:
// 		//   //transition to FaceOne state
// 		//   if (setupButton.getState() == 1 && faceOneFlag == 1
// 		//                                   && nextButton.getState() == 0
// 		//                                   && prevButton.getState() == 0) {
																				
// 		//     Clock_State = ClockSM_FaceOne;  //set the state machine state

// 		//     //Set the time to new minute, same hour and seconds
// 		//     rtc.setTime(t.hour, minuteCounter, t.sec);

// 		//     clearScreen();            //clears the screen.

// 		//     //draws the clock face with the new hour.
// 		//     drawFaceOne(t.hour, t.min, t.sec);
				
// 		//     previousHour = t.hour;    //sets the value of previous hour

// 		//     //reset the state of the buttons
// 		//     setupButton.reset();    //resets setup button state
// 		//     nextButton.reset();     //resets next button state
// 		//     prevButton.reset();    //resets enter button state

// 		//     //reset all counters
// 		//     hourCounter = 0;          //resets the hour counter
// 		//     minuteCounter = 0;        //resetst the minute counter
// 		//   }
// 		//   //transition to FaceTwo state
// 		//   else if (setupButton.getState() == 1 && faceOneFlag == 0
// 		//                                        && nextButton.getState() == 0
// 		//                                        && prevButton.getState() == 0) {

// 		//     Clock_State = ClockSM_FaceTwo;  //set the state machine clock state

// 		//     //sets the new time.
// 		//     rtc.setTime(hourCounter, minuteCounter, t.sec);

// 		//     previousHour = t.hour;    //sets the value of previous hour

// 		//     clearScreen();

// 		//     drawFaceTwo(t.hour, t.min);
				
// 		//     //reset the state of the buttons
// 		//     setupButton.reset();    //resets setup button state
// 		//     nextButton.reset();     //resets next button state
// 		//     prevButton.reset();    //resets enter button state

// 		//     //reset all counters
// 		//     hourCounter = 0;          //resets the hour counter
// 		//     minuteCounter = 0;        //resetst the minute counter

// 		//   }
// 		//   break;

// 		default:
// 			state = ClockSM_Init;
// 			break;
// 	}
// 	//end of transitions

// 	///////////////////////
// 	// STATE ACTIONS
// 	//////////////////////
// 	switch (state) {  //states actions

// 		case ClockSM_FaceOne:
// 		case ClockSM_FaceTwo:
// 			view->UpdateView();
// 		break;
// 		// case ClockSM_FaceOne:
// 		//   //refeshes the clock every minute.
// 		//   if ((unsigned long)(millis() - previousMillis) > ONE_SECOND) {
// 		//     refreshClock();   //refreshes the clock face

// 		//     if (previousHour != t.hour) { //the hour changed
// 		//       drawTheHour(t.hour);   //draws the next hour
// 		//       previousHour = t.hour;
// 		//     }
// 		//     drawMinuteHandle(t.min);  //draws the minute handle
// 		//     drawSecondHandle(t.sec);  //draws the second handle

// 		//     previousMillis = millis();
// 		//   }
// 			// break;

// 		// case ClockSM_FaceTwo:
// 		//   //refeshes the clock every minute.
// 		//   if ((unsigned long)(millis() - previousMillis) > ONE_SECOND) {
// 		//     refreshClock();   //refreshes the clock face

// 		//     if (previousHour != t.hour) { //the hour changed
// 		//       printHour(t.hour);   //draws the next hour
// 		//       previousHour = t.hour;
// 		//     }
				
// 		//     printMinute(t.min);  //draws the minute handle

// 		//     previousMillis = millis();
// 		//   }
// 		//   else {
// 		//     //do-nothing
// 		//   }
// 		//   break;

// 		// case ClockSM_SetHour:
// 		//   //checks whether next button is pressed
// 		//   if (setupButton.getState() == 0 && nextButton.getState() == 1 
// 		//                                   && prevButton.getState() == 0) {
// 		//     hourCounter++;   //increse the hour counter
				
// 		//     //checks for the boundaries of the hours, else set it to zero.
// 		//     if ((hourCounter < 0) || (hourCounter > 23)) {
// 		//       hourCounter = 0;
// 		//     }
				
// 		//     //refresh the screen
// 		//     matrix.fillRect(0, 14, 31, 31, matrix.Color333(0, 0, 0));

// 		//     //prints the hour screen
// 		//     printSetHour(hourCounter);
// 		//   }
// 		//   //checks whether the previous button is pressed
// 		//   else if (setupButton.getState() == 0 && nextButton.getState() == 0 
// 		//                                        && prevButton.getState() == 1) {
// 		//     hourCounter--;   //decrements the hour counter
				
// 		//     //checks for the boundaries of the hours, else set it to zero.
// 		//     if (hourCounter < 0 || hourCounter > 23) {
// 		//       hourCounter = 23;
// 		//     }
// 		//     //refresh the screen
// 		//     matrix.fillRect(0, 14, 31, 31, matrix.Color333(0, 0, 0));
					
// 		//     //prints the hour screen
// 		//     printSetHour(hourCounter);
				
// 		//   }
// 		//   else {  //no button is pressed
// 		//     //do-nothing
// 		//   }
// 		//   break;

// 		// case ClockSM_SetMinutes:
// 		//   //checks whether next button is pressed
// 		//   if (setupButton.getState() == 0 && nextButton.getState() == 1 
// 		//                                   && prevButton.getState() == 0) {
// 		//     minuteCounter++;  //increments the minute counter

// 		//      //checks for the boundaries of the minutes, else set it to zero.
// 		//     if (minuteCounter < 0 || minuteCounter > 59) {
// 		//       minuteCounter = 0;  //resets minute counter to zero
// 		//     }
// 		//     //refreshes the screen
// 		//     matrix.fillRect(0, 12, 31, 31, matrix.Color333(0, 0, 0));

// 		//     //prints the setup screen
// 		//     printSetMinutes(minuteCounter);
// 		//   }
// 		//   else if (setupButton.getState() == 0 && nextButton.getState() == 0 
// 		//                                        && prevButton.getState() == 1){
// 		//     minuteCounter--;  //increments the counter

// 		//     //checks for the boundaries of the minutes, else its set to 59
// 		//     if (minuteCounter < 0 || minuteCounter > 59) {
// 		//       minuteCounter = 59;  //resets minute counter to the end
// 		//     }
// 		//     //refreshes the screen
// 		//     matrix.fillRect(0, 12, 31, 31, matrix.Color333(0, 0, 0));
					
// 		//     //prints the setup screen
// 		//     printSetMinutes(minuteCounter);
// 		//   }
// 		//   else {  //no button is pressed
// 		//     //do-nothing
// 		//   }
// 		//   break;

// 		default:
// 			break;
// 	}
// 	//end of state actions

// 	model->SetClockState(state);
// }