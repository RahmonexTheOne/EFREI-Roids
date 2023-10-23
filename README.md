# EFREI-Roids
2D Game where you need to stay with the ship in space as long as possible , but don't get hit by asteroids or you will crash your ship !
+ Asteroids explosion doesn't take in parameter xSpeed and ySpeed but takes the speend and an angle and calculates itself the xSpeed and ySpeed
+ Invincibilty last 3 seconds
+ Added a parameter SDL_Texture to asteroid and draw asteroid to make changes in the asteroids so that all of them doesn't look the same
+ Added a getRender in the framework
+ Added a main menu(3 buttons with play that redirects to the game)
+ Added an animated background for the main menu-> create a similar function to get texture but for gif files (downloaded SDL_Image.h)
### TO-Dos
+ NbAsteroids varies with the level
+ Level written in a text for example : Lvl1 5,10,2 where we can define size of asteroids number of asteroids and their speed as parameters separated with commas
+ Add a bar in top of the lvl playing where we show the shield level , the invincibilty time remaining and the time spent in the level
+ Add a main menu with a possibilty to play levels or to play an endless wave and try to stay as long as you can 
+ Add sounds ?