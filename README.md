# fdf
### Basic height-map rendering engine

Converts a given heigth map to image.  
![fdf_42](../assets/image/fdf_42.png) 

Available projections `iso` `iso 2:1` `top view` `side view`  

Use numbers `1` `2` `3` `4` to change the projection type  
![projections](../assets/image/projections.gif)

## Few cool features
To move map hold `left cntrl` , then pick and move the top left corner of the map with `right mouse button` 
![move](../assets/image/move.gif)  
To zoom in/out hold `left cntrl` and use the `mouse wheel`  
![zoom](../assets/image/zoom.gif)  
To increase relative altitude hold `left cmnd` and use the `mouse wheel`  
![altitude](../assets/image/altitude.gif)  
To reverse the altitude press `R`  
![reverse_altitude](../assets/image/reverse_altitude.gif)  
Hold `H` to view the help menu  
![help_bar](../assets/image/help_bar.gif)  

## How to use
Install the `mlx` (mini lib x), which is only compatible with MacOS 10.12 and later version

Run the program with file that specifies map, as a first argument
`./fdf maps/pyramide.fdf`  

Optionally, you can specify two colors for the linear gradient, by passing them as a second argument in rgb format  
`./fdf maps/pyraide.fdf 255000255~001225099`. The second argument consists of two colors specified by RBG value of red then blue and green, each varying from `0` up to `255` (just like `RRRGGGBBB`) with`~` in-between
