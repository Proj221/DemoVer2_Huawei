# DemoVer2_Huawei
This is the second demo to the Proj221. In this demo, it is more related to the card system.
The project will last for around one and a half month until the October of Year 2021. The project will be a preparation for the project later.

## Ep1_Delete all the unnecessary instances in level
+ delete the walls and the floor
+ delete character
+ delete other unnecessary instances

## Ep2_Build a new classroom
+ add several bsp and convert to SM so that the unit wall can be used
+ build a classroom

## Ep3_Modify the classroom
+ add some doors
+ add some glasses
+ add a trigger volume at door

## Ep4_Add animation to door1 and door2
+ add reference in lecel bp
+ use the trigger box bp to set the overlap anim on doors

## Ep5_Cutomize a event to handle door rotation
+ add some functions to refactor the bp
+ add a new custom event to exec the door rotation
+ the door workflow is: 1.detect overlap, 2.check if player, 3.assign correct door, 4.exec the door rotation

## Ep6_Set Class on and off
+ add a new custom event in game mode to receive notification from trigger box on class on off information
+ add a func in TB_ClassOn to set the class on off status
+ when the player is overlapping with the trigger box, the class will change from on to off, or vice versa
+ rename the TriggerBox to TB

## Ep7_Fix the door animation issue

## Ep8_Ray casting to set wall to glass
+ if the camera boom is interacting with any walls, then make the wall to transparent

## Ep9_Create a PDA and a DA
+ PDA for primary data asset where the base info is stored in the PDA
+ DA for data asset where the detailed (specific) info will be stored

## Ep10_Add new widget when class is on
+ create mainHUD and widget
+ add widget when the class is on
+ create new mainPlayerController

## Ep11_To solve the extra click after the card appear and disappear
+ https://www.youtube.com/watch?v=RvDHS5KOn58
+ https://community.gamedev.tv/t/attempting-to-focus-non-focusable-widget-sobjectwidget/116586/3
+ add some bp nodes at card appear and disappear area

## Ep12_Set Card background color
+ add bp code in widget construct to set the card bg color according to DA

## Ep13_Set question session
+ add question session now and max in game state
+ in game mode, set question session increment function to record the session
+ in card sys, call question session after click (release) the card, and to further check if the session reaches the max
+ in door open, check if the question session matches the max session. If not, then do not open the door
+ in game mode, delay some time between question sessions
+ set max session to 3 so that each time we enter into the classroom we need to choose for 3 times

## Ep14_Migrate some props from SciFi Office Proj
+ A monitor
+ A paper
+ Fix the reference relationship between the starter content and the asset

## Ep15_Add a new logic in question session increment func
+ add a new the pre-requiste to appear the Card Chossing UI: the class on has to be true (to avoid when class is off but the UI appears)

## Ep16_Set input methods and create actors
+ in bp_main widget to set a button for calling a monitor around the player
+ and a new func in func lib to get transform offset around the actor (to spawn the actor more easily around the player)
+ modify codes in CPP to comment out the direct mouse axis control
+ // PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
+ // PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
+ in bp add input axis turn and left alt to set as a key input combine for controlling camera rotation
+ same action to input axis lookup
+ in func lib to add a new func called get main widget to capture the main widget easily

## Ep17_Set left alt key to toggle the mouse cursor usage
+ in thirdPersonChara, to set left alt key as the toggle switch to enable the mouse cursor (game and ui) and only game
+ in thirdPersonChara, to set left alt key as the toggle switch to enable mouse movement as the input for character pitch and yaw

## Ep18_Create widgets to drag and drop (2D)
+ rename previous cardsys to cardsys_v1
+ create new cardsys called cardsys_v2, in v2, 2 scroll boxes are included (later it should be changed to one scroll box, and 3 bound slots)
+ create new cardsingle to store a single card template. introduce a new var and make it expose to spawn so that the value can be initiated in the widget constructor
+ set KEY:Z to call out the cardsys_v2
+ use KEY:Z also to disable cam pitch and yaw
+ set a root node to single card, (overlay) so that the size would not be affected in the scrollbox (should further check if grid array is supported in scroll box)
+ reference to: https://blog.csdn.net/ali013719291765/article/details/102425497
+ bug: if dragging out of the box, then OnDrop func will not be triggered, then the card would disappear

## Ep19_Bug fix for Ep18
+ Modify a bit in CardSys_v2 to add child properly according to the screen position

## Ep20_Restructure the bag and the slot
+ seperate the whole Card sys UI to Overall, Bag and Slot1/2/3
+ use slot 1, 2 and 3 to store the card, use mask to recycle the card

## Ep21_Refactor the input mode
+ use left Alt to toggle camera (TBD)
+ use Z to toggle card sys (this is the 2D Main UI)

## Ep22_Modify BP_CardSys
+ modify GetTransOffsetAroundActor to set the widget appear when pressed left alt
+ input changed to: DistFromActor, DistOffset, CombineRotation, ScaleValue
+ DistFromActor, float, this defines the distance from the character pivot point, along with the camera forward vector
+ DistOffset, vector, the distance offset based on DistFromActor
+ CombineRotation, rotator, not used yet
+ ScaleValue: the scale to the original widget

## Ep23_Add 1st and 3rd camera angle
+ left alt and button to switch between 1st and 3rd angle
+ card sys UI will appear after switch to 1st person angle
+ Bug: switch back to 3rd person chara, UI would still appear

## Ep24_bug fix for switching back with new UI
+ when switching back from 1st to 3rd, destroy the UI panel
+ to be solved: make the timeline a var and set this var in game state instead of chara

## Ep25_3D widget is too difficult to tune
+ if 3D widget will reuse again, please set the branch from here!!!

