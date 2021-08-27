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
