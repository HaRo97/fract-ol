
#include "fractol.h"

double scale(double num, double new_min, double new_max, double old_min, double old_max)
{
    return (new_max - new_min) * (num - old_min) / (old_max - old_min) + new_min;
}

void    my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
    int offset;

    offset = (y * img->line_lenght) + (x * (img->bits_per_pixel / 8));
    *(unsigned int *)(img->addr + offset) = color;
}

void    mandelbrot_julia_switch(t_complex_num *z, t_complex_num *c, t_fractal *fractal)
{
    if(ft_strncmp(fractal->name, "julia", 5) == 0)
    {
        c->real = fractal->julia_x;
        c->imaginary = fractal->julia_y;
    }
    else
    {
        c->real = z->real;
        c->imaginary = z->imaginary;
    }
}

void burningship_fractal(t_complex_num *z, t_fractal *fractal, int *color, int *x, int *y)
{
    int i;

    i = 0;
    while (i < fractal->iterations)
    {
        if (z->real < 0)
            z->real = -z->real;
        if(z->imaginary < 0)
            z->imaginary = -z->imaginary;  
        if ((z->real * z->real) + (z->imaginary * z->imaginary) > fractal->escape_value)
        {
            *color = interpolate(fractal->palette.start, fractal->palette.end, 40, (int)scale(i, 0, 39, 0, fractal->iterations));
            my_mlx_pixel_put(&fractal->img, *x, *y, *color);
        }
        i++;
    }
    
}

void phoenix_fractal(t_complex_num *z, t_fractal *fractal, int *color, int *x, int *y)
{
    int i;
    t_complex_num tmp; 
    t_complex_num tmp2;

    tmp.real = 0;
    tmp.imaginary = 0;
    tmp2.real = 0;
    tmp2.imaginary = 0;
    i = 0;
    while (i < fractal->iterations)
    {
        tmp2 = *z;
        *z = complex_minus_complex(complex_num_square(*z),complex_mp_num(tmp, 0.5));
        z->real = z->real + 0.56667;
        tmp = tmp2;
        tmp2 = *z;
        if ((z->real * z->real) + (z->imaginary * z->imaginary) > fractal->escape_value)
        {
            *color = interpolate(fractal->palette.start, fractal->palette.end, 40, (int)scale(i, 0, 39, 0, fractal->iterations));
            my_mlx_pixel_put(&fractal->img, *x, *y, *color);
        }
        i++;
    }

}

void handle_pixel_mandelbrot(int x, int y, t_fractal *fractal)
{
    t_complex_num   z;
    t_complex_num   c;
    int             i;
    int             color;
    t_complex_num   tmp; 
    t_complex_num   tmp2;

    z.real = (scale(x, -2, 1, 0, WIDTH) * fractal->zoom) + fractal->shift_x;
    z.imaginary = (scale(y, -1.5, 1.5, 0, HEIGHT) * fractal->zoom) + fractal->shift_y;

    mandelbrot_julia_switch(&z, &c, fractal);
    
    tmp.real = 0;
    tmp.imaginary = 0;
    tmp2.real = 0;
    tmp2.imaginary = 0;
    i = 0;
    while (i < fractal->iterations)
    {
        // if(ft_strncmp(fractal->name, "burning_ship", 12) == 0)
        // {
        //     if (z.real < 0)
        //         z.real = -z.real;
        //     if(z.imaginary < 0)
        //         z.imaginary = -z.imaginary;  
        // }
        // if(ft_strncmp(fractal->name, "phoenix", 7) == 0)
        // {
        //     tmp2 = z;
        //     z = complex_minus_complex(complex_num_square(z),complex_mp_num(tmp, 0.5));
        //     z.real = z.real + 0.56667;
        //     tmp = tmp2;
        //     tmp2 = z;
        // }
        // else
            z = complex_num_sum(complex_num_square(z), c);
        if ((z.real * z.real) + (z.imaginary * z.imaginary) > fractal->escape_value)
        {
            color = interpolate(fractal->palette.start, fractal->palette.end, 40, (int)scale(i, 0, 39, 0, fractal->iterations));
            my_mlx_pixel_put(&fractal->img, x, y, color);
        }
        i++;
    }
    my_mlx_pixel_put(&fractal->img, x, y, fractal->palette.complementary);
}

void    fractal_render(t_fractal *fractal)
{
    int x;
    int y;

    y = -1;
    while(++y < HEIGHT)
    {
        x = -1;
        while (++x < WIDTH)
        {
            // if(ft_strncmp(fractal->name, "mandelbrot", 10) == 0)
            //     handle_pixel_mandelbrot(x, y, fractal);
            // else if(ft_strncmp(fractal->name, "julia", 5) == 0)
            //     handle_pixel_mandelbrot(x, y, fractal);
            // else if(ft_strncmp(fractal->name, "burning_ship", 12) == 0)
            //     burningship_fractal(&z, fractal, &color, &x, &y);
            // else if(ft_strncmp(fractal->name, "phoenix", 7) == 0)
            //     phoenix_fractal(&z, fractal, &color, &x, &y);
            handle_pixel(x, y, fractal);
        }
        
    }
    mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window, fractal->img.img, 0, 0);
}


static void event_init(t_fractal *fractal)
{
    mlx_hook(fractal->mlx_window, ON_KEYDOWN, 0, keydown_handler, fractal);
    mlx_hook(fractal->mlx_window, ON_MOUSEDOWN, 0, mousedown_handler, fractal);
    mlx_hook(fractal->mlx_window, ON_DESTROY, 0, destroy_handler, fractal);
}

static void malloc_failed(void)
{
    perror("malloc failed");
    exit(EXIT_FAILURE);
}


void    fractal_init(t_fractal  *fractal)
{
    if (!fractal )
        return ;
    fractal->mlx_connection = mlx_init();
    if (fractal->mlx_connection == NULL)
        malloc_failed();
    fractal->mlx_window = mlx_new_window(fractal->mlx_connection, WIDTH, HEIGHT, fractal->name);
    if (fractal->mlx_window == NULL)
    {
        free(fractal->mlx_connection);
        malloc_failed();
    }
    fractal->img.img = mlx_new_image(fractal->mlx_connection, WIDTH, HEIGHT);
    if (fractal->img.img == NULL)
    {
        mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
        free(fractal->mlx_connection);
        malloc_failed();
    }
    fractal->img.addr = mlx_get_data_addr(fractal->img.img, &(fractal->img.bits_per_pixel), &(fractal->img.line_lenght), &(fractal->img.endian));
}

int main (int argc, char **argv)
{
    t_fractal   fractal;
    int parsingSuccess;

    fractal.escape_value = 4;
    fractal.iterations = 18;
    fractal.shift_x = 0.0;
    fractal.shift_y = 0.0;
    fractal.zoom = 1.0;
    fractal.range = 3.0;
    fractal.palette_index = 0;
    set_palette(0xffd900, 0x191971, 0xffd900, &fractal);
    parsingSuccess = parsing(argc, argv, &fractal);
    if (parsingSuccess == 0)
        return (EXIT_FAILURE);
    else
        {
            fractal_init(&fractal);
            fractal_render(&fractal);
            event_init(&fractal);
            mlx_loop(&fractal.mlx_connection);
        }
    
}


