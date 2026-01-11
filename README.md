# Fract-ol

*This project has been created as part of the 42 curriculum by hamzarochd.*

## Description

**Fract-ol** is a graphical fractal explorer built in C using the MiniLibX graphics library. This project allows you to visualize and interact with beautiful mathematical fractals in real-time.

The project implements several famous fractals including:
- **Mandelbrot Set** - One of the most famous fractals, characterized by its intricate boundary and self-similar patterns
- **Julia Set** - A family of fractals related to the Mandelbrot set, with customizable parameters
- **Burning Ship** - A fractal that resembles a burning ship when rendered
- **Phoenix** - Another complex fractal pattern

### Features

- 🎨 **Multiple Color Palettes** - Switch between 11 different color schemes using the spacebar
- 🔍 **Zoom Functionality** - Use mouse scroll or keyboard to zoom in/out on fractal details
- 🎯 **Mouse-based Navigation** - Click and scroll to zoom into specific areas
- ⌨️ **Keyboard Controls** - Navigate using arrow keys and adjust settings on the fly
- 🖼️ **Real-time Rendering** - Smooth interaction with fractal visualization
- 🎛️ **Julia Set Parameters** - Custom real and imaginary parts for Julia set variations

The project demonstrates:
- Complex number mathematics and iteration
- Color interpolation and gradient generation
- Event handling and user interaction
- Pixel manipulation and graphics rendering
- Mathematical visualization techniques

## Instructions

### Prerequisites

- **macOS** (the project uses macOS-specific frameworks:  OpenGL and AppKit)
- **MiniLibX** library
- **GCC** or **Clang** compiler

### Compilation

To compile the project, simply run: 

```bash
make
```

This will create an executable named `fractol`.

To clean object files: 
```bash
make clean
```

To remove all compiled files:
```bash
make fclean
```

To recompile everything:
```bash
make re
```

### Execution

The program accepts different command-line arguments depending on the fractal you want to visualize:

#### For Mandelbrot Set:
```bash
./fractol mandelbrot
```

#### For Burning Ship:
```bash
./fractol burning_ship
```

#### For Phoenix:
```bash
./fractol phoenix
```

#### For Julia Set (requires two parameters):
```bash
./fractol julia <real_part> <imaginary_part>
```

Example: 
```bash
./fractol julia -0.4 0.6
./fractol julia 0.285 0.01
./fractol julia -0.70176 -0.3842
```

### Controls

Once the program is running, use these controls:

#### Keyboard Controls:
- **ESC** - Exit the program
- **I** - Zoom in
- **O** - Zoom out
- **Arrow Keys** - Move the view (up, down, left, right)
- **Spacebar** - Change color palette

#### Mouse Controls:
- **Scroll Up** - Zoom in at mouse cursor position
- **Scroll Down** - Zoom out at mouse cursor position

### Color Palettes

The program includes 11 different color palettes that you can cycle through by pressing the spacebar.  Each palette provides a unique visual representation of the fractal's escape-time algorithm, highlighting different aspects of the mathematical structure.

### Technical Details

- **Window Size**: 800x800 pixels (configurable in fractol.h)
- **Default Iterations**: 18 (affects detail level)
- **Escape Value**: 4 (mathematical constant for fractal calculations)
- **Rendering**: Uses MiniLibX for graphics, with custom pixel manipulation

## Project Structure

```
fract-ol/
├── fractol.c                  # Main program and initialization
├── fractol.h                  # Header file with structures and prototypes
├── parsing.c                  # Command-line argument parsing
├── pixel_handlers.c           # Fractal calculation and pixel rendering
├── events_utils.c             # Event handlers (keyboard, mouse)
├── color_utils.c              # Color palette and interpolation
├── complex_maths_utils.c      # Complex number mathematics
├── maths_utils.c              # General mathematical utilities
├── string_utils.c             # String manipulation functions
└── Makefile                   # Compilation rules
```

## Learning Outcomes

This project helps develop understanding of:
- Complex number arithmetic and mathematical iteration
- Graphics programming and pixel manipulation
- Event-driven programming
- Optimization techniques for real-time rendering
- Mathematical visualization
- Color theory and interpolation algorithms

## Resources

To learn more about fractals and the mathematics behind them:
- [Mandelbrot Set - Wikipedia](https://en.wikipedia.org/wiki/Mandelbrot_set)
- [Julia Set - Wikipedia](https://en.wikipedia.org/wiki/Julia_set)
- [Burning Ship Fractal - Wikipedia](https://en.wikipedia.org/wiki/Burning_Ship_fractal)
- [Complex Numbers - Khan Academy](https://www.khanacademy.org/math/algebra2/x2ec2f6f830c9fb89: complex)

---

*Enjoy exploring the infinite beauty of fractals!  🌀✨*