## Ep26_Fix the issue of card invisibility when the card is dragged out of the viewport
+ add a OnDragCancelled event in the card single and once the event is called, set the card visibility to true

## Ep27_Change card holder to scroll box + wrap box
+ under scroll box, a wrap box is added to avoid any grid construction

## Ep28_Fix child not able to add back to card bag bug
+ in card bag, first check if the bag has already got the child, if not, then add the child

## Ep29_Add textures to the picture, and add card show window
+ in the card single, add mouse action detection on mouse enter and mouse leave, to trigger the show window show and hide
+ in the card single, add a new func on defining the card texture (NOTE that the random func is always failed on matching the card single in bag and card info in card show. need further investigation why the random func is not a good choice here)
+ in the card show, add 2 new custom event on show and hide the card information. Note that the show card info will consume the card idx as the input
+ in the card info, add a new func on defining the card texture based on the idx
+ in the card bag, note that the input to create widget type is changed from name to integer. Accordingly, in the display session where the card num is displayed, the var needs to be transferred from int to name
+ import sanguosha cards
+ change the position of the slot and the show box

## Ep30_If we change cardDisp from "World" to "Screen", then the UI would become following along with the camera (always)

## Ep31_Add 4 trigger boxes and a new level
+ 4 trigger boxes would trigger math class, chinese class, english class and common class seperately
+ one new level would be reused for 4 classrooms
+ the design target is changed to demoVer2 PRD now!

## Ep32_Move all vars from gameState to game Instance
+ use mainGameInstance to store all the variables used to store in gameState
+ seprate the mainScene with the classroomScene more differently
+ add some texture render on walls to identify the classroom name
+ set transparent effect not only to the wallset but also to classroomConstruct

## Ep33_Add new loading level
+ add a new var in gameInstance to set which level should be loaded after the loading bar finished
+ add a new loading level, consisted of a background image and a progress bar
+ add the logic to check the progress by the tick delta time, when the delta time is accumulating and exceeds 1.0, the system would load for the next level

## Ep34_Change Door logic and set keyHint in chara
+ change door open logic in classroom scene. bind the door Static Mesh to the collision box
+ set the logic to the text render (child to follow camera) so that once the actor approaches the teacher desk, the text render would appear (to hint player for class ON authorization)

## Ep35_Add new logic to trigger user event
+ user would use E key to interact with the world
+ a single event trigger conditions include: 1.event is ready, 2.user is pressing the key, 3.the new event gate is true
+ add a debug btn in card sys to jump out of an event
+ bug: when jumping in an event, the mouse would able to use to drag the chara yaw and pitch. To solve the issue, the pitch yaw movement should be sealed in a seperate custom event.

## Ep36_Bug fix for Ep35
+ add a new function especially for toggle UI mode in person chara

## Ep37_Set camera transition in chara for class ON and OFF
+ in game mode, the class on is seperated to ToggleUIMode, SwingCamera, MembersReady and ShowCardSys
+ in player chara, add a new func called transitCamPos to coordinate the camera position for class ON and OFF (or potentially other features in future)

## Ep38_Set the camera change when press Q key
+ set a new pawn called cam pawn for manage camera view in classroom
+ when pressing Q key, the controller would abandon to master the thirdpersoncharacter and to swing to the other camera

## Ep39_Set the character controlled by AIC while the player is controlling the camera pawn
+ in thirdPersonCharacter, integrate possess and unpossess the proper camera
+ create a new AIController, for controlling the character while the player is on Camera (need to be modulized in future)
+ tester: add a new behavior tree and play animation with JUMP, in AIC to run the BT for testing if the AIC is truly controlling the character and to check if the player is able to override the AIC

## Ep40_Set the character controlled by AI_PlayerController and fix the lerp issue
+ always remember: the lerp should start from the START value, and end at the END value, not start from the DELTA value (or intermidiate value)
+ set a new AIPlayerController for controlling the player character while the player is actually holding the class on camera
+ set a new blackboard and a new behavior tree especially for controlling the class on BB and BT

## Ep41_Set the character responding according to the "ANNOUNCE"
+ add 2 buttons on card sys to toggle class annouce begin and end
+ add BT logic to respond according to the annouce instruction
+ add flag in the AI player controller for controlling if the player (and other NPCs) is ready to class (where the character is at their own classroom desk)

## Ep42_Bug remained
+ card drag and drop system is not able to use now

## Ep43_Bug fixed
+ NOTE: always use NOT HIT-TESTABLE (SELF ONLY) on the card system widget, rather than visible, to avoid the CANNOT drag drop issue

## Ep44_Add announce trigger logic
+ in the game mode, add new custom event on checking if the teacher should announce class is ON
+ the preconditions on checking if should announce are: 1.studentRegistrationList length is equal to studentReadyList, 2.StudentRegistrationList length is not 0, 3.HasAnnounced is false
+ StudentRegistrationList will be effective when the Player press E key to engage Class On event, and will be cleared when the Class Off event is triggered
+ StudentReadyList will be effective when the Player BT triggers the task on setting ClassReady to true, and will be cleared when the Class Off event is triggered
+ HasAnnounced will be triggered once the announce event is triggered, and will be reset when the Class Off event is triggered

## Ep45_Add conversation system
+ preliminary conversation system includes a structure to store the conversation text, which role it should show and left/right side it should show at
+ add a new UI window to show conversation, includes the text area and 2 role image areas
+ add the conversation session in between of the normal game mode and the card sys show mode
+ the click flow now is: press E key to start class, click anywhere you want on the screen to proceed the conversation session until the conversation session is end, then the card system will appear, after choosing the card to use, click the button (development btn) on top left to end the class session

