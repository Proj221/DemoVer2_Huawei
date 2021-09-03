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

