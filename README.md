# fdf
### Basic height-map rendering engine

It converts given heigth map into image.
//image
Available projections `iso` `iso 2:1` `top view` `side view`
Use nubmers `1` `2` `3` `4` to change the projection type
//gif

## There are few cool features
To move the map hold `left cntrl` , then pick and move the top left corner of the map with `rbm` 
//gif

To zoom in/out hold `left cntrl` and use the `mouse wheel`
//gif

To increase relative altitude hold `left cmnd` and use the `mouse wheel`
//gif

## How to use
First of all, you need to install mlx(mini lib x), and it's only compatible with MacOS(10.12 and later)
Run the program with a filename of the file that specifies a map, as a first argument.
`./fdf maps/pyramide.fdf`
Optionaly you can specify two colors for the linear gradient, by passing them as a second argument in rgb format
`./fdf maps/pyraide.fdf 255000255~001225099`
The second argument consists of two colors specified by RBG value of red then blue and green, each varying from 0 up to 255 `RRRGGGBBB`, and the `~` between them.
