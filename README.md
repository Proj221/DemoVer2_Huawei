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





