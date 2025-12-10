
//COMMON LIBRARIES//
#include <stdio.h>
#include <fcntl.h>

//OTHER LIBRARIES//
#include "LIBFT_H"

//STRUCTS//
struct	header
{
char ceiling[3];//saves each 0 to 255 color value as chars to save memory
char floor[3];//might be NULL terminated or undoable because ascii limits
char *north_texture;
char *south_texture;
char *east_texture;
char *west_texture;
}

//PROTOTYPES//

