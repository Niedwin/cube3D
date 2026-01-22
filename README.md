_This project has been created as part of the 42 curriculum by kguillem, guviure._
---

# Cube3D

### Description

> This project is a 3D maze visualizer, reminescent of games such as **Wolfenstein 3D**.
> The executable needs a single **.cub** file as argument, containing visual information (floor and ceiling colors, as well as wall textures for each cardinal direction) in any order, and at the end the representation of the maze from a top down view.
> Upon sucessful launch, a window will open, allowing the player to explore the maze as a first person perspective from within.

### Feature list

> *Controls* :
> > The window and executable can be properly closed if the **escape key** is pressed, or manually closed by clicking on the **X button** in the corner of the window.
> > The player can be moved with the **WASD keys**.
> > The player can look left and right with the respectives **arrow keys**.
> *Error handling* :
> > Executing the program without a **.cub** file as argument or multiple arguments will output an error text.
> > If the file do not meet the requirements, various error messages may display depending on the error type, they will either end the execution on the spot or continue parsing for additionnal error collection if possible.

### Instructions

> Use the **make** command within the root of the repository to generate the executable named **cub3D**.
> Still in the same folder, execute the command **./cub3d** followed by a space and the path to a single valid **.cub** file as argument.
> The requirements of the **.cub** file  are first :
> > Paths to the textures for the walls linked to their cardinal directions
> >
> And last the map contents, wich must be composed of only 1 player orientation character (either N, S, E or W), any number of floor tiles characters (0) which must be contained by wall characters (1) to prevent the player going out of bounds and

### Resources

> [Lode's Raycasting tutorial](https://lodev.org/cgtutor/raycasting.html)

### Submission details

> Along with the code needed to build the executable, the project is shipped with various pre-built **.cub** files, sorted into working or non-working folders to enable faster testing.
