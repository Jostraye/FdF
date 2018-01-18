# Fdf

Fdf is a program that helps you draw 3D maps from a text file containing height for each point.

The projection is orthogonal, which is to say line do not converge with distance.

The size of the window adapts to the size of the map passed as an argument. If the map is too big for the screen (the size is set as an Imac screen) the grid is shrinking to let the drawing fit the screen.

Extremely big maps can take a long time to draw, that is why the program tells you every time it has processed 10% more of the data. This lets you know the program has not frozen, but is actually only taking time.

The maps passed to the program as arguments must be strictly rectangular (This is a bug I will to fix in the future).



***
Fdf is a school project.
It was the opportunity for me to discover coding graphics, more specifically with the MinilibX library.

The goal of the project is to create an executable file that takes a text file filled with numbers, and create a visual interpretation of a 3D map from it.


This is the type of input file you can pass as an argument

![](https://scontent-sjc3-1.xx.fbcdn.net/v/t1.0-9/26804515_10157066727709676_80041474437850480_n.jpg?oh=60089778abaa4a2dfb79d6ea7aa291a6&oe=5AE671E9)


This is the output for that same file. The map is small, which makes the pixels appear bigger here.

![](https://scontent-sjc3-1.xx.fbcdn.net/v/t1.0-9/26992688_10157066727699676_4463895965669277599_n.jpg?oh=c2c4fd42a0bbc154c3dbc4ae1973e10d&oe=5AF97277)

The programs can process bigger maps like this one, drawn from a mars surface map

![](https://scontent-sjc3-1.xx.fbcdn.net/v/t31.0-8/26758318_10157066727869676_7101718593165733676_o.jpg?oh=ab461b9a89dbd6703e86a0d0ee55aac0&oe=5ADD8109) 


Gigantic maps take some time to process, this is the kind of message you can get

![](https://scontent-sjc3-1.xx.fbcdn.net/v/t1.0-9/26733477_10157066727704676_929145998151638677_n.jpg?oh=97f41a50d122d2e5057426292f01d6bc&oe=5AF1F736)


This is the sort of gigantic map that may take a while to process, but the result is interesting! Here is one of the Julia fractal sets, you can see that the center points are extremely high, and give this impression of peaks.

![](https://scontent-sjc3-1.xx.fbcdn.net/v/t31.0-8/26756566_10157066727874676_6085651106857364718_o.jpg?oh=1eadfa2af1db414d9e5898cce480145b&oe=5AE8A148)
