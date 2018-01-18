# Fdf

Fdf is a program that helps you draw 3D maps.

The projection is orthogonal, which is to say line do not converge with distance.

The size of the window adapts to the size of the map passed as an argument. If the map is too big for the screen (the size is set as an Imac screen) the grid is shrinking to let the drawing fit the screen.

Extremely big maps can take a long time to draw, that is why the program tells you every time it has processed 10% more of the data. This lets you know the program has not frozen, but is actually only taking time.

The maps passed to the program as arguments must be strictly rectangular (This is a bug I will to fix in the future).
