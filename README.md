# Fract-ol
This program takes as it's input the kind of fractol the user wishes to see, either julia or mandelbrot set
and renders it in a window. The program uses an external library called mini libx for mac to render images,
pixels, or strings on the window. Julia sets could be drawn using the starting points the user passes as arguments.


 <img width="876" alt="julia_3" src="https://user-images.githubusercontent.com/35448350/220626126-63d57638-63ad-4472-b6c7-ec1e48394a3e.png">


When the image is rendered mouse could zoom, clicking on the window would draw a different julia set starting from the
point that was clicked on. The makefile makes everything. 


<img width="895" alt="mandelbrot_zoom" src="https://user-images.githubusercontent.com/35448350/220627254-903cd737-7158-40fe-9ad6-d18ac26fddd4.png">


# Usage
First, go to the root of your repository, which is where we can find your Makefile git clone and do:

-make

To see julia set give random values, here's an example:

-./fractol julia -0.65 -0.45

 Please not that the external mini libx library is for mac and so it won't work on windows or linux.

# Refrancces
To do this project I used many resources to learn about fractals and inspirations for the algorithem, links for which could be found below:

-https://youtu.be/FFftmWSzgmk

-https://www.geogebra.org/m/mfewjrek

-https://github.com/42Paris/minilibx-linux

-http://warp.povusers.org/Mandelbrot/
